//
// CommunicationManager.cpp for cpp_plazza in /home/gouy_e/rendu/cpp_plazza/source
// 
// Made by Gouy Elliot
// Login   <gouy_e@epitech.net>
// 
// Started on  Sun Apr 26 12:16:22 2015 Gouy Elliot
// Last update Tue Apr 28 14:58:17 2015 Gouy Elliot
//

#include "CommunicationManager.hh"

CommunicationManager::CommunicationManager(const std::string &name) : _name(name)
{
  _fdOut = open((name + ".out").c_str(), O_WRONLY);
  _fdIn = open((name + ".in").c_str(), O_RDONLY);
  _fd.fd = _fdIn;
  _fd.events = POLLIN;
}

CommunicationManager::~CommunicationManager()
{
  close(_fdOut);
  close(_fdIn);
}

CommunicationManager	&CommunicationManager::operator>>(std::string &input)
{
  int			isReadable;
  char			tmp[512];
  int			i;

  isReadable = poll(&_fd, 1, 1000);
  if (isReadable > 0 && _fd.revents & POLLIN &&
      (i = read(_fdIn, tmp, 511)) > 0)
    {
      tmp[i] = 0;
      input.append(tmp);
    }
  return (*this);
}

CommunicationManager	&CommunicationManager::operator<<(const std::string &output)
{
  write(_fdOut, output.c_str(), output.length());
  return (*this);
}
