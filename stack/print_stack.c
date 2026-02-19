/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:21:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/01/31 14:00:33 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_stack(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[], char *env[])
{

    char init;
    char *ptr;

    init = 'a';
    ptr = &init;
    while (1)
    {
        if (*ptr == '\0')
        {
            write(1, "\n", 1);
        }
        write(1, ptr++, 1);
    }

    return (0);
}
