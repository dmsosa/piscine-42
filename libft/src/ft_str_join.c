/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:42:00 by apuchill          #+#    #+#             */
/*   Updated: 2020/10/30 19:55:46 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int ft_strlen(char *src)
{
	int i;

    i = 0;
	while (src[i])
		i++;
	return (i);
}

//receives "Hallo welt" and returns {"Hallo", "Welt", NULL}
char **ft_str_to_tab(int ac, char *str)
{
	int	i;
	int	j;
	int	k;
	char **tab;

	tab = malloc(sizeof(char*) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
	    printf("hello '%d'", i);
	    while (ft_isspace(*str) && *str)
	        str++;
		if (*str)
		{
			k = 0;
			while (!ft_isspace(str[k]) && str[k])
				k++;
			tab[i] = malloc(sizeof(char) * (k + 1));
			j = 0;
			while (!ft_isspace(*str) && *str)
			{
				tab[i][j++] = *str++;
			}
			tab[i][j] = '\0';
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
