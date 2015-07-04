//
// PizzaException.cpp for cpp_plazza in /home/gouy_e/rendu/cpp_plazza/source
// 
// Made by Gouy Elliot
// Login   <gouy_e@epitech.net>
// 
// Started on  Tue Apr 28 14:45:41 2015 Gouy Elliot
// Last update Tue Apr 28 14:47:46 2015 Gouy Elliot
//

#include "PizzaException.hh"

PizzaException::PizzaException(const char *m) : _msg(m)
{}

PizzaException::~PizzaException() throw()
{}

const char	*PizzaException::what() const throw()
{
  return (_msg.c_str());
}
