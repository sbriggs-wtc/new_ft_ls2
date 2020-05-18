/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 12:39:49 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/20 15:14:19 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_free_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	size_t	size;
	char	*new_string;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(new_string = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
    ft_strdel(&s1);
	j = 0;
	while (s2[j] != '\0')
	{
		new_string[i + j] = s2[j];
		j++;
	}
	new_string[i + j] = '\0';
	return (new_string);
}
