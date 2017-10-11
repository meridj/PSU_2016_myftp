/*
** myftp.c for ftp in /home/meridj/Rendus/PSU_2016_myftp/srcs/
**
** Made by Mehdi Meridja
** Login   <mehdi.meridja@epitech.eu>
**
** Started on  Sun May 21 20:14:43 2017 Mehdi Meridja
** Last update Tue May 23 20:02:42 2017 Mehdi Meridja
*/

#include "myftp.h"

int	test(t_ftp *data)
{
  int	value;

  if (strcmp(data->ptr[0], "USER") == 0)
    set_utilisateur(data);
  else if (strcmp(data->ptr[0], "PASS") == 0)
    utilisateur_password(data);
  else if (strcmp(data->ptr[0], "CWD") == 0)
    my_change_repertoire(data, 1);
  else if (strcmp(data->ptr[0], "PWD") == 0)
    aff_my_current_directory(data);
  else if (strcmp(data->ptr[0], "QUIT") == 0)
    my_terminate_ftp(data);
  else if (strcmp(data->ptr[0], "DELE") == 0)
    rm_file(data);
  else if (strcmp(data->ptr[0], "NOOP") == 0)
    rien_a_faire(data);
  else if (strcmp(data->ptr[0], "HELP") == 0)
    my_user_required_help(data);
  else if (strcmp(data->ptr[0], "CDUP") == 0)
    my_change_repertoire(data, 2);
  else
    mauvaise_entree_utilisateur(data);
  value = 0;
  return (value);
}

void	commande_fabrication(t_ftp *data)
{
  if (strcmp(data->tempo, "\r\n") == 0)
    {
      return ;
    }
  data->ptr = my_str_to_wordtab(data->tempo, 0, 0, 0);
  if (data->ptr && data->ptr[0])
    {
      test(data);
    }
  return ;
}

void	one_more_verif(t_ftp *data)
{
  char	*str;
  char	*str2;

  str = strdup("Bienvenidos amigos !");
  str2 = strdup("220");
  yes_aff_my_writing(data->its_ok, str, str2);
  getcwd(data->path_current, sizeof(data->path_current));
  data->utilisateur_good = 0;
  data->psswd_good = 0;
  free(str);
  return ;
}

void	on_boucle_fork(t_ftp *data, int sleep)
{
  if (sleep != 10)
    {
      return ;
    }
  while (linux)
    {
      memset(data->ptr_first, '\0', sizeof(data->ptr_first));
      read(data->its_ok, &data->ptr_first, sizeof(data->ptr_first));
      data->tempo = strdup(data->ptr_first);
      commande_fabrication(data);
      usleep(sleep);
    }
  return ;
}

long	multiple_verif(t_ftp *data)
{
  int	i;

  i = 0;
  data->size = sizeof(data->in_sockaddr);
  data->in_sockaddr.sin_family = AF_INET;
  data->in_sockaddr.sin_port = htons(data->port_entry);
  data->in_sockaddr.sin_addr.s_addr = INADDR_ANY;
  data->bind_ftp = bind(data->socket,
			(const struct sockaddr *)&data->in_sockaddr,
			sizeof(struct sockaddr));
  if (data->bind_ftp == -1)
    {
      my_check_fail("error: Bad Create Bind");
    }
  return ((long)i);
}
