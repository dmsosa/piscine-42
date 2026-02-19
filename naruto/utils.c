#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}	

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
        ft_putchar(str[i]);
        i++;
    }
}

int	ft_arrlen(char *arr)
{
	int i;

	i = 0;
	while (arr[i] != '\0')
	{
        i++;
    }
    return (i);
}

void    printArray(char *arr)
{
    int i;
    int size;

    i = 0;
    size = ft_arrlen(arr);
    while (i < size)
    {
        ft_putchar(arr[i]);
        ft_putchar(' ');
        i++;
    }
    ft_putchar('\n');
}

int ft_atoi(char *str)
{
    
}