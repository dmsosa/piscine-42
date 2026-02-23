/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:06:30 by durisosa          #+#    #+#             */
/*   Updated: 2020/10/28 17:55:06 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_isspace(char c)
{
    int i;
    
    i = 0;
    if (c >= 9 && c <= 13 || c == 32)
        return (1);
	return (0);
}

int ft_atoi(char *str)
{
    int i;
	int nbr;
	int sign;
	
	sign = 1;
	i = 0;
	nbr = 0;
	if (str == NULL)
	    return (0);
	
	while (ft_isspace(*str) || str[i] == '-' || str[i] == '+')
    {
		if (*str == '-')
			sign *= -1;
		str++;
	}
	
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

int main(int argc, char **argv)
{
	printf("ey %d\n", ft_atoi(argv[1]));	
	return (0);
}
