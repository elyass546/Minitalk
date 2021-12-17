/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:47:15 by ie-laabb          #+#    #+#             */
/*   Updated: 2021/12/17 21:18:26 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	rest_nbr(const char *str, int sign, int i)
{
	long	res;
	long	num;

	res = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = ((str[i] - '0') + (res * 10));
		if (sign == -1)
		{
			if (res / 10 != num)
				return (0);
		}
		if (sign == 1)
		{
			if (res / 10 != num)
				return (-1);
		}
		num = (str[i++] - '0') + (num * 10);
	}
	return (num * sign);
}

int	ft_atoi(const char	*str)
{
	long	i;
	long	num;
	int		sign;

	i = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	num = rest_nbr(str, sign, i);
	return (num);
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit != -1)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit--;
		usleep(100);
	}
}

void	str_to_char(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		send_char(pid, str[i++]);
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	char	*str;
	int		i;

	str = argv[1];
	if (argc == 3)
	{
		if (ft_atoi(str) <= 0 || str == NULL)
			exit(1);
		i = 0;
		while (str[i])
		{
			if (str[i] < 0 && str[i] > 9)
				exit(1);
			i++;
		}
		str_to_char(ft_atoi(argv[1]), argv[2]);
	}
	else
	{
		i = 0;
		str = "ERROR incorrecte arguments [PID], [Message]";
		while (str[i])
			write(1, &str[i++], 1);
	}
}
