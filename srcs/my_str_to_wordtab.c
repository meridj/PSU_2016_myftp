/*
** my_str_to_wordtab.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:35:30 2016 Mehdi Meridja
** Last update Sun May 21 21:27:23 2017 Mehdi Meridja
*/

#include <myftp.h>

char    **x_malloc_tab_c(int size)
{
  char  **dl_ptr;

  if ((dl_ptr = malloc(size)) == NULL)
    {
      return (NULL);
    }
  return (dl_ptr);
}

static int	cpt_words(char *str)
{
  int		i;
  int		cpt;

  i = 0;
  cpt = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
          || (str[i] >= '0' && str[i] <= '9')
          || str[i] == '-' || str[i] == '_' || str[i] == '.' || str[i] == '/')
	{
	  cpt++;
	  while (str[i] && ((str[i] >= 'a' && str[i] <= 'z')
			    || (str[i] >= 'A' && str[i] <= 'Z')
			    || (str[i] >= '0' && str[i] <= '9')
			    || str[i] == '-' || str[i] == '_' || str[i] == '.'
			    || str[i] == '/'))
	    i++;
	}
      if (str[i] != 0)
	i++;
    }
  return (cpt);
}

char	**my_str_to_wordtab(char *str, int i, int j, int deb)
{
  char	**tab;

  tab = x_malloc_tab_c(sizeof(char *) * (cpt_words(str) + 1));
  while (str[i] != 0)
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A'
					       && str[i] <= 'Z')
          || (str[i] >= '0' && str[i] <= '9')
          || str[i] == '-' || str[i] == '_' || str[i] == '.'
	  || str[i] == '/')
	{
	  deb = i;
	  while (str[i] && ((str[i] >= 'a' && str[i] <= 'z')
			    || (str[i] >= 'A' && str[i] <= 'Z')
			    || (str[i] >= '0' && str[i] <= '9')
			    || str[i] == '-' || str[i] == '_' || str[i] == '.'
			    || str[i] == '/'))
	    i++;
	  tab[j++] = strndup(&str[deb], i - deb);
	}
      else
	i++;
    }
  tab[j] = NULL;
  return (tab);
}
