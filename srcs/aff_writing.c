/*
** aff_writing.c for ftp in /home/meridj/Rendus/PSU_2016_myftp/srcs/
**
** Made by Mehdi Meridja
** Login   <mehdi.meridja@epitech.eu>
**
** Started on  Sun May 21 20:13:28 2017 Mehdi Meridja
** Last update Sun May 21 21:13:43 2017 Mehdi Meridja
*/

#include "myftp.h"

long	my_puts(char *str, int fd)
{
  long	value;

  value = 2;
  write(fd, str, strlen(str));
  return (value);
}

long	yes_aff_my_writing(int file, char *ptr, char *pass)
{
  int	verif;
  int	indice;
  char	*my_ptr;
  int	file_descriptor;

  indice = 1;
  file_descriptor = file;
  verif = 0;
  my_ptr = ptr;
  if (pass != NULL)
    {
      my_puts(pass, file_descriptor);
      my_puts(" ", file_descriptor);
      verif = indice;
    }
  if (my_ptr != NULL)
    {
      my_puts(my_ptr, file_descriptor);
    }
  if (verif == indice)
    {
      my_puts("\r\n", file_descriptor);
    }
  return (verif);
}
