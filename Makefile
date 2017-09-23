##
## Makefile for Makefile in /home/lejeun_b/Tools
## 
## Made by stephane lejeune
## Login   <lejeun_b@epitech.net>
## 
## Started on  Wed Dec 17 15:58:15 2014 stephane lejeune
## Last update Sat Dec 17 15:34:27 2016 Thomas Jamais
##

COMP	=	g++

RM	=	rm -rf

OBJ     =	$(SRC:.cpp=.o)

CPPFLAGS	+=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -std=c++11 -g3
CPPFLAGS	+= 	-I./Headers
#CPPFLAGS	+=	-Wall -Wextra -Werror

NAME	=	Gomoku

SRC	=	Sources/GomoMain.cpp \
		Sources/Starter.cpp \
		Sources/Gomoku.cpp \
		Sources/Goban.cpp \
		Sources/GomokuIA.cpp \
		Sources/Rules.cpp \
		Sources/WinGame.cpp \
		Sources/AI.cpp \
		Sources/Ruler.cpp

AOK	=	echo -e "\\033[32mDone\\033[0m"
AKO	=	echo -e "\\033[31mFailed\\033[0m"
BOK	=	echo -e "\\033[32mDeleting OK\\033[0m"
BKO	=	echo -e "\\033[31mDeleting Failed\\033[0m"
COK	=	echo -e "\\033[32mDeleting OK\\033[0m"
CKO	=	echo -e "\\033[31mDeleting Failed\\033[0m"


all:		$(NAME)

$(NAME): 	$(OBJ)
		@$(COMP) -o $(NAME) $(OBJ) $(CPPFLAGS) && $(AOK) || $(AKO)

clean:
		@$(RM) $(OBJ) && $(BOK) || $(BKO)

fclean: 	clean
		@$(RM) $(NAME) && $(COK) || $(CKO)

re:		fclean all

run:		re
		./Gomoku

.PHONY:		all clean fclean re
