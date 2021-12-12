#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int ft_pow(int nbr, int power);
int	ft_atoi(const char	*str);
size_t	ft_strlen(char *str);
int	conv_binary(int c);
int	ft_nbrlen(long nb);
char	*ft_itoa(int n);
void	ft_putstr(char *str);

# endif