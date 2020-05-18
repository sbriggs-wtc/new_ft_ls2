/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:29:16 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/20 15:20:25 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_ls(t_files **pointer_to_head, t_options **p_options)
{
	t_files		*temp;

	temp = *pointer_to_head;
	while (temp)
	{
		if (temp->to_display == 1)
		{
			ft_print_elem(&temp, p_options);
		}
		if (temp->to_display == 2)
		{
			if (temp->permissions[0] == 'd')
				ft_read_print_dir(temp->file_name, p_options);
			else
				ft_print_elem(&temp, p_options);
		}
		temp = temp->next;
	}
}
