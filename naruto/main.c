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

#include "narutocust.h"
#include <unistd.h>
#include <stdlib.h>


int	main(int argc, char *argv[])
{
    int n;
    int base;

    if (argc < 2)
    {
        ft_putstr("Please give a valid number of combinations\n");
        return (1);
    }
    n = argv[1][0] - 48;
    base = 2;
    if (argc == 2)
    {
        ft_putstr("No base given, default to 2\n");
    }
    else
    {
        base = argv[1][0] - 48;
    }
    binNarutoWrapper(n, base);

    return (0);
}
