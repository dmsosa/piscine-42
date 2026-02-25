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

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_array(char v[], int size, int last)
{
	int		i;

	i = 0;
	while (i < size)
	{
	    ft_putchar(v[i] + 48);
		i++;
	}
	if (v[0] == last)
		write(1, ".\n", 2);
	else
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
		v[i] = i;
		// I create both initial and final STATES that i wanna reach.
		// USE A WHILE HERE for Norminette
		v_max[i] = (10 - n) + i;
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

void	ft_print_combn_backtrack(int pos, int size, int start, char *v)
{
	int		i;
	
	if (pos == size)
	{
	    print_array(v, size, 10 - size);
	    return;
	}
	i = start;
	while (i < 10)
	{
	    v[pos] = i;
	    ft_print_combn_backtrack(pos + 1, size, i + 1, v);
	    i++;
	}
}
int		main(int argc, char **argv)
{
    int n;
    char v[10];
    
//     n = 3;
//     if (argc < 2)
//     {
//         write(1, "Please give a number\n", 17);
// 		return (1);
//     }
//     if (n <= 0 || n > 10)
// 	{
// 		write(1, "Please insert a number 0<n<10\n", 25);
// 		return (1);
// 	}
	ft_print_combn(2);
	write(1, "\nCOMBO 1\n", 9);
	ft_print_combn_backtrack(0, 10, 0, v);
	write(1, "\nCOMBO 2\n", 9);
	write(1, "\nFINAL\n", 7);
	return (0);
}
