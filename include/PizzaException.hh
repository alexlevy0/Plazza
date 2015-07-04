//
// PizzaException.hh for cpp_plazza in /home/gouy_e/rendu/cpp_plazza/include
// 
// Made by Gouy Elliot
// Login   <gouy_e@epitech.net>
// 
// Started on  Tue Apr 28 14:42:38 2015 Gouy Elliot
// Last update Tue Apr 28 14:45:21 2015 Gouy Elliot
//

#ifndef PIZZAEXCEPTION_HH_
# define PIZZAEXCEPTION_HH_

# include <exception>
# include <string>

class			PizzaException : public std::exception
{
private:
  std::string		_msg;
public:
  PizzaException(const char *);
  ~PizzaException() throw();

  const char		*what() const throw();
};

#endif /* !PIZZAEXCEPTION_HH_ */
