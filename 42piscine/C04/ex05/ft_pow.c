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

#include "libft.h"

int		ft_pow(int base, int pow)
{
	//Recursion Power
	if (0 == pow)
		return 1;
	else 
		return ft_pow(base, pow - 1) * base;
}