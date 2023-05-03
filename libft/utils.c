/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaldas <acaldas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:58:47 by acaldas           #+#    #+#             */
/*   Updated: 2023/04/25 19:58:50 by acaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	dexs(unsigned long decimalnum, int i, int cpyresult)
{
	unsigned long	result;
	unsigned long	rest;
	char			*hexadecimal;

	result = decimalnum;
	if (decimalnum == 0)
		return (ft_putchar('0'));
	while (decimalnum != 0 && i++ > -1)
		decimalnum = decimalnum / 16;
	hexadecimal = malloc(sizeof(char) * i + 1);
	hexadecimal[i--] = '\0';
	while (result != 0)
	{
		rest = result % 16;
		if (rest < 10)
			hexadecimal[i] = (48 + rest);
		else
			hexadecimal[i] = (87 + rest);
		result = result / 16;
		i--;
	}
	cpyresult = ft_putstr(hexadecimal);
	free(hexadecimal);
	return (cpyresult);
}

int	dex(unsigned long decimalnum, int i, int cpyresult)
{
	unsigned long	result;
	unsigned long	rest;
	char			*hexadecimal;

	result = decimalnum;
	if (decimalnum == 0)
		return (ft_putchar('0'));
	while (decimalnum != 0 && i++ > -1)
		decimalnum = decimalnum / 16;
	hexadecimal = malloc(sizeof(char) * i + 1);
	hexadecimal[i--] = '\0';
	while (result != 0)
	{
		rest = result % 16;
		if (rest < 10)
			hexadecimal[i] = (48 + rest);
		else
			hexadecimal[i] = (55 + rest);
		result = result / 16;
		i--;
	}
	cpyresult = ft_putstr(hexadecimal);
	free(hexadecimal);
	return (cpyresult);
}

int	pointer(unsigned long ptr)
{
	int	ret;

	if (!ptr)
		return (ft_putstr("(nil)"));
	ret = ft_putstr("0x");
	ret += dexs(ptr, 0, 0);
	return (ret);
}

int	ft_putnbr(int n)
{
	int	ret;

	ret = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		ret += ft_putchar('-');
		n = -n;
	}
	if (n < 10)
	{
		ret += ft_putchar(n + 48);
		return (ret);
	}
	else
	{
		ret += ft_putnbr(n / 10);
		ret += ft_putnbr(n % 10);
	}
	return (ret);
}
