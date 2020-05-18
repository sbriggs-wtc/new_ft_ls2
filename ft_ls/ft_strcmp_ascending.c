/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_ascending.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:40:45 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/17 16:27:07 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp_ascending(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
	{
		i++;
	}
	if (((unsigned char)s1[i] - (unsigned char)s2[i]) > 0)
	{
		return (1);
	}
	else
		return (0);
}
