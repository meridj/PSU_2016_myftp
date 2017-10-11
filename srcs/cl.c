/*
** cl.c for ftp in /home/meridj/Rendus/PSU_2016_myftp/srcs/
**
** Made by Mehdi Meridja
** Login   <mehdi.meridja@epitech.eu>
**
** Started on  Sun May 21 21:10:13 2017 Mehdi Meridja
** Last update Sun May 21 21:15:58 2017 Mehdi Meridja
*/

#include "myftp.h"

long	on_go_le_forking(t_ftp *data)
{
  int	sleep;
  pid_t	client;

  sleep = 10;
  if ((client = fork()) != 0)
    {
      if (close(data->its_ok) == -1)
        return (-1);
    }
  else
    {
      one_more_verif(data);
      on_boucle_fork(data, sleep);
    }
  return (0);
}
