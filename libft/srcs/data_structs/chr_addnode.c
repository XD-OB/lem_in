/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_addnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 07:52:08 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:52:21 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		chr_addnode(t_chr **list, char *str, int len)
{
	t_chr	*curr;
	t_chr	*node;

	if (!(node = (t_chr*)malloc(sizeof(t_chr))))
		return ;
	node->str = ft_strdup(str);
	node->len = len;
	node->next = NULL;
	if (!*list)
	{
		*list = node;
		return ;
	}
	curr = *list;
	while (curr->next)
		curr = curr->next;
	curr->next = node;
}
