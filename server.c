/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:30:45 by ie-laabb          #+#    #+#             */
/*   Updated: 2021/12/17 21:19:11 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb <= 9)
		ft_putchar(nb + '0');
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	salam(int i)
{
	static char	str[1000];
	static int	count = 0;
	static int	bit = 7;

	if (i == SIGUSR2)
		str[count] |= (1 << bit);
	if (i == SIGUSR1)
		str[count] &= ~(1 << bit);
	bit--;
	if (bit == -1)
	{
		bit = 7;
		if (str[count] == '\0')
		{
			write(1, str, count);
			write(1, "\n", 1);
			count = 0;
		}
		else
			count++;
	}
}

int	main(int argc, char **argv)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, salam);
	signal(SIGUSR2, salam);
	while (1)
		pause();
}
