//
// PizzaFactory.cpp for cpp_plazza in /home/gouy_e/rendu/cpp_plazza/source
// 
// Made by Gouy Elliot
// Login   <gouy_e@epitech.net>
// 
// Started on  Mon Apr 27 19:34:14 2015 Gouy Elliot
// Last update Tue Apr 28 13:59:57 2015 Gouy Elliot
//

#include "PizzaFactory.hh"

PizzaFactory::PizzaFactory()
{
  Pizza         pizza;

  pizza.setName("Margarita");
  pizza.setTime(1);
  pizza.setIng(0, true);
  pizza.setIng(1, true);
  pizza.setIng(2, true);
  setNewPizza(pizza);

  pizza.setName("Regina");
  pizza.setTime(2);
  pizza.setIng(3, true);
  pizza.setIng(4, true);
  setNewPizza(pizza);

  pizza.setName("Americana");
  pizza.setTime(2);
  pizza.setIng(3, false);
  pizza.setIng(4, false);
  pizza.setIng(5, true);
  setNewPizza(pizza);

  pizza.setName("Fantasia");
  pizza.setTime(4);
  pizza.setIng(2, false);
  pizza.setIng(5, false);
  pizza.setIng(6, true);
  pizza.setIng(7, true);
  pizza.setIng(8, true);
  setNewPizza(pizza);
}

PizzaFactory::~PizzaFactory()
{
  while (_pizza.size())
    {
      delete _pizza.back();
      _pizza.pop_back();
    }
}

void			PizzaFactory::setNewPizza(const Pizza &p)
{
  Pizza			*new_p;

  new_p = new Pizza();
  *new_p = p;
  _pizza.push_back(new_p);
}

Pizza			*PizzaFactory::createPizza(const std::string &n) const
{
  unsigned int		i;
  Pizza			*ret;

  i = -1;
  while (++i < _pizza.size())
    {
      if (_pizza[i]->isSameName(n))
	{
	  ret = new Pizza();
	  *ret = *(_pizza[i]);
	  return (ret);
	}
    }
  return (NULL);
}
