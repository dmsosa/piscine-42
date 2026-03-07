/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:06:30 by durisosa          #+#    #+#             */
/*   Updated: 2020/10/28 17:55:06 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//For test
#include <stdio.h>
#include "libft.h"

int ft_valid_base(char *base)
{
    int i;
    int j;

    i = 0;
    j = 0;
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

int		ft_atoi_base_pow(char *str, char *base)
{
	int sign;
	int result;
    int i;
    int magnitude;
    int base_len;

    i = 0;
    magnitude = 0;
    result = 0;
	sign = 1;
    base_len = ft_valid_base(base);
	while ((*str >= 9 && *str <= 13) || *str == 32
            || *str == '+' || *str == '-')
    {
        if (*str == '-')
            sign *= -1;
        ++str;
    }
    if (base_len > 0)
        result = result_recursive(result, str[0], 0, base, base_len, magnitude) * sign;
    else
        return (0);
}
int		result_recursive(int *result, char c, int position, char *base, int base_len, int magnitude)
{
    int i;

    i = 0;
    if (!ft_find_index(c, base))
        *result = 0;
	if (position == magnitude)
        return ft_find_index(c, base);
    else
        return (
            result_recursive(c, base, position + 1, base_len, magnitude, magnitude - position + 1) + 
            (ft_find_index(c, base) * ft_pow(base, magnitude - position))
        );
}



//Command line INPUTS
//gcc cafeConversion.c && ./a.out "10" "01"


int		main(int argc, char **argv)
{
	char	*base;
	char	*nbr;
	int		result;

	//Basically i have to find the value of nbr
	//in this example -> 42
	nbr = argv[1];  //"101010"
	base = argv[2]; //"01"

					//nbr & base a are strings!
	result = ft_atoi_base(nbr, base);
    printf("The real value of \"%s\" in base \"%s\" is -> %d\n", nbr, base, result);
}
