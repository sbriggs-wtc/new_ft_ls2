/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:18:11 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/16 13:24:32 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strdup(const char *s1)
{
	char	*pointer_to_char;
	int		len;
	int		i;

	len = ft_strlen(s1);
	pointer_to_char = (char *)malloc((len + 1) * sizeof(char));
	if (!pointer_to_char)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		pointer_to_char[i] = s1[i];
		i++;
	}
	pointer_to_char[i] = '\0';
	return (pointer_to_char);
}
