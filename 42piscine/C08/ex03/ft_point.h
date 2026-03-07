/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:59:43 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/02/18 12:13:18 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H

# include <unistd.h>

// If the past value is negative, the value is converted to positive
typedef struct s_point {
    int x;
    int y;
} t_point;

void	set_point(t_point *point);

#endif