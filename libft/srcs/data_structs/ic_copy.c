/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ic_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 07:46:20 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:46:29 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_icase			*ic_copy(t_icase *icase)
{
	t_icase		*copy;

	copy = NULL;
	while (icase)
	{
		ic_addnode(&copy, icase->n);
		icase = icase->next;
	}
	return (copy);
}
