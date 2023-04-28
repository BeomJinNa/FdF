/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:30:05 by bena              #+#    #+#             */
/*   Updated: 2023/04/29 04:32:22 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list_bonus.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (1)
	{
		f(lst->content);
		lst = lst->next;
		if (lst == 0)
			return ;
	}
}
