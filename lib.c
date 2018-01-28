/*
** EPITECH PROJECT, 2017
** lib
** File description:
** LIB || 2017 
*/

#include <limits.h>
#include "./include/my.h"

int my_getnbr(char const *str)
{
	int nb = 0;
	int neg = 1;
	int i = 0;

	while (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	i = 0;
	while (str[i] >= '0' && str[i] <= '9') {
		nb = nb * 10 + (str[i] - 48);
		i++;
		if (nb * neg > INT_MAX || nb * neg < INT_MIN)
			return (0);
	}
	return (nb * neg);
}

void my_putchar(char c)
{
	write(1, &c, 1);
}