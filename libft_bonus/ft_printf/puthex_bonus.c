/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:04:46 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:20:12 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	write_nbr(char *buffer, size_t buffer_len);
ssize_t		ft_write_printf(const void *buf, size_t nbyte);

void	puthex_u_printf(unsigned int num)
{
	char		buffer[8];
	char		*ptr;
	const char	*hex = "0123456789ABCDEF";

	ptr = buffer;
	if (num == 0)
		*ptr++ = '0';
	while (num)
	{
		*ptr++ = hex[num % 16];
		num /= 16;
	}
	write_nbr(buffer, ptr - buffer);
}

void	puthex_l_printf(unsigned int num)
{
	char		buffer[8];
	char		*ptr;
	const char	*hex = "0123456789abcdef";

	ptr = buffer;
	if (num == 0)
		*ptr++ = '0';
	while (num)
	{
		*ptr++ = hex[num % 16];
		num /= 16;
	}
	write_nbr(buffer, ptr - buffer);
}

static void	write_nbr(char *buffer, size_t buffer_len)
{
	char	str[8];
	char	*ptr;

	ptr = str;
	buffer += buffer_len;
	while (buffer_len--)
		*ptr++ = *--buffer;
	ft_write_printf(str, ptr - str);
}
