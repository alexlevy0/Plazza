//
// Reception.hh for cpp_plazza in /home/gouy_e/rendu/cpp_plazza/include
// 
// Made by Gouy Elliot
// Login   <gouy_e@epitech.net>
// 
// Started on  Sun Apr 26 15:20:43 2015 Gouy Elliot
// Last update Tue Apr 28 14:01:13 2015 Gouy Elliot
//

#ifndef RECEPTION_HH_
# define RECEPTION_HH_

# include <vector>
# include <string>
# include <iostream>

# include "PizzaFactory.hh"
# include "Kitchen.hh"

struct				KitchenHandle
{
  std::string			name;
  int				fdIn;
  int				fdOut;
};

class				Reception : public PizzaFactory
{
private:
  float				_multiplier;
  int				_nbrCook;
  int				_stockDelai;
  int				_kitchenNbr;
  std::vector<KitchenHandle *>	_kitchenList;
public:
  Reception(float, int, int);
  ~Reception();

  bool		openKitchen();
  void		getOrder();
};

#endif /* !RECEPTION_HH_ */

