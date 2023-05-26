/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_dist_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:24:10 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 11:26:25 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_map.h"

static void		sort(t_point **start, t_point **end);
static void		finish_sort(t_point **start, t_point **end);
static void		swap(t_point **a, t_point **b);
static double	select_pivot(t_point **start, t_point **end);

void	refresh_dist_index(t_status *stat)
{
	const int	size = stat->map.width * stat->map.height;

	sort(stat->map.index, stat->map.index + size - 1);
}

static void	sort(t_point **start, t_point **end)
{
	double	pivot;
	t_point	**left;
	t_point	**right;

	if (end - start < 3)
		return (finish_sort(start, end));
	pivot = select_pivot(start, end);
	left = start;
	right = end;
	while (left < right)
	{
		while (left < end && (*left)->distance > pivot)
			left++;
		while (right > start && (*right)->distance <= pivot)
			right--;
		if (left < right)
			swap(left, right);
	}
	if (left == right)
		left++;
	sort(start, right);
	sort(left, end);
}

static void	finish_sort(t_point **start, t_point **end)
{
	if (end == start)
		return ;
	if (end - start == 1)
	{
		if ((*start)->distance < (*end)->distance)
			return (swap(start, end));
		else
			return ;
	}
	if ((*start)->distance < (*(start + 1))->distance)
		swap(start, start + 1);
	if ((*start)->distance < (*(start + 2))->distance)
		swap(start, start + 2);
	if ((*(start + 1))->distance < (*(start + 2))->distance)
		swap(start + 1, start + 2);
}

static void	swap(t_point **a, t_point **b)
{
	t_point	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static double	select_pivot(t_point **start, t_point **end)
{
	double	pivot[3];
	double	temp;

	pivot[0] = (*start)->distance;
	pivot[1] = (*(start + ((end - start) / 2)))->distance;
	pivot[2] = (*(end))->distance;
	if (pivot[0] > pivot[1])
	{
		temp = pivot[0];
		pivot[0] = pivot[1];
		pivot[1] = temp;
	}
	if (pivot[0] > pivot[2])
	{
		temp = pivot[0];
		pivot[0] = pivot[2];
		pivot[2] = temp;
	}
	if (pivot[1] > pivot[2])
	{
		temp = pivot[1];
		pivot[1] = pivot[2];
		pivot[2] = temp;
	}
	return (pivot[1]);
}
