/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_events.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:19:11 by bena              #+#    #+#             */
/*   Updated: 2023/05/09 14:20:02 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_EVENTS_H
# define E_EVENTS_H

enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
#endif
