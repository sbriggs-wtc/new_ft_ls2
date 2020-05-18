/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:16:50 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/19 11:40:01 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_ls_rev(t_files **pointer_to_head, t_options **p_options)
{
	t_files		*temp;
	t_options	*options;

	options = *p_options;
	temp = *pointer_to_head;
	if (temp->next && options->reverse == 1)
		ft_print_ls_rev(&temp->next, p_options);
	if (temp->to_display)
	{
		if (temp->to_display == 1)
			ft_print_elem(&temp, p_options);
		if (temp->to_display == 2)
		{
			if (temp->permissions[0] == 'd')
				ft_read_print_dir(temp->file_name, p_options);
			else
				ft_print_elem(&temp, p_options);
		}
	}
}
