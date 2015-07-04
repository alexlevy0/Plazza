//
// Reception.cpp for cpp_plazza in /home/gouy_e/rendu/cpp_plazza/source
// 
// Made by Gouy Elliot
// Login   <gouy_e@epitech.net>
// 
// Started on  Sun Apr 26 15:23:24 2015 Gouy Elliot
// Last update Tue Apr 28 14:11:18 2015 Gouy Elliot
//

#include "Reception.hh"

Reception::Reception(float m, int n, int s) : PizzaFactory(), _multiplier(m), _nbrCook(n), _stockDelai(s), _kitchenNbr(0)
{}

Reception::~Reception()
{}

bool		Reception::openKitchen()
{
  KitchenHandle	*mem;
  pid_t		pid;
  Kitchen	*kit;

  mem = new KitchenHandle();
  mem->name += "kitchen" + std::to_string(_kitchenNbr++);

  if (mkfifo((mem->name + ".out").c_str(), 0644))
    return (false);
  if (mkfifo((mem->name + ".in").c_str(), 0644))
    return (false);

  pid = fork();
  if (pid == 0)
    {
      mem->fdIn = open((mem->name + ".out").c_str(), O_RDONLY | O_NONBLOCK);
      mem->fdOut = open((mem->name + ".in").c_str(), O_WRONLY);
      _kitchenList.push_back(mem);
    }
  else if (pid == -1)
    return (false);
  else
    {
      std::cout << "Child Launch Kitchen" << std::endl;
      kit = new Kitchen(_multiplier, _nbrCook, _stockDelai, mem->name);
      kit->launch();
      delete kit;
      exit(0);
    }
  return (true);
}

void		Reception::getOrder()
{
  std::string	input;
  std::string	pizza;
  Pizza		    *tmp;

  std::cin >> input;
  tmp = createPizza(input);
  std::cout << *tmp << std::endl;
  if (tmp)
    {
      std::cout << "Open Kitchen" << std::endl;
      openKitchen();
      *tmp >> pizza;
      std::cout << "Send to Kitchen " << pizza << std::endl;
      write(_kitchenList.front()->fdOut, pizza.c_str(), pizza.length());
    }
}
