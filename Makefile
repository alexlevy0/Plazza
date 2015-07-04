##
## Makefile for plazza in /home/gouy_e/rendu/cpp_plazza
## 
## Made by Gouy Elliot
## Login   <gouy_e@epitech.net>
## 
## Started on  Tue Apr 21 16:24:23 2015 Gouy Elliot
## Last update Tue Apr 28 14:48:18 2015 Gouy Elliot
##

NAME		= plazza

SRC		= source/main.cpp \
		  source/CommunicationManager.cpp \
		  source/Reception.cpp \
		  source/Kitchen.cpp \
		  source/Cook.cpp \
		  source/Stock.cpp \
		  source/PizzaException.cpp \
		  source/Pizza.cpp \
		  source/PizzaFactory.cpp \

OBJ		= $(SRC:.cpp=.o)

CPP		= g++

CPPFLAGS	= -Wall -Wextra -Werror -g3 -I include/ -I include/Pizza -std=c++11

RM		= rm -f

LDFLAGS		= -lpthread

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

