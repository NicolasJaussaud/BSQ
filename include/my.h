/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** all my headers 
*/

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "structparam.h"

char	*get_file(char *path);
int findparam(int *nbCol, char *str, int *boolean);
param_t initparam(param_t p, char **av);
tab_t inittab(tab_t t, param_t p);
int my_getnbr(char const *str);
void my_putchar(char c);
int **createtab(char *str, int first, int **tab);
char **createstrtab(char **tabstr, param_t p);
int findnblin(char *str, int nbLin);
