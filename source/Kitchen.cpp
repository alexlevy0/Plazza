//
// Kitchen.cpp for cpp_plazza in /home/gouy_e/rendu/cpp_plazza/source
// 
// Made by Gouy Elliot
// Login   <gouy_e@epitech.net>
// 
// Started on  Sun Apr 26 11:55:06 2015 Gouy Elliot
// Last update Tue Apr 28 14:55:21 2015 Gouy Elliot
//

#include "Kitchen.hh"

void			*launch_cooker(void *c)
{
  Cook			*tmp;

  tmp = static_cast<Cook *>(c);
  tmp->cook();
  return (NULL);
}

Kitchen::Kitchen(float multipler, int cookNbr, float ingTime, const std::string &name) : Stock(ingTime), CommunicationManager(name), _multiplier(multipler), _cookNbr(cookNbr), _threads(NULL)
{
  pthread_mutex_init(&(_memory.mutex), NULL);
  pthread_cond_init(&(_memory.cond), NULL);
  _memory.stock = this;
}

Kitchen::~Kitchen()
{}

void			Kitchen::exitAllCook()
{
  int			i;

  i = -1;
  while (++i < _cookNbr)
    _cooks[i]->setIsFinish(true);
  pthread_cond_broadcast(&(_memory.cond));
  i = -1;
  while (++i < _cookNbr)
    pthread_join(_threads[i], NULL);
}

bool			Kitchen::launch()
{
  int			i;
  time_t		t;
  std::string		tmp;
  Pizza			*p;

  i = -1;
  _threads = new pthread_t[_cookNbr];
  while (++i < _cookNbr)
    {
      _cooks.push_back(new Cook(_multiplier, &_memory));
      pthread_create(_threads + i, NULL, launch_cooker, _cooks[i]);
    }
  t = time(0);
  while (difftime(time(0), t) < 5.f)
    {
      tmp.clear();
      *this >> tmp;
      this->regenIngredients();
      if (tmp.length())
	{
	  std::cout << "Child Recieve pizza" << std::endl;
	  p = new Pizza();
	  try
	    {
	      *p << tmp;
	      _memory.pizza.push_back(p);
	      pthread_cond_signal(&(_memory.cond));
	      t = time(0);
	    }
	  catch (PizzaException &e)
	    {
	      *this << e.what();
	      delete p;
	    }
	}
    }
  exitAllCook();
  return (true);
}

