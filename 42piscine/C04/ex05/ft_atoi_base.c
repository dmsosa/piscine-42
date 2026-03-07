/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:06:30 by durisosa          #+#    #+#             */
/*   Updated: 2020/10/28 17:55:06 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	• Write a function that converts the initial portion of the string pointed by str to int representation.

	• str is in a specific base given as a second parameter.
	
	• excepted the base rule, the function should work exactly like ft_atoi.
	
	• If there’s an invalid argument, the function should return 0. Examples of invalid arguments :
		◦ base is empty or size of 1;
		◦ base contains the same character twice; 
		◦ base contains + or - or whitespaces;
	
	• int ft_atoi_base(char *str, char *base);
*/

//For test
#include <stdio.h>


//🏁 Flags
int 	NO_MATCH = 0;
int		INVALID_BASE = 0;




//PROTOTYPES
int 	ft_atoi_base(char *str, char *base);
int     twiceChar(char *symbols);
int     realValue(char *nbr, char *symbols, int baseValue, int positioni, int sign);
int		ft_pow(int, int);
int 	ft_isspace(char *);
int 	symbol_set(char, char *);



int ft_valid_base(char *base)
{
    while (base[i])
    {   
        if (ft_isspace(base[i]) || base[i] == '+' || base[i] == '-')
            return (-1);
        j = i + 1;
        while (base[j])
        {
            if (base[i] == base[j])
                return (-1);
            j++;
        }
        i++;
    }
    if (i < 2)
        return (-1);
    return (i);
}

int		ft_atoi(char *str)
{
	int sign;
	int result;

	sign = 1;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}	
	//Check all numbers and stock in accumulator number	
	while (*str >= 48 && *str <= 57)	
	{
		//This is a << shift_base10_like operation
		number *= 10;
		//Conversion from char to number
		number += *str - 48;
		++str;
	}
	return (number * sign);
}

int main(void)
{
	char str[] = "--+345";
	printf("My atoi: '%d'\n", ft_atoi(str));	
	printf("REAL atoi: '%d'\n", atoi(str));	
	return (0);
}



//Command line INPUTS
//gcc cafeConversion.c && ./a.out "10" "01"


int		main(int argc, char **argv)
{
	char	*base;
	char	*nbr;
	int		result;

	//Basically i have to find the value of nbr
	//in this example -> 42
	nbr = argv[1];  //"101010"
	base = argv[2]; //"01"

					//nbr & base a are strings!
	result = ft_atoi_base(nbr, base);


	if (NO_MATCH)
		printf("The symbols in the base don't match the sample number\n");
	else if (INVALID_BASE)
		printf("Invalid base\n");
	else
		printf("The real value of \"%s\" in base \"%s\" is -> %d\n", nbr, base, result);
}
	









int ft_atoi_base(char *str, char *base)
{
	//DIVIDE AND CONQUER was 
	
	int		baseValue;
	int		position;
	int 	final;
	int		sign;


	sign = +1;
	baseValue = 0;
	position = 0;
	


	//🚨PRELIMINARY STUFF🚨
	//Get the base value + controls
	while (base[baseValue])	
	{
		//base contains + or - or whitespaces
		if (base[baseValue] == '+' || base[baseValue] == '-' || base[baseValue] == ' ')
		{
		  	INVALID_BASE = 1;	
			return 0;
		}
		//"poneyvif" -> 8
		++baseValue;	
	}

	

	//base is empty or size of 1
	if (baseValue < 2)
	{
		INVALID_BASE = 1;	
		return 0;
	}



	//Base contains the same char twice
	if (twiceChar(base))
	{
		INVALID_BASE = 1;	
		return 0;
	}
		

	//POSITION is the MAGNITUDE of the number
	//Useful data for later
	//Get to know magnitude of my number
	//101010 -> 6 
	//ff -> 2
	//caffeebabe -> 10 
	while (*(str + position))
	{
		//Given a strange value 
		//" ---+--+1234ab567" skip all +, spaces, and -
		while (*str == '+' || *str == '-' || ft_isspace(str))//Ok 
		{
			if (*str == '-')
				sign *= -1;
			++str;
		}						

		//Are these chars legal?
						  //char is in symbolSet?							
		if ( ! symbol_set(*(str + position), base)) //Ok
		{
			NO_MATCH = 1;
			return 0;
		}
		++position;	
	}


          //👀 The real function;        👀☟☟☟☟☟☟☟☟☟☟☟☟👀
	return realValue(str, base, baseValue, position - 1, sign);													
}	












//REAL 🥩

int 	realValue(char *nbr, char *symbols, int baseValue, int position, int sign) 
{
	//E.G.
	//nbr-> "caffeebabe"
	//symbols-> "0123456789abcdef"
	//BaseValue-> 16
	//			            	  9  8  7  6  5  4  3  2  1  0	
	//Position-> 1 We start at->  c  a  f  f  e  e  b  a  b  e 
	//i will be the value of the symbol in position 0
	int 	i;

	i = 0;
	//🎩 Recursion magic 🎩
	//BASE CASE
   	if (!position)
	{
		//Search the match symbol 
		while (*nbr != *(symbols + i))
			++i;
		return i * sign;
	}

	//RECURSIVE CASE
	else 
	{
		while (*nbr != *(symbols + i))
			++i;	

		//😅👀🎩 WTF crazy Recursion herei													 //👀 position here
		return realValue(nbr + 1, symbols, baseValue, position - 1, sign) + (i * ft_pow(baseValue, position) * sign);
	}
}









//👊🏻 Helper functions 👊🏻

int 	symbol_set(char c, char *symbols)
{
	//Search for a specific char in a symbol set
	while ((c != *symbols) && *symbols)
		symbols++;
	//Char is not in setSymbols
	if (! *symbols)
		return 0;
	//Char is in set
	return 1;
}









int		ft_pow(int base, int pow)
{
	//Recursion Power
	if (0 == pow)
		return 1;
	else 
		return ft_pow(base, pow - 1) * base;
}	






int 	twiceChar(char *symbols)
{
	int		i;
	int		j;

	i = 0;
	//Iteratively search for a double char
	//Same idea print_comb-> ~https://youtu.be/qshq8KnmWx8
	while (*(symbols + i))
	{
		j = i + 1;
		while (*(symbols + j))
		{
			if (*(symbols + i) == *(symbols + j))
				return 1;
			++j;
		}
		++i;
	}
	return 0;
}




int		ft_isspace(char *str)
{
	if ((*str >= 9 && *str <= 13) || *str == 32)
		return 1;
	else 
		return 0;
}
