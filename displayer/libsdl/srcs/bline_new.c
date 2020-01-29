/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bline_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:32:23 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 20:32:55 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

t_bline			bline_new(t_point pi, t_point pf, int bold)
{
	t_bline		bline;

	bline.pi = pi;
	bline.pf = pf;
	bline.bold = bold;
	return (bline);
}
