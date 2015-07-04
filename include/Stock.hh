//
// Stock.hh for cpp_plazza in /home/gouy_e/rendu/cpp_plazza/include
// 
// Made by Gouy Elliot
// Login   <gouy_e@epitech.net>
// 
// Started on  Sun Apr 26 10:52:08 2015 Gouy Elliot
// Last update Tue Apr 28 14:57:05 2015 Gouy Elliot
//

#ifndef STOCK_HH_
# define STOCK_HH_

# include <ctime>
# include <pthread.h>

# include "Pizza.hh"

class			Stock
{
private:
  float			_time;
  int			_ingredients[ING_NBR];
  time_t		_clock;
  pthread_mutex_t	_sMutex;
public:
  Stock(float);
  virtual ~Stock();

  bool			regenIngredients();
  bool			checkIngredients(const Pizza &);
};

#endif /* !STOCK_HH_ */
