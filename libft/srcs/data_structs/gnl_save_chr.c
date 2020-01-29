/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_save_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 07:47:19 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:50:16 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_chr		*gnl_save_chr(int fd)
{
	t_chr	*input;
	char	*line;
	int		ret;

	input = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
		chr_addnode(&input, line, ft_strlen(line));
	if (ret == 0)
		return (input);
	if (input)
		chr_free(&input);
	return (NULL);
}
