#include "narutocust.h"

#include <stdlib.h>


// void    printBoard(int arr[4][4], int size)
// {
//     int i;
//     int j;
//     char    c;

//     while (i < size)
//     {
//         while (j < size)
//         {
//             c = arr[i][j] + 48;
//             ft_putchar(c);
//             ft_putchar(' ');
//             j++;
//         }
//         c = '\n';
//         ft_putchar(c);
//         i++;
//     }
// }

// void	biNarutoHelper(int idx, int digits, char *v) 
// {

//   //🥷🖨️ BASE CASE 🖨️🥷
// 	if (idx == digits)
// 	{
// 		p("%s\n", v);
// 	}

//   //🥷 RECURSION 🥷
// 	else
// 	{
// 		v[idx] = '0';
// 		biNarutoHelper(idx + 1, digits, v);

// 		v[idx] = '1';
// 		biNarutoHelper(idx + 1, digits, v);
// 	}
// }


void	binNarutoCustom(int idx, int base, int n_digits, char *digits)
{   
    int i;

    i = 0;

	if (idx == n_digits)
    {
        printArray(digits);
    } else {
        while (i < base)
        {
            if (base < 9) {
                digits[idx] = i + 48;
            }
            else
            {
                digits[idx] = i + 65;
            }
            
            binNarutoCustom(idx + 1, base, n_digits, digits);
            i++;
        }
    }
	
}

void	binNarutoWrapper(int n_digits, int base)
{
    char *digits;

    digits = malloc((n_digits * sizeof (char)) + 1);
    if (!digits)
    {
        ft_putstr("Error in Malloc\n");
        return;
    }
    binNarutoCustom(0, base, n_digits, digits);
    free(digits);
}
