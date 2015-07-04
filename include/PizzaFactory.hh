//
// PizzaFactory.hh for cpp_plazza in /home/gouy_e/rendu/cpp_plazza/include
// 
// Made by Gouy Elliot
// Login   <gouy_e@epitech.net>
// 
// Started on  Mon Apr 27 19:30:34 2015 Gouy Elliot
// Last update Mon Apr 27 19:40:13 2015 Gouy Elliot
//

#ifndef PIZZAFACTORY_HH_
# define PIZZAFACTORY_HH_

# include <vector>

# include "Pizza.hh"

class			PizzaFactory
{
private:
  std::vector<Pizza *>	_pizza;
public:
  PizzaFactory();
  ~PizzaFactory();

  void			setNewPizza(const Pizza &);
  Pizza			*createPizza(const std::string &) const;
};

#endif /* !PIZZAFACTORY_HH_ */
