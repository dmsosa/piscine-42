/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:14:51 by durisosa          #+#    #+#             */
/*   Updated: 2022/11/15 18:24:06 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The first combination has all digits set to their minimum value, starting at 0 for the leftmost digit.
For four digits:
0123
The last combination has all digits set to their maximum value, starting at 10 - N for an N digit number.
For four digits:
6789
The combinations inbetween are found by "incrementing" the previous combination. 
This involves a search from right to left looking for the rightmost digit that is not at its maximum value. 
For example, if the current combination for 4 digits is:
0589
 ^ this is the rightmost digit that can be incremented
Form the next combination by incrementing that digit and setting all digits to its right 
to one more than the previous digit:
0678
 ^ this is the first changed digit, the digits to the right are set sequentially
*/

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_array(char v[], int size, int last)
{
	int		i;

	i = 0;
	if (v[0] == last)
	{
		while (i < size)
			ft_putchar(v[i++]);
		write(1, ".\n", 2);
		return ;
	}
	while (i < size)
		ft_putchar(v[i++]);
	write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	char	v[10];
	char	v_max[10];
	int		flag;
	int		base;

	if (n <= 0 || n > 10)
	{
		write(1, "Insert an 0<n<10\n", 17);
		return ;
	}

	for (int i=0; i<n; ++i)
	{
		v[i] = i + 48;
		// I create both initial and final STATES that i wanna reach.
		// USE A WHILE HERE for Norminette
		v_max[i] = (10 - n) + i + 48;
	}		
	
	//Routine to print the checked vector
	print_array(v, n, v_max[0]);	
			
	//When v[0] has its max value i know i'm done, cause this is FORCEFULLY the last config possible 
	while (v[0] != v_max[0])
	{
		//Find position of int that should be increased
		//We assume initially it is in last position for every iteration
		flag = n-1;
		while (v[flag] == v_max[flag])
			--flag;
		base = ++(v[flag]);
		//Set following numbers properly
		while (flag < n-1)
			v[++flag] = ++base;
		print_array(v, n, v_max[0]);
	}
}

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

int		main(int argc, char** argv)
{	
    int n;
    
    if (argc < 2)
    {
        ft_putstr("Please give a number\n");
        return (1);
    }
    n = ft_atoi(argv[1]);
	ft_putstr("\nResult:\n");
	ft_print_combn(n);
	ft_putstr("----------\n");
    return (0); 
}
