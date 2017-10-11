/*
** aff_directory.c for ftp in /home/meridj/Rendus/PSU_2016_myftp/srcs/
**
** Made by Mehdi Meridja
** Login   <mehdi.meridja@epitech.eu>
**
** Started on  Sun May 21 20:13:15 2017 Mehdi Meridja
** Last update Sun May 21 21:13:13 2017 Mehdi Meridja
*/

#include "myftp.h"

void	aff(t_ftp *data)
{
  yes_aff_my_writing(data->its_ok, "257: ", NULL);
  yes_aff_my_writing(data->its_ok, data->path_current, NULL);
  yes_aff_my_writing(data->its_ok, "\r\n", NULL);
}

void	my_aff_put(t_ftp *data, int value)
{
  if (value == 1)
    {
      aff(data);
    }
  else if (value == 2)
    {
      yes_aff_my_writing(data->its_ok,
			 "Veuillez vous connecter", "530");
    }
}

long	aff_my_current_directory(t_ftp *data)
{
  int	value;
  int	value1;

  value = 1;
  value1 = 2;
  if (data->psswd_good == value)
    {
      my_aff_put(data, value);
      return (value1);
    }
  else if (data->psswd_good != value)
    {
      my_aff_put(data, value1);
    }
  return (value1);
}
