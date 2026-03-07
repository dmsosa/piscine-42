/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/30 14:15:59 by pbie              #+#    #+#             */
/*   Updated: 2026/11/30 15:10:11 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
#include <stdio.h>

void	set_point(t_point *point)
{
	// defines the values for the struct variables
	point-> x = 42;
	point-> y = 21;
}
int	main(void)
{
	t_point point;
	
	set_point(&point);
	printf("Valor de x: %d\n", point.x);
    printf("Valor de y: %d\n", point.y);
	return (0);
}