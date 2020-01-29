/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_nsave_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 07:50:26 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 08:00:08 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_chr		*gnl_nsave_chr(int fd, int nbr_lines)
{
	t_chr	*input;
	char	*line;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	input = NULL;
	while ((nbr_lines == -1 || i < nbr_lines) &&
			((ret = get_next_line(fd, &line)) > 0))
	{
		chr_addnode(&input, line, ft_strlen(line));
		i++;
	}
	if (ret == 0 || i == nbr_lines)
		return (input);
	if (input)
		chr_free(&input);
	return (NULL);
}
