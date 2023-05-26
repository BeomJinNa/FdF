/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_the_map_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 03:57:01 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 10:20:58 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "s_map.h"

void		convert_line_feed_to_space(char *line);
void		get_min_max_value(t_map *map);
static void	import_file(t_list **map, int fd);
static void	write_map_from_text(t_map *map, t_list *text);
static int	get_point_array(t_point **array, char *line);
static void	remove_data(t_map *map, t_list *text);

void	parse_the_map_file(t_map *map, int fd)
{
	t_list	*text;
	char	*buffer;

	map->point = NULL;
	map->width = 0;
	map->height = 0;
	import_file(&text, fd);
	buffer = get_next_line(fd);
	while (buffer != NULL)
	{
		free(buffer);
		buffer = get_next_line(fd);
	}
	if (text == NULL)
		return ;
	write_map_from_text(map, text);
	if (map->point != NULL)
		get_min_max_value(map);
}

static void	import_file(t_list **map, int fd)
{
	char	*parsed_line;
	t_list	*lastnode;

	*map = NULL;
	parsed_line = get_next_line(fd);
	if (parsed_line == NULL)
		return ;
	convert_line_feed_to_space(parsed_line);
	*map = ft_lstnew(parsed_line);
	if (*map == NULL)
		return (free(parsed_line));
	lastnode = *map;
	parsed_line = get_next_line(fd);
	while (parsed_line != NULL)
	{
		convert_line_feed_to_space(parsed_line);
		lastnode->next = ft_lstnew(parsed_line);
		if (lastnode->next == NULL)
		{
			ft_lstclear(map, free);
			return (free(parsed_line));
		}
		lastnode = lastnode->next;
		parsed_line = get_next_line(fd);
	}
}

static void	write_map_from_text(t_map *map, t_list *text)
{
	t_list		*list_ptr;
	t_point		**point_ptr;
	int			width;
	const int	size = ft_lstsize(text);

	map->point = (t_point **)malloc(sizeof(t_point *) * (size + 1));
	if (map->point == NULL)
		return (ft_lstclear(&text, free));
	*(map->point + size) = NULL;
	point_ptr = map->point;
	list_ptr = text;
	width = get_point_array(point_ptr, list_ptr->content);
	if (width == 0 || *point_ptr == NULL)
		return (remove_data(map, text));
	while (list_ptr->next != NULL)
	{
		list_ptr = list_ptr->next;
		if (get_point_array(++point_ptr, list_ptr->content) != width
			|| *point_ptr == NULL)
			return (remove_data(map, text));
	}
	map->width = width;
	map->height = size;
	ft_lstclear(&text, free);
}

static int	get_point_array(t_point **array, char *line)
{
	char	**char_array;
	char	**text_ptr;
	t_point	*point_ptr;
	size_t	arr_size;

	*array = NULL;
	char_array = ft_split(line, ' ');
	if (char_array == NULL)
		return (0);
	arr_size = 0;
	text_ptr = char_array;
	while (*text_ptr++ != NULL)
		arr_size++;
	*array = (t_point *)malloc(sizeof(t_point) * arr_size);
	point_ptr = *array;
	text_ptr = char_array;
	if (*array != NULL)
		while ((size_t)(point_ptr - *array) < arr_size)
			(point_ptr++)->value = ft_atoi(*text_ptr++);
	text_ptr = char_array;
	while (*text_ptr != NULL)
		free(*text_ptr++);
	free(char_array);
	return (arr_size);
}

static void	remove_data(t_map *map, t_list *text)
{
	t_point	**ptr;

	if (text != NULL)
		ft_lstclear(&text, free);
	ptr = map->point;
	if (ptr == NULL)
		return ;
	while (*ptr != NULL)
		free(*ptr++);
	free(map->point);
	map->point = NULL;
}
