/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:14:51 by durisosa          #+#    #+#             */
/*   Updated: 2022/11/15 18:24:06 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *src)
{
	int i;

    i = 0;
	while (src[i])
		i++;
	return (i);
}

// int main(void)
// {

// 	printf("%s", ft_strdup("hello"));
// 	return (0);
// }