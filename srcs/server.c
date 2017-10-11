/*
** server.c for ftp in /home/meridj/Rendus/PSU_2016_myftp/srcs/
**
** Made by Mehdi Meridja
** Login   <mehdi.meridja@epitech.eu>
**
** Started on  Sun May 21 20:15:02 2017 Mehdi Meridja
** Last update Sun May 21 21:31:00 2017 Mehdi Meridja
*/

#include "myftp.h"

int	my_strlen(char *str)
{
  int	indice;

  indice = 0;
  while (str[indice] != 0)
    indice++;
  return (indice);
}

void	my_putstrror(char *str)
{
  write(2, str, my_strlen(str));
}

long	my_check_fail(char *error)
{
  my_putstrror(error);
  my_putstrror("\n");
  exit(0);
  return (0);
}

long	verification_directory(t_ftp *data)
{
  chdir(data->path_entry);
  getcwd(data->temporaire_chemin,
	 sizeof(data->temporaire_chemin));
  data->size_path = my_strlen(data->temporaire_chemin);
  return (0);
}

int	main(int ac, char **av)
{
  t_ftp	data;
  DIR	*directory;

  if (ac == 3)
    {
      data.path_entry = av[2];
      data.port_entry = atoi(av[1]);
      if (!(data.port_entry >= 0 && data.port_entry < 65537))
	{
	  send_error(1);
	}
      if ((directory = opendir(data.path_entry)) != NULL)
	verification_directory(&data);
      else
	send_error(2);
      lancement_ftp(&data);
      return (EXIT_SUCCESS);
    }
  my_check_fail("Usage: ./server [port] && [path]");
  return (EXIT_FAILURE);
}
