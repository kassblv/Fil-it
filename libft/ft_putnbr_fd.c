/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:34:44 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/10 20:19:29 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int c;

	c = n;
	if (c < 0)
	{
		ft_putchar_fd('-', fd);
		c = -c;
	}
	if (c > 9)
	{
		ft_putnbr_fd((c / 10), fd);
		ft_putnbr_fd((c % 10), fd);
	}
	else
		ft_putchar_fd((c + '0'), fd);
}
