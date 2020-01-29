/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ic_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 07:45:59 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:46:12 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ic_free(t_icase **icase)
{
	t_icase		*curr;
	t_icase		*tmp;

	tmp = *icase;
	while (tmp)
	{
		curr = tmp;
		tmp = tmp->next;
		free(curr);
	}
	icase = NULL;
}
