/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:14:29 by bena              #+#    #+#             */
/*   Updated: 2023/04/29 04:32:25 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_list_bonus.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == 0)
		return ;
	del(lst->content);
	free(lst);
}
