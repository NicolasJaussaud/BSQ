/*
** EPITECH PROJECT, 2017
** structparam
** File description:
** structure
*/

typedef struct param_s
{
	char *str;
	int nbLin;
	int nbCol;
	int first;
	int boolean;
}	param_t;

typedef struct tab_s
{
	int **tab;
	int *tab2;
	char **tabstr;
	char *tabstr2;
	int max[3];
}	tab_t;