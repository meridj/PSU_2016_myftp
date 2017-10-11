/*
** my_utilisateur.c for ftp in /home/meridj/Rendus/PSU_2016_myftp/srcs/
**
** Made by Mehdi Meridja
** Login   <mehdi.meridja@epitech.eu>
**
** Started on  Sun May 21 20:14:38 2017 Mehdi Meridja
** Last update Tue May 23 17:03:56 2017 Mehdi Meridja
*/

#include "myftp.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = -1;
  while (src[++i] != 0)
    dest[i] = src[i];
  dest[i] = 0;
  return (dest);
}

long	aff_test(t_ftp *data, int value)
{
  if (value == 1)
    {
      yes_aff_my_writing(data->its_ok, "Pas de nom d'utilisateur",
			 "550");
    }
  else if (value == 2)
  {
    yes_aff_my_writing(data->its_ok,
		       "Impossible de changer d'utilisateur",
		       "530");
  }
  else if (value == 3)
    {
      my_strcpy(data->utilisateur, data->ptr[1]);
      yes_aff_my_writing(data->its_ok,
			 "Entrez votre mot de passe", "331");
      if (strcmp(data->utilisateur, "Anonymous") == 0)
	{
	  data->utilisateur_good = 1;
	}
    }
  return (0);
}

long	set_utilisateur(t_ftp *data)
{
  int	value;

  value = 1;
  if (!(data->ptr && data->ptr[0] && data->ptr[1]))
    {
      value = 1;
      aff_test(data, value);
    }
  else if (data->utilisateur_good == 1 && data->psswd_good == 1)
    {
      value = 2;
      aff_test(data, value);
    }
  else
    {
      value = 3;
      aff_test(data, value);
    }
  return (value);
}
