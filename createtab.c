/*
** EPITECH PROJECT, 2017
** createtab
** File description:
** Create tab || 2017 - JAUSSAUD NICOLAS
*/

#include "./include/my.h"

int **createtab(char *str, int first, int **tab) {
	int d = 0;
	int u = 0;

	while (str[first] != '\0') {
		if (str[first] == '.')
			tab[d][u] = 1;
		if (str[first] == 'o')
			tab[d][u] = 0;
		u++;
		if (str[first] == '\n') {
			u = 0;
			d++;
		}
		first++;
	}
	return (tab);
}

char **createstrtab(char **tabstr, param_t p) 
{
	int w = 0;
	int z = 0;
	int y = p.first;

	while (w != p.nbLin) {
		tabstr[w][z] = p.str[y];
		z++;
		if (z == p.nbCol) {
			y = y + 1;
			w++;
			z = 0;
		}
		y++;
	}
	return (tabstr);
}
