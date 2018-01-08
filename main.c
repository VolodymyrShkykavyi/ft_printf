/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 22:25:00 by vshkykav          #+#    #+#             */
/*   Updated: 2017/12/06 22:25:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#include <wchar.h>
#include "includes/libft.h"
#include <locale.h>

void	format_o(t_specinfo *info, int *len, va_list *args);

int	main()
{
	setlocale(LC_ALL, "en_US.UTF-8");

	char happy[] = { 0xd8, 0xa8 };  /* U+263A */
	wchar_t *wc = L"_ঋ_";
	unsigned int res;

	//ft_putwstr(wc);
	int i = 123;

	printf("__%#10.6u__\n", 1245);
	//write(1, &happy, 2);
	/*res = 0xc2;
	write(1, &(res), 1);
	res = 0xa9;
	write(1, &(res), 1);
*/
	//res = (value) >> 16;
	//write(1, (char *)(value), 1);
	//printf("res:%5.*s\n", 2, "_str_", 10);
//	printf("res: %i\nprintf: %X\n", ft_putwchar(wc), wc);
	/*write(1, value, 2);
	printf("\n");
	write(1, value, 3);
	printf("\n");
	write(1, value, 4);
	printf("\n");*/
	//ft_printf("asdad\n%7.56s\ndd\n");
	//ft_printf("test%#  +-10mxmkin", 111);
	//ft_printf("\ntest:%.3s:test\n", NULL);
	//int c = 5;
	//va_list ap;
	//printf("%i\n", sizeof(value));
	//printf("\norig %-05c_end");
	//ft_printf("\ntest:%s:test\n", "。");
}
/*
//assumes little endian
void printBits(size_t const size, void const * const ptr)
{
	unsigned char *b = (unsigned char*) ptr;
	unsigned char byte;
	int i, j;

	for (i=size-1;i>=0;i--)
	{
		for (j=7;j>=0;j--)
		{
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
		printf("\t");
	}
	puts("");
}

int main(int argv, char* argc[])
{
	int i = 23;
	wchar_t ui = L'。';
	float f = 23.45f;
	printBits(sizeof(i), &i);
	printBits(sizeof(ui), &ui);
	printBits(sizeof(f), &f);
	return 0;
}*/