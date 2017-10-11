/*
** myftp.h for ftp in /home/meridj/Rendus/PSU_2016_myftp/incs/
**
** Made by Mehdi Meridja
** Login   <mehdi.meridja@epitech.eu>
**
** Started on  Sun May 21 20:12:41 2017 Mehdi Meridja
** Last update Fri May 26 12:53:49 2017 Mehdi Meridja
*/

#ifndef _MY_FTP_H_
# define _MY_FTP_H_

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>

typedef struct		s_ftp
{
  long			port_entry;
  char			*path_entry;
  char			temporaire_chemin[4096];
  long			socket;
  long			its_ok;
  long			bind_ftp;
  struct sockaddr_in	in_sockaddr;
  char			*tempo;
  long			utilisateur_good;
  long			psswd_good;
  char			utilisateur[4096];
  char      ptr_first[4096];
  char			**ptr;
  char			path_current[4096];
  unsigned long		size_path;
  socklen_t		size;
}			t_ftp;

char	**my_str_to_wordtab(char *str, int i, int j, int deb);
long	multiple_verif(t_ftp *data);
long	send_error(long value);
void	lancement_ftp(t_ftp *data);
long	my_check_fail(char *error);
void	make_cmd(t_ftp *data);
void	one_more_verif(t_ftp *data);
void	on_boucle_fork(t_ftp *data, int sleep);
long	on_go_le_forking(t_ftp *data);
long	yes_aff_my_writing(int file, char *ptr, char *pass);
long	my_user_required_help(t_ftp *data);
long	aff_my_current_directory(t_ftp *data);
long	mauvaise_entree_utilisateur(t_ftp *data);
long	my_change_repertoire(t_ftp *data, int value);
long	my_terminate_ftp(t_ftp *data);
void	rm_file(t_ftp *data);
long	rien_a_faire(t_ftp *data);
long	set_utilisateur(t_ftp *data);
long	utilisateur_password(t_ftp *data);

#endif /* !_MY_FTP_*/
