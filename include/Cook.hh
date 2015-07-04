//
// Cook.hh for cpp_plazza in /home/gouy_e/rendu/cpp_plazza/include
// 
// Made by Gouy Elliot
// Login   <gouy_e@epitech.net>
// 
// Started on  Sun Apr 26 10:49:45 2015 Gouy Elliot
// Last update Tue Apr 28 12:30:48 2015 Gouy Elliot
//

#ifndef COOK_HH_
# define COOK_HH_

# include <list>
# include <string>
# include <pthread.h>
# include <unistd.h>

# include "Stock.hh"

struct				KitchenMemory
{
  pthread_mutex_t		mutex;
  pthread_cond_t		cond;
  Stock				    *stock;
  std::list<Pizza *>	pizza;
};

class				Cook
{
private:
  float				    _multiplier;
  KitchenMemory			*_memory;
  bool				    _isFinish;
public:
  Cook(float, KitchenMemory *);
  ~Cook();

  void				cook();
  void				setIsFinish(bool);
};

#endif /* !COOK_HH_ */
