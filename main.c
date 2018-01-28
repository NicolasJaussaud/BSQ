/*
** EPITECH PROJECT, 2017
** key
** File description:
** read&save file 
*/

#include "./include/my.h"

int findparam(int *nbCol, char *str, int *boolean) {
	int i = 0;
	int first = 0;

	while (*boolean != 2) {
		if ((str[i] == '.' || str[i] == 'o') && *boolean == 0) {
			first = i;
			*boolean = 1;
		}
		if (str[i + first] == '\n' && *boolean == 1) {
			*nbCol = i;
			*boolean = 2;
		}
		i++;
	}
	return (first);
}

int **calculmin(int **tab, int (*max)[3], int nbLin, int nbCol) 
{
	int d = 0;
	int u = 0;
	int min = 9999999;

	while (d != (nbLin - 1)) {
		if (tab[d][u] < min && tab[d + 1][u + 1] != 0)
			min = tab[d][u];
		if (tab[d][u + 1] < min && tab[d + 1][u + 1] != 0)
			min = tab[d][u + 1];
		if (tab[d + 1][u] < min && tab[d + 1][u + 1] != 0)
			min = tab[d + 1][u];
		if (min == 9999999)
			min = -1;
		tab[d + 1][u + 1] = min + 1;
		if ((*max)[0] < min + 1) {
			(*max)[0] = min + 1;
			(*max)[1] = d + 1;
			(*max)[2] = u + 1;
		}
		min = 9999999;
		u++;
		if (u + 1 == nbCol) {
			d++;
			u = 0;
		}
	}
	return (tab);
}

void replacex(param_t p, tab_t t)
{

	int c = 0;
	int b = 0;
	int n = 0;
	int o = 0;
	int i = 0;
	int a = 0;
	char *tabstr3 = malloc(sizeof(char) * (p.nbLin * p.nbCol + p.nbLin));

	while (c != p.nbLin) {
		if (c + t.max[0] - 1 == t.max[1] && b + t.max[0] - 1 == t.max[2])
			while (i != t.max[0]) {
				t.tabstr[c + n][b + o] = 'x';
				o++;
				if (o == t.max[0]) {
					i++;
					n++;
					o = 0;
				}
			}
		tabstr3[a] = t.tabstr[c][b];
		b++;
		if (b == p.nbCol) {
			b = 0;
			c++;
			a++;
			tabstr3[a] = '\n';
		}
		a++;
	}
	tabstr3[a] = '\0';
	write(1, tabstr3, a);
	free(tabstr3);
}

int findnblin(char *str, int nbLin)
{	
	char *lin;
	int i = 0;
	int j = 0;

	while (str[i] != '\0') {
		if (str[i] == '.' || str[i] == 'o')
			break;
		i++;
	}
	lin = malloc(sizeof(char) * i);
	while (j != i) {
		lin[j] = str[j];
		j++;
	}
	lin[j - 1] = '\0';
	nbLin = my_getnbr(lin);
	return (nbLin);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (84);
	param_t p = initparam(p, av);
	tab_t t = inittab(t, p);
	t.tab = createtab(p.str, p.first, t.tab);
	t.tab = calculmin(t.tab, &t.max, p.nbLin, p.nbCol);
	t.tabstr = createstrtab(t.tabstr, p);
	replacex(p, t);
	free(t.tab);
	free(t.tab2);
	free(t.tabstr);
	free(t.tabstr2);
	free(p.str);
	return (0);
}
