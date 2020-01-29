/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ic_revlstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 07:41:08 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:42:46 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ic_revlstnew(t_icase *path)
{
	t_icase		*copy;
	t_list		*new;

	copy = ic_revcopy(path);
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->content = copy;
	new->next = NULL;
	return (new);
}
