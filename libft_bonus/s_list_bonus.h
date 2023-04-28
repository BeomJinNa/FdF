/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 04:25:35 by bena              #+#    #+#             */
/*   Updated: 2023/04/29 04:30:48 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LIST_BONUS_H
# define S_LIST_BONUS_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
#endif
