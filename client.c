/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:47:15 by ie-laabb          #+#    #+#             */
/*   Updated: 2021/12/12 23:35:13 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char **argv)
{
    int i;
	int j;
	int a;

	a = 1;
	if (argc == 3)
    {
		while (argv[2])
		{
			i = conv_binary(argv[2][j]);
			while (a > 0)
			{
				if ((a&i) != 0)
					printf("%d\n", (a&i));
				else if ((a&i) == 0)
					
				a = a << 1;
			}
			j++;
		}		
    }
	else
		ft_putstr("ERROR incorrecte arguments [PID], [Message]");
}