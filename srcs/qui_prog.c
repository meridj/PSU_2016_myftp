/*
** qui_prog.c for ftp in /home/meridj/Rendus/PSU_2016_myftp/srcs/
**
** Made by Mehdi Meridja
** Login   <mehdi.meridja@epitech.eu>
**
** Started on  Sun May 21 20:14:50 2017 Mehdi Meridja
** Last update Sun May 21 21:29:06 2017 Mehdi Meridja
*/

#include "myftp.h"

void	my_exit(t_ftp *data)
{
  if (close(data->its_ok) == -1)
    {
      exit(0);
    }
  exit(0);
}

long	my_aff(t_ftp *data)
{
  int	my_value;

  my_value = 0;
  yes_aff_my_writing(data->its_ok, "__QUIT MY_FTP__", "221");
  return (my_value);
}

long	my_terminate_ftp(t_ftp *data)
{
  my_aff(data);
  shutdown(data->its_ok, SHUT_RDWR);
  my_exit(data);
  return (42);
}
