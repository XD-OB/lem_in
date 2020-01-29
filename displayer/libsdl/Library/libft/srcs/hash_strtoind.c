/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_strtoind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 07:38:20 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:38:34 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			hash_strtoind(char **tab_hash, int size, char *str)
{
	int		ind;
	int		i;

	ind = hash_str(str) % size;
	i = ind;
	while (i < size)
	{
		if (!tab_hash[i])
			return (i);
		i++;
	}
	i = 0;
	while (i < ind)
	{
		if (!tab_hash[i])
			return (i);
		i++;
	}
	return (-1);
}
