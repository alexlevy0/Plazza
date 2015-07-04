//
// Stock.cpp for cpp_plazza in /home/gouy_e/rendu/cpp_plazza/source
// 
// Made by Gouy Elliot
// Login   <gouy_e@epitech.net>
// 
// Started on  Sun Apr 26 10:56:19 2015 Gouy Elliot
// Last update Tue Apr 28 12:51:53 2015 Gouy Elliot
//

#include "Stock.hh"

#include <iostream>

Stock::Stock(float t) : _time(t)
{
  int		i;
  
  i = -1;
  while (++i < ING_NBR)
    _ingredients[i] = 5;
  _clock = time(0);
  pthread_mutex_init(&_sMutex, NULL);
}

Stock::~Stock()
{}

bool		Stock::regenIngredients()
{
  time_t	t;
  int		i;

  if ((t = difftime(time(0), _clock) * 1000) >= _time)
    {
      i = -1;
      pthread_mutex_lock(&_sMutex);
      while (++i < ING_NBR)
	_ingredients[i] += (int)(t / _time);
      pthread_mutex_unlock(&_sMutex);
      _clock = time(0);
      return (true);
    }
  return (false);
}

bool		Stock::checkIngredients(const Pizza &p)
{
  const	bool	*tmp;
  int		i;

  i = -1;
  tmp = p.getIng();
  while (++i < ING_NBR)
    {
      if (tmp[i] && _ingredients[i] < 1)
	return (false);
    }
  i = -1;
  pthread_mutex_lock(&_sMutex);
  while (++i < ING_NBR)
    {
      if (tmp[i])
	_ingredients[i] -= 1;
    }
  pthread_mutex_unlock(&_sMutex);
  return (true);
}
