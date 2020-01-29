/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 07:55:56 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:55:58 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		chr_len(t_chr *chr)
{
	int		len;

	len = 0;
	while (chr)
	{
		len++;
		chr = chr->next;
	}
	return (len);
}