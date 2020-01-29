/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstextfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 07:50:49 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:50:54 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstextfree(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
}
