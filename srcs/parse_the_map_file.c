/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_the_map_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 03:57:01 by bena              #+#    #+#             */
/*   Updated: 2023/04/29 04:23:39 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "s_map.h"

void	parse_the_map_file(t_map *map, int fd)
{
	t_list	map_text;
	t_list	last_node;
	char	*parsed_line;

	parsed_line = get_next_line(fd);
	if (parsed_line != NULL)
	{
		last_node = ft_lstnew(parsed_line);
		if (last_node == NULL);

	}
}
