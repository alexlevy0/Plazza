//
// Kitchen.hh for cpp_plazza in /home/gouy_e/rendu/cpp_plazza/include
// 
// Made by Gouy Elliot
// Login   <gouy_e@epitech.net>
// 
// Started on  Sun Apr 26 10:45:22 2015 Gouy Elliot
// Last update Tue Apr 28 12:29:25 2015 Gouy Elliot
//

#ifndef KITCHEN_HH_
# define KITCHEN_HH_

# include <vector>
# include <pthread.h>
# include <unistd.h>

# include "Stock.hh"
# include "CommunicationManager.hh"
# include "Cook.hh"

class				Kitchen : public Stock, public CommunicationManager
{
private:
  float				_multiplier;
  int				_cookNbr;
  pthread_t			*_threads;
  std::vector<Cook *>		_cooks;
  KitchenMemory			_memory;

  void				exitAllCook();
public:
  Kitchen(float, int, float, const std::string &);
  ~Kitchen();

  bool			launch();
};

#endif /* !KITCHEN_HH_ */
