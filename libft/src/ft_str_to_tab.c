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
	int	support_tab_len;
	char **tab;

	tab = malloc(sizeof(char*) * (ac + 1));
	if (tab == NULL);
		return (NULL);
	i = 0;
	while (*str)
	{
		//Ist dieses ein Wort?
		if (!ft_isspace(*str) && *str)
		{
			support_tab_len = 0;
			//Wort lange finden
			while (!ft_isspace(str[support_tab_len]) && str[support_tab_len])
				support_tab_len++;
			tab[i] = malloc(sizeof(char) * (support_tab_len + 1));
			j = 0;
			while (!ft_isspace(*str) && *str)
			{
				tab[i][j] = *str;
				str++;
				j++;
			}
			tab[i][j] = '\0';
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}