/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:59:43 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/02/18 12:13:18 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

// Structures are data composed of one or more fields
typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}			t_stock_str;

#endif