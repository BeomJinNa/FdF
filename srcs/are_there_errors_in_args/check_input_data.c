/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:10:42 by bena              #+#    #+#             */
/*   Updated: 2023/05/26 09:26:30 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			is_this_wrong_character(int c);
int			is_this_space(int c);
int			is_this_sign(int c);
static int	check_the_bad_sign(const char **ptr);

int	is_there_wrong_character(char *str)
{
	const char	*ptr;

	ptr = str;
	while (*ptr)
		if (is_this_wrong_character(*ptr++))
			return (1);
	return (0);
}

int	is_there_bad_position_of_sign(char *str)
{
	const char	*ptr;

	ptr = str;
	while (is_this_space(*ptr))
		ptr++;
	while (*ptr)
	{
		if (check_the_bad_sign(&ptr))
			return (1);
		while (is_this_space(*ptr))
			ptr++;
	}
	return (0);
}

static int	check_the_bad_sign(const char **ptr)
{
	int	sign_stack;

	sign_stack = 0;
	while (is_this_sign(**ptr))
	{
		sign_stack++;
		*ptr += 1;
	}
	if (sign_stack > 1 || ft_isdigit(**ptr) == 0)
		return (1);
	while (**ptr && is_this_space(**ptr) == 0)
	{
		if (is_this_sign(**ptr))
			return (1);
		*ptr += 1;
	}
	return (0);
}

int	does_any_overflow_occur(char *str)
{
	int			count_digits;
	const char	*ptr;

	ptr = str;
	while (*ptr)
	{
		count_digits = 0;
		while (*ptr && (is_this_sign(*ptr) || is_this_space(*ptr)))
			ptr++;
		while (*ptr == '0')
			ptr++;
		while (ft_isdigit(*ptr))
		{
			count_digits++;
			ptr++;
			if (count_digits > 10)
				return (1);
		}
	}
	return (0);
}

int	is_the_value_invalid(const char *str)
{
	int			sign;
	int			error;
	long long	output;

	error = 0;
	while (is_this_space(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	output = 0;
	while ('0' <= *str && *str <= '9')
	{
		output = output * 10 + *str - '0';
		str++;
	}
	output = sign * output;
	if (output < -2147483648 || 2147483647 < output)
		error = 1;
	return (error);
}
