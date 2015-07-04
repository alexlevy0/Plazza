//
// Pizza.hh for cpp_plazza in /home/gouy_e/rendu/cpp_plazza/include
// 
// Made by Gouy Elliot
// Login   <gouy_e@epitech.net>
// 
// Started on  Mon Apr 27 15:33:18 2015 Gouy Elliot
// Last update Tue Apr 28 14:48:03 2015 Gouy Elliot
//

#ifndef PIZZA_HH_
# define PIZZA_HH_

# include <string>
# include <iostream>

# include "PizzaException.hh"

# define ING_NBR	9

class			Pizza
{
private:
  std::string		_name;
  int			    _time;
  bool			    _ingredients[ING_NBR];
public:
  Pizza();
  Pizza(const std::string &, const bool *, int);
  ~Pizza();

  const std::string &	getName() const;
  int			        getTime() const;
  const bool		    *getIng() const;
  
  void			setName(const std::string &);
  void			setTime(int);
  void			setIng(int, bool);
  bool			isSameName(const std::string &) const;
  Pizza			&operator=(const Pizza &);
  Pizza			&operator>>(std::string &);
};

Pizza			    &operator<<(Pizza &, const std::string &);
std::ostream&		operator<<(std::ostream &, const Pizza &);

#endif /* !PIZZA_HH_ */
