//
// Pizza.cpp for cpp_plazza in /home/gouy_e/rendu/cpp_plazza/source
// 
// Made by Gouy Elliot
// Login   <gouy_e@epitech.net>
// 
// Started on  Mon Apr 27 15:56:14 2015 Gouy Elliot
// Last update Tue Apr 28 14:52:48 2015 Gouy Elliot
//

#include "Pizza.hh"

Pizza::Pizza() : _name(""), _time(0)
{
  int	i;

  i = -1;
  while (++i < ING_NBR)
    _ingredients[i] = false;
}

Pizza::Pizza(const std::string &n, const bool *b, int t) : _name(n), _time(t)
{
  int	i;

  i = -1;
  while (++i < ING_NBR)
    _ingredients[i] = b[i];
}

Pizza::~Pizza()
{}

bool			Pizza::isSameName(const std::string &toCmp) const
{
  return (toCmp == _name);
}

Pizza			&Pizza::operator=(const Pizza &p)
{
  int			i;

  _name = p._name;
  _time = p._time;
  i = -1;
  while (++i < ING_NBR)
    _ingredients[i] = p._ingredients[i];
  return (*this);
}

Pizza			&Pizza::operator>>(std::string &out)
{
  int			i;
  int			val;
  int			tmp;

  i = ING_NBR;
  val = 0;
  tmp = 256;
  while (--i >= 0)
    {
      if (_ingredients[i])
	val += tmp;
      tmp = tmp / 2;
    }
  out.append(_name);
  out.append(",");
  out.append(std::to_string(_time));
  out.append(",");
  out.append(std::to_string(val));
  return (*this);
}

const std::string &	Pizza::getName() const
{
  return (_name);
}

int			Pizza::getTime() const
{
  return (_time);
}

const bool		*Pizza::getIng() const
{
  return (_ingredients);
}

void			Pizza::setName(const std::string &n)
{
  _name = n;
}

void			Pizza::setTime(int t)
{
  _time = t;
}

void			Pizza::setIng(int idx, bool v)
{
  if (idx > 0 && idx < ING_NBR)
    _ingredients[idx] = v;
}

Pizza			&operator<<(Pizza &p, const std::string &in)
{
  int			ing;
  int			i;
  int			tmp;
  size_t		first;
  size_t		second;

  try
    {
      if ((first = in.find(",")) == std::string::npos ||
	  (second = in.rfind(",")) == std::string::npos)
	throw (PizzaException("Syntax Error"));
      p.setName(in.substr(0, first));
      p.setTime(std::stoi(in.substr(first + 1, second - first + 1)));
      ing = std::stoi(in.substr(second + 1, in.length()));
    }
  catch (std::exception &e)
    {
      throw (PizzaException(e.what()));
    }
  i = ING_NBR;
  tmp = 256;
  while (--i >= 0)
    {
      if (ing & tmp)
	p.setIng(i, true);
      else
	p.setIng(i, false);
      tmp = tmp / 2;
    }
  return (p);
}

std::ostream&		operator<<(std::ostream &out, const Pizza &p)
{
  std::cout << "Pizza: " << p.getName() << " done in " << p.getTime();
  return (out);
}
