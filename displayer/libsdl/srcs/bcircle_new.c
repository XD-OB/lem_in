/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcircle_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 03:24:30 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 20:31:06 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

t_bcircle		bcircle_new(t_point c, int r, int bold)
{
	t_bcircle	bcircle;

	bcircle.c = c;
	bcircle.r = r;
	bcircle.bold = bold;
	return (bcircle);
}
