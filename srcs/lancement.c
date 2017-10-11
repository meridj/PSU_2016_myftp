/*
** lancement.c for ftp in /home/meridj/Rendus/PSU_2016_myftp/srcs/
**
** Made by Mehdi Meridja
** Login   <mehdi.meridja@epitech.eu>
**
** Started on  Sun May 21 20:14:05 2017 Mehdi Meridja
** Last update Tue May 23 19:46:25 2017 Mehdi Meridja
*/

#include "myftp.h"

void	lancement_ftp(t_ftp *data)
{
  int	list;
  int	verif;
  int	v_socket;

  list = 21;
  v_socket = 6;
  verif = -1;
  if ((data->socket = socket(AF_INET, SOCK_STREAM, v_socket)) != verif)
    {
      multiple_verif(data);
      listen(data->socket, list);
      while (linux)
	{
	  if ((data->its_ok
	       = accept(data->socket,
			(struct sockaddr *)&data->in_sockaddr, &data->size)) != verif)
	    {
	      on_go_le_forking(data);
	    }
      if (data->tempo)
        strcpy(data->tempo, "");
	  usleep(100);
	}
    }
  else
    my_check_fail("error: Bad Generate Socket");
  return ;
}
