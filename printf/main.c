/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:21:02 by maborges          #+#    #+#             */
/*   Updated: 2025/01/27 17:41:57 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"
#include <limits.h>

int	main(void)
{
	/* int	output = -1;
	ft_printf("Hello, World!\n");
	ft_printf("Number: %d\n", 42);
	ft_printf("Char: %c\n", 'A');
	ft_printf("String: %s\n", "Test String");
	ft_printf("Percent: %%\n");

	ft_printf("Null string: %s\n", NULL);
	ft_printf("Null pointer: %p\n", NULL);
	ft_printf(" %d \n", -1);
	//output = ft_printf("%u\n", 429496729);
	//printf("%d chars printed from ft_printf\n", output);

	printf("Null string: %s\n", (char *)NULL);
	printf("Null pointer: %p\n", NULL);
	printf(" %d \n", -1);
	//output = printf("%u\n", 429496729);
	//printf("%d chars printed from printf\n", output);

	ft_printf("Hex (lowercase): %x\n", 255);
	ft_printf("Hex (uppercase): %X\n", 255);
	ft_printf("Pointer: %p\n", &output);

	printf("Hex (lowercase): %x\n", 255);
	printf("Hex (uppercase): %X\n", 255);
	printf("Pointer: %p\n", &output); */

	printf("===FT_PRINTF TEST RESULT===\n");
	ft_printf("some thing %x \n", 0);
	//ft_printf(" %p %p \n", 0, 0);
	ft_printf("%p\n", NULL);
	//ft_printf("%pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	ft_printf("\001\002\007\v\010\f\r\n");
	ft_printf("%x\n", -10);
	ft_printf("%x\n", 0);
	ft_printf("%x\n", 4294967295U);
	ft_printf("%x\n", 10000);
	ft_printf(" %p %p ", 0, 0);

	printf("===FT_PRINTF TEST RESULT===\n");
	printf("some thing %x \n", 0);
	//printf(" %p %p \n", 0, 0);
	printf("%p\n", NULL);
	//printf("%pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	printf("\001\002\007\v\010\f\r\n");
	printf("%x\n", -10);
	printf("%x\n", 0);
	printf("%x\n", 4294967295U);
	printf("%x\n", 10000);
	printf(" %p %p ", 0, 0);




	return (0);
}
