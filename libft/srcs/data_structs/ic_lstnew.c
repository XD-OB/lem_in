/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ic_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 07:44:58 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:45:13 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ic_lstnew(t_icase *path)
{
	t_list		*new;
	t_icase		*copy;

	copy = ic_copy(path);
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->content = copy;
	new->next = NULL;
	return (new);
}
