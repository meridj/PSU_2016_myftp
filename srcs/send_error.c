/*
** send_error.c for ftp in /home/meridj/Rendus/PSU_2016_myftp/srcs/
**
** Made by Mehdi Meridja
** Login   <mehdi.meridja@epitech.eu>
**
** Started on  Sun May 21 20:14:58 2017 Mehdi Meridja
** Last update Sun May 21 21:29:29 2017 Mehdi Meridja
*/

#include "myftp.h"

long	send_error(long value)
{
  if (value == 1)
    {
      my_check_fail("error: Bad entry port");
      return (value);
    }
  if (value == 2)
    {
      my_check_fail("error: Bad entry path");
      return (value);
    }
  return (value);
}
