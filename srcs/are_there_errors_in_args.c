/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_there_errors_in_args.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:43:45 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 09:27:28 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			is_there_wrong_character(char *str);
int			is_there_bad_position_of_sign(char *str);
int			does_any_overflow_occur(char *str);
int			is_the_value_invalid(const char *str);
static int	does_empty_arg_exist(int ac, char **av);
static int	does_input_error_exist(char *str1, char *str2);

int	are_there_errors_in_args(int ac, char **av)
{
	if (does_empty_arg_exist(ac, av))
		return (1);
	if (does_input_error_exist(av[2], av[3]))
		return (1);
	return (0);
}

static int	does_empty_arg_exist(int ac, char **av)
{
	char	*ptr;

	while (--ac > 1)
	{
		ptr = av[ac];
		while (*ptr)
		{
			if (ft_isdigit(*ptr))
				break ;
			ptr++;
		}
		if (*ptr == '\0')
			return (1);
	}
	return (0);
}

static int	does_input_error_exist(char *str1, char *str2)
{
	if (is_there_wrong_character(str1) || is_there_wrong_character(str2))
		return (1);
	if (is_there_bad_position_of_sign(str1)
		|| is_there_bad_position_of_sign(str2))
		return (1);
	if (does_any_overflow_occur(str1) || (does_any_overflow_occur(str2)))
		return (1);
	if (is_the_value_invalid(str1) || is_the_value_invalid(str2))
		return (1);
	return (0);
}
