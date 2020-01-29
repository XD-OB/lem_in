/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_pushfront.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 07:54:43 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:56:24 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		chr_pushfront(t_chr **list, char *str, int len)
{
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
	node->next = *list;
	*list = node;
}
