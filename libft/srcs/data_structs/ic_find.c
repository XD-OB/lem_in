/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ic_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 07:46:42 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:46:54 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ic_find(t_icase *path, int n)
{
	t_icase		*icase;

	icase = path;
	while (icase)
	{
		if (icase->n == n)
			return (1);
		icase = icase->next;
	}
	return (0);
}
