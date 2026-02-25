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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:58:04 by Oceano            #+#    #+#             */
/*   Updated: 2022/12/13 10:06:09 by Oceano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

int ft_valid_base(char *base)
{
    while (base[i])
    {   
        if (ft_isspace(base[i]) || base[i] == '+' || base[i] == '-')
            return (-1);
        j = i + 1;
        while (base[j])
        {
            if (base[i] == base[j])
                return (-1);
            j++;
        }
        i++;
    }
    if (i < 2)
        return (-1);
    return (i);
}

int		ft_atoi(char *str)
{
	int sign;
	int result;

	sign = 1;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}	
	//Check all numbers and stock in accumulator number	
	while (*str >= 48 && *str <= 57)	
	{
		//This is a << shift_base10_like operation
		number *= 10;
		//Conversion from char to number
		number += *str - 48;
		++str;
	}
	return (number * sign);
}

int main(void)
{
	char str[] = "--+345";
	printf("My atoi: '%d'\n", ft_atoi(str));	
	printf("REAL atoi: '%d'\n", atoi(str));	
	return (0);
}
