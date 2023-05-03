/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaldas <acaldas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:56:21 by acaldas           #+#    #+#             */
/*   Updated: 2023/04/25 19:56:22 by acaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = 0;
	p = (char *)s1;
	if (ft_strlen(s2) == 0 || s1 == s2)
		return (p);
	while (p[i] != '\0' && i < len)
	{
		j = 0;
		while (p[i + j] != '\0' && s2[j] != '\0'
			&& p[i + j] == s2[j] && i + j < len)
			j++;
		if (j == ft_strlen(s2))
			return (p + i);
		i++;
	}
	return (0);
}
