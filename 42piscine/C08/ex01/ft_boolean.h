/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:59:43 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/02/18 12:13:18 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H

#include <unistd.h>

#define SUCCESS 0
#define TRUE 1
#define FALSE 0

#define EVEN(nbr) (nbr % 2 == 0)

# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"

typedef int t_bool;

void    ft_putchar(char c);
t_bool  ft_is_even(int nbr);

#endif /* INVENTORY_H */