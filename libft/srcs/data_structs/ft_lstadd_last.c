/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 07:51:44 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:53:28 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_last(t_list **lst, t_list *node)
{
	t_list	*current;

	if (!node)
		return ;
	if (*lst)
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = node;
	}
	else
		*lst = node;
}
