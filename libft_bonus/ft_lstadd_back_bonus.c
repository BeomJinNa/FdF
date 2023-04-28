/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:01:31 by bena              #+#    #+#             */
/*   Updated: 2023/04/29 04:32:39 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_list_bonus.h"

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}
