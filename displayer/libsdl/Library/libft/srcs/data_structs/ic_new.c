/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ic_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 05:04:13 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:43:43 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_icase			*ic_new(int n)
{
	t_icase		*new;

	if (!(new = (t_icase*)malloc(sizeof(t_icase))))
		return (NULL);
	new->n = n;
	new->next = NULL;
	return (new);
}
