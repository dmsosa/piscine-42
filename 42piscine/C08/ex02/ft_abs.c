/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:30:19 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/02/20 10:30:37 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This is the code passed by the exercise
// If 1 parameter the return is odd if you have 2, the return is even
#include "ft_abs.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void		ft_putnbr(int n)
{
	if (n == -2147483648)
    {
		write(1, "-2147483648", 11);
        return ;
    }
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n < 10)
    {
		ft_putchar(n % 10 + '0');
	}
	else
    {
        ft_putnbr(n / 10);
        ft_putchar(n % 10 + '0');
    }
}

int	main(int argc, char **argv)
{
	int	nbr;
	if (argc >= 2)
	{
		nbr = argv[1];
		ft_putstr("ABS value is: ");
		ft_putnbr(nbr);
	}
	return (0);
}
