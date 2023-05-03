/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaldas <acaldas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:53:18 by acaldas           #+#    #+#             */
/*   Updated: 2023/04/25 19:53:20 by acaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*pos;
	size_t	tot_size;
	int		fill_byte;

	tot_size = nmemb * size;
	fill_byte = 0;
	if (!nmemb || !size || size > INT_MAX / nmemb)
		return (NULL);
	pos = malloc(tot_size);
	if (!pos)
		return (NULL);
	ft_memset (pos, fill_byte, tot_size);
	return ((void *)pos);
}
