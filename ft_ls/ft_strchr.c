/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 11:21:53 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/16 13:23:44 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str_in;

	str_in = (char *)s;
	i = 0;
	while (str_in[i] != '\0')
	{
		if (c == str_in[i])
		{
			return (&str_in[i]);
		}
		else
		{
			i++;
		}
	}
	if (c == '\0')
	{
		return (&str_in[i]);
	}
	return (NULL);
}
