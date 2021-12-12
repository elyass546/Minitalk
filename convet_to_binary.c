/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convet_to_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:02:53 by ie-laabb          #+#    #+#             */
/*   Updated: 2021/12/12 22:33:05 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	conv_binary(int c)
{
	char	str[1024];
	int		i;
	int		j;
	char	*str_return;

	i = 0;
	while (c > 0)
	{
		str[i] = c % 2 + '0';
		c = c / 2;
		i++;
	}
	str[i] = c % 2 + 48;
	str[i + 1] = '\0';
	i = i - 1;
	j = 0;
	str_return = (char *)malloc(sizeof(char) * i);
	while (i >= 0)
		str_return[j++] = str[i--];
	str_return[i] = '\0';
	return (ft_atoi(str_return));
}
