##
## Makefile for ftp in /home/meridj/Rendus/PSU_2016_myftp
## 
## Made by Mehdi Meridja
## Login   <mehdi.meridja@epitech.net>
## 
## Started on  Sun May 21 21:10:34 2017 Mehdi Meridja
## Last update Sun May 21 21:11:14 2017 Mehdi Meridja
##

CC	= gcc

RM	= rm -f

NAME	= server

CFLAGS	+= -W -Wall -Wextra -Werror -g \
	   -I./incs/

SRC	= $(addprefix srcs/, \
	  mot_de_passe.c \
	  server.c \
	  lancement.c \
	  my_del_noop.c \
	  send_error.c \
	  mauvaise_entre.c \
	  aff_writing.c \
	  change_and_cop_rep.c \
	  qui_prog.c \
	  my_noop_func.c \
	  my_utilisateur.c \
	  aff_directory.c \
	  help_my_user.c \
	  my_str_to_wordtab.c \
	  cl.c \
	  myftp.c)

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
