/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:20:35 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/20 15:26:04 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_free_list(t_files **p_head)
{
	t_files		*temp1;
	t_files		*temp2;

	temp1 = *p_head;
	while (temp1)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		ft_strdel(&temp2->permissions);
        /* ft_strdel(&temp2->owner);
        ft_strdel(&temp2->group); */
        ft_strdel(&temp2->file_name);
/*         free(temp2->permissions);
        free(temp2->owner);
        free(temp2->group);
        free(temp2->file_name); */
		free(temp2);
	}
}
