/*
** EPITECH PROJECT, 2017
** initstruct
** File description:
** initstruct || 2017
*/

#include "./include/my.h"

param_t initparam(param_t p, char **av)
{
	p.str = get_file(av[1]);
	p.nbLin = findnblin(p.str, p.nbLin);
	p.nbCol = 0;
	p.boolean = 0;
	p.first = findparam(&p.nbCol, p.str, &p.boolean);
	return (p);
}

tab_t inittab(tab_t t, param_t p)
{
	t.tab = (int **)malloc(sizeof(int*) * p.nbLin);
	t.tab2 = (int *)malloc(sizeof(int) * p.nbCol * p.nbLin);
	for(int j = 0 ; j < p.nbLin ; j++)
		t.tab[j] = &t.tab2[j * p.nbCol];
	t.tabstr = (char **)malloc(sizeof(char*) * p.nbLin);
	t.tabstr2 = (char *)malloc(sizeof(char) * p.nbCol * p.nbLin);
	for(int j = 0 ; j < p.nbLin ; j++)
		t.tabstr[j] = &t.tabstr2[j * p.nbCol];
	t.max[0] = 0;
	return (t);
}