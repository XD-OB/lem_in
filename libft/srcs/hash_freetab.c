/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_freetab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 07:37:49 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:37:51 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		hash_freetab(char ***tab_hash, int size)
{
	int		i;

	i = 0;
	while (i < size)
		free((*tab_hash)[i++]);
	free(*tab_hash);
}
