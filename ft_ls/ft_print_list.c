/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:10:05 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/19 11:45:57 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_list(t_files **pointer_to_head, t_options **p_options)
{
	t_files		*temp;
	t_options	*options;

	temp = *pointer_to_head;
	options = *p_options;
	ft_putstr(":");
	ft_putstr("\n");
	if (options->reverse == 1)
	{
		ft_print_ls_rev(pointer_to_head, p_options);
	}
	else
	{
		while (temp)
		{
			if (temp->to_display == 1)
			{
				ft_print_elem(&temp, p_options);
			}
			temp = temp->next;
		}
	}
	ft_putstr("\n");
}
