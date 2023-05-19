/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_line_feed_to_space.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 08:10:52 by bena              #+#    #+#             */
/*   Updated: 2023/05/24 08:13:46 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void convert_line_feed_to_space(char *line)
{
	char	*ptr;

	ptr = ft_strchr(line, '\n');
	if (ptr != NULL)
		*ptr = ' ';
}
