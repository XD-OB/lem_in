/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 08:35:00 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/25 09:36:09 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_point		pt_rot(t_point c, t_point a, int o_deg)
{
	float		o_rad;
	t_point		b;

	o_rad = (o_deg * M_PI) / 180;
	b.x = (a.x - c.x) * cos(o_rad) - (a.y - c.y) * sin(o_rad) + c.x;
	b.y = (a.y - c.y) * cos(o_rad) + (a.x - c.x) * sin(o_rad) + c.y;
	return (b);
}
