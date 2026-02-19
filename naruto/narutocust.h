#ifndef NARUTO_H
#define NARUTO_H

#include <stdlib.h>
#include <unistd.h>

void    printArray(char *arr);
int    ft_arrlen(char *arr);
void	ft_putchar(char c);
void    ft_putstr(char *c);
void	binNarutoWrapper(int n_digits, int base);
void	binNarutoCustom(int idx, int base, int n_digits, char *digits);

#endif