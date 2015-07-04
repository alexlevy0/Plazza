//
// Cook.cpp for cpp_plazza in /home/gouy_e/rendu/cpp_plazza/source
// 
// Made by Gouy Elliot
// Login   <gouy_e@epitech.net>
// 
// Started on  Sun Apr 26 13:47:20 2015 Gouy Elliot
// Last update Tue Apr 28 12:57:39 2015 Gouy Elliot
//

#include "Cook.hh"
#include <iostream>

Cook::Cook(float mul, KitchenMemory *m) : _multiplier(mul), _memory(m), _isFinish(false)
{}

Cook::~Cook()
{}

void			Cook::cook()
{
  Pizza			*tmp;

  while (!_isFinish)
    {
      pthread_mutex_lock(&(_memory->mutex));
      pthread_cond_wait(&(_memory->cond), &(_memory->mutex));
      if (!_isFinish)
	{
	  tmp = _memory->pizza.front();
      	  _memory->pizza.pop_front();

	  if (tmp)
	    {
	      while (!_memory->stock->checkIngredients(*tmp))
		sleep(1);
	      std::cout << *tmp << std::endl;
	      delete tmp;
	    }
	}
      pthread_mutex_unlock(&(_memory->mutex));
    }
  pthread_exit(NULL);
}

void			Cook::setIsFinish(bool i)
{
  _isFinish = i;
}
