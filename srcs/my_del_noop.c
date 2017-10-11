/*
** my_del_noop.c for ftp in /home/meridj/Rendus/PSU_2016_myftp/srcs/
**
** Made by Mehdi Meridja
** Login   <mehdi.meridja@epitech.eu>
**
** Started on  Sun May 21 20:14:19 2017 Mehdi Meridja
** Last update Sun May 21 21:22:15 2017 Mehdi Meridja
*/

#include "myftp.h"

int	on_test(t_ftp *data)
{
  if (data->psswd_good != 1)
    {
      yes_aff_my_writing(data->its_ok, "Veuillez vous connecter", "530");
      return (1);
    }
  return (2);
}

long	rien_a_faire(t_ftp *data)
{
  if (on_test(data) == 1)
    return (1);
  yes_aff_my_writing(data->its_ok, "Rien à faire", "200");
  return (2);
}
