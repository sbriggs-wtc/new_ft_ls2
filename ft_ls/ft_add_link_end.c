/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_link_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:45:28 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/17 17:14:34 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_files	*ft_new_link(char *s)
{
	t_files		*new;

	new = (t_files *)malloc(sizeof(t_files));
	new->file_name = s;
	new->next = NULL;
	return (new);
}

void	ft_add_link_end(t_files **pointer_to_head, char *s)
{
	t_files	*temp;
	t_files	*temp2;

	temp = ft_new_link(s);
	if (*pointer_to_head == NULL)
		*pointer_to_head = temp;
	else
	{
		temp2 = *pointer_to_head;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = temp;
	}
}
