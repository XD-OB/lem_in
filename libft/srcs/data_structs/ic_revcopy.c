/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ic_revcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 07:41:36 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:43:17 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_icase			*ic_revcopy(t_icase *icase)
{
	t_icase		*copy;

	copy = NULL;
	while (icase)
	{
		ic_pushnode(&copy, icase->n);
		icase = icase->next;
	}
	return (copy);
}
