/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:35:24 by mrabat            #+#    #+#             */
/*   Updated: 2023/09/13 17:22:04 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ptr;

	if (!(s1) || !(s2))
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(*ptr) * ((len_s2 + len_s1) + 1));
	if (!(ptr))
		return (NULL);
	ft_memcpy(ptr, s1, len_s1);
	ft_memcpy(ptr + len_s1, s2, len_s2 + 1);
	return ((char *)ptr);
}
