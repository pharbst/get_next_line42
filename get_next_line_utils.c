/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:17:38 by pharbst           #+#    #+#             */
/*   Updated: 2022/06/13 22:33:44 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*ft_strchr(char *str, int ch)
{
	if (!str)
		return (NULL);
	while (*str != ((unsigned char)ch))
		if (*str++ == '\0')
			return (NULL);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	strlen;

	strlen = 0;
	while (*s != '\0')
	{
		strlen++;
		s++;
	}
	return (strlen);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n > 0 && (dest || src))
	{
		n--;
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return (dest);
}

char	*ft_strdup(const char *src)
{
	size_t	n;
	char	*dest;

	n = ft_strlen(src) + 1;
	dest = (char *)malloc(n * sizeof(char));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, src, n);
	return (dest);
}

char	*ft_strjoinfree(char *str1, char *str2)
{
	size_t	len1;
	size_t	len2;
	char	*dest;

	if (!str1)
	{
		str1 = (char *)malloc(1 * sizeof(char));
		if (!str1)
			return (NULL);
		*str1 = '\0';
	}
	if (!str2)
		return (str1);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	dest = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, str1, (len1 + 1));
	ft_memcpy((dest + len1), str2, (len2 + 1));
	free(str1);
	return (dest);
}
