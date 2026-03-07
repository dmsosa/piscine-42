/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:42:00 by apuchill          #+#    #+#             */
/*   Updated: 2020/10/30 19:55:46 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//receives "Hallo welt" and returns 2 because {"Hallo", "Welt", \0}
int	ft_count_words(char *str)
{
	int i;
	int count;

	i = 0;
	while (*str)
	{
		while (ft_isspace(*str) && *str)
			str++;
		if (!ft_isspace(*str) && *str)
		{
		    i++;
		    while(!ft_isspace(*str) && *str)
		        str++;
		}
	}
	return (i);
}