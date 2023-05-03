/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaldas <acaldas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:53:44 by acaldas           #+#    #+#             */
/*   Updated: 2023/04/25 19:53:45 by acaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

// int main()
// {
// 	int number = 51; //aqui tem que sair 1 //
// 	int notnumber = 'a'; // sai 0 
// 	printf("%i\n", ft_isdigit(number));
// 	printf("%i\n", ft_isdigit(notnumber));
// 	return(0);
// }*/