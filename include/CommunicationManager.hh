//
// CommunicationManager.hh for cpp_plazza in /home/gouy_e/rendu/cpp_plazza/include
// 
// Made by Gouy Elliot
// Login   <gouy_e@epitech.net>
// 
// Started on  Sun Apr 26 12:09:06 2015 Gouy Elliot
// Last update Tue Apr 28 14:56:54 2015 Gouy Elliot
//

#ifndef COMMUNICATIONMANAGER_HH_
# define COMMUNICATIONMANAGER_HH_

# include <cstdio>
# include <string>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <poll.h>

class			CommunicationManager
{
private:
  std::string		_name;
  int			    _fdOut;
  int			    _fdIn;
  struct pollfd		_fd;
public:
  CommunicationManager(const std::string &);
  virtual ~CommunicationManager();

  CommunicationManager	&operator>>(std::string &);
  CommunicationManager	&operator<<(const std::string &);
};

#endif /* !COMMUNICATIONMANAGER_HH_ */
