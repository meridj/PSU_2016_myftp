/*
** mauvaise_entre.c for ftp in /home/meridj/Rendus/PSU_2016_myftp/srcs/
**
** Made by Mehdi Meridja
** Login   <mehdi.meridja@epitech.eu>
**
** Started on  Sun May 21 20:14:10 2017 Mehdi Meridja
** Last update Tue May 23 17:05:41 2017 Mehdi Meridja
*/

#include "myftp.h"

void	aff_output(t_ftp *data)
{
  yes_aff_my_writing(data->its_ok, "Veuillez vous connecter.", "530");
  return ;
}

void	my_mauvaise_entry(t_ftp *data, int value)
{
  if (value == 1)
    {
      aff_output(data);
    }
  else if (value == 2)
    {
      yes_aff_my_writing(data->its_ok,
			 "Vous avez entré une mauvaise commande -> ",
			 "404");
    }
  return ;
}

long	mauvaise_entree_utilisateur(t_ftp *data)
{
  int	v;
  int	v1;

  v = 1;
  v1 = 2;
  if (data->psswd_good != v)
    {
      my_mauvaise_entry(data, v);
    }
  else
    {
      my_mauvaise_entry(data, v1);
    }
  return (v1);
}
