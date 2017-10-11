/*
** help_my_user.c for ftp in /home/meridj/Rendus/PSU_2016_myftp/srcs/
**
** Made by Mehdi Meridja
** Login   <mehdi.meridja@epitech.eu>
**
** Started on  Sun May 21 20:13:59 2017 Mehdi Meridja
** Last update Sun May 21 21:16:43 2017 Mehdi Meridja
*/

#include "myftp.h"

void	my_help_put(t_ftp *data, int value)
{
  if (value == 1)
    {
      yes_aff_my_writing(data->its_ok,
			 "214 Voici toute les commande connu\r\n \
      DELE PASS PWD USER HELP CWD CDUP QUIT NOOP\r\n", NULL);
    }
  else if (value == 2)
    {
      yes_aff_my_writing(data->its_ok,
			 "Veuillez vous connecter", "530");
    }
}

long	my_user_required_help(t_ftp *data)
{
  int	v;
  int	v2;

  v = 1;
  v2 = 2;
  if (data->psswd_good == v)
    {
      my_help_put(data, v);
    }
  else
    {
      my_help_put(data, v2);
      return (v);
    }
  return (v2);
}
