/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ic_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 07:45:24 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:45:36 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ic_lstfind(t_list *list, t_icase *target)
{
	t_icase		*item;
	t_list		*tmp;

	(void)target;
	tmp = list;
	while (tmp)
	{
		item = (t_icase*)tmp->content;
		if (!ic_cmp(item, target))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
