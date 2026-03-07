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

#ifndef FT_ABS_H
# define FT_ABS_H

// If the past value is negative, the value is converted to positive
# define ABS(Value) (Value < 0 ? -Value : Value)

#endif