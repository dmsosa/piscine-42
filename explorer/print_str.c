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

void	print_str(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[], char *env[])
{

    int i;
    char *word;

    word = argv[1];
    i = 0;
    while (word[i])
    {

        write(1, &word[i], 1);
        i = i + 1;
    }

    return (0);
}
