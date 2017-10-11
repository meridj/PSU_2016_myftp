/*
** my_noop_func.c for ftp in /home/meridj/Rendus/PSU_2016_myftp/srcs/
**
** Made by Mehdi Meridja
** Login   <mehdi.meridja@epitech.eu>
**
** Started on  Sun May 21 20:14:23 2017 Mehdi Meridja
** Last update Sun May 21 21:24:54 2017 Mehdi Meridja
*/

#include "myftp.h"

long	version_1(t_ftp *data)
{
  if (data->psswd_good != 1)
    {
      yes_aff_my_writing(data->its_ok, "Veuillez vous connecter", "530");
      return (1);
    }
  return (0);
}

long	version_2(t_ftp *data)
{
  int	value;

  value = 1;
  if ((data->ptr == NULL && data->ptr[0] == NULL && data->ptr[value] == NULL)
      || access(data->ptr[value], F_OK & R_OK) == -1)
    {
      yes_aff_my_writing(data->its_ok, "Impossible de supprimer le fichier", "550");
      return (value);
    }
  return (0);
}

long	version_3(t_ftp *data)
{
  int	value;
  int	v_4;

  value = 1;
  v_4 = remove(data->ptr[value]);
  if (v_4 == 0)
    {
      yes_aff_my_writing(data->its_ok, "Fichier supprimé", "250");
      return (value);
    }
  return (0);
}

void	rm_file(t_ftp *data)
{
  int	value;

  value = 1;
  if (version_1(data) == value)
    return ;
  if (version_2(data) == value)
    return ;
  if (version_3(data) == value)
    return ;
  yes_aff_my_writing(data->its_ok, "Impossible de supprimer le fichier", "550");
}
