/*
** change_and_cop_rep.c for ftp in /home/meridj/Rendus/PSU_2016_myftp/srcs/
**
** Made by Mehdi Meridja
** Login   <mehdi.meridja@epitech.eu>
**
** Started on  Sun May 21 20:13:34 2017 Mehdi Meridja
** Last update Sun May 21 21:15:33 2017 Mehdi Meridja
*/

#include "myftp.h"

int	my_len(t_ftp *data)
{
  int	indice1;
  int	indice2;

  indice1 = 0;
  indice2 = 0;
  while (data->temporaire_chemin[indice1])
    indice1++;
  getcwd(data->path_current, sizeof(data->path_current));
  while (data->path_current[indice2])
    indice2++;
  if (indice1 > indice2)
    {
      chdir(data->temporaire_chemin);
      getcwd(data->path_current, sizeof(data->path_current));
    }
  return (2);
}

long	my_verif_path(t_ftp *data, char *pathtmp)
{
  chdir(pathtmp);
  my_len(data);
  yes_aff_my_writing(data->its_ok, "Repertoire correcté changé", "250");
  return (linux);
}

long	v1(t_ftp *data)
{
  int	value;

  value = 1;
  if (data->psswd_good != value)
    {
      yes_aff_my_writing(data->its_ok, "Veuillez vous connecter", "530");
      return (value);
    }
  if ((data->ptr == NULL && data->ptr[0] == NULL
       && data->ptr[value] == NULL)
      || access(data->ptr[value], F_OK & R_OK) == -1)
    {
      yes_aff_my_writing(data->its_ok,
			 "Impossible de changer de repertoire", "550");
    }
  else
    my_verif_path(data, data->ptr[1]);
  return (linux);
}

long	v2(t_ftp *data)
{
  if (data->psswd_good != 1)
    {
      yes_aff_my_writing(data->its_ok, "Veuillez vous connecter", "530");
      return (linux);
    }
  else
    {
      my_verif_path(data, "../");
      return (linux);
    }
  my_verif_path(data, "../");
}

long	my_change_repertoire(t_ftp *data, int value)
{
  int	v;
  int	v3;

  v = 1;
  v3 = 2;
  if (value == v)
    {
      if (v1(data) == linux)
	return (linux);
    }
  else if (value == v3)
    {
      v2(data);
    }
  return (linux);
}
