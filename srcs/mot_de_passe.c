/*
** mot_de_passe.c for ftp in /home/meridj/Rendus/PSU_2016_myftp/srcs/
**
** Made by Mehdi Meridja
** Login   <mehdi.meridja@epitech.eu>
**
** Started on  Sun May 21 20:08:07 2017 Mehdi Meridja
** Last update Fri May 26 13:04:51 2017 Mehdi Meridja
*/

#include "myftp.h"

int	func_value(t_ftp *data, int value)
{
  if (value == 1)
    {
      yes_aff_my_writing(data->its_ok,
			 "Vous etes toujours connecté",
			 "230");
    }
  else if (value == 2)
    {
      yes_aff_my_writing(data->its_ok,
			 "Mot de passe ou utilisateur incorrect",
			 "530");
       return (-1);
    }
  return (0);
}

long	utilisateur_password(t_ftp *data)
{
  data->ptr = my_str_to_wordtab(data->ptr_first, 0, 0, 0);
  if (data->psswd_good == 1)
    {
      func_value(data, 1);
      return (0);
    }
  if (data->utilisateur_good != 1)
  {
    func_value(data, 2);
    return (0);
  }
  if (data->ptr[1] == NULL)
    {
      data->psswd_good = 1;
      yes_aff_my_writing(data->its_ok,
			 "Connexion réussis",
			 "230");
    }
    else
    {
      func_value(data, 2);
      return (0);
    }
  return (0);
}
