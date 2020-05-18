/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:31:59 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/20 15:30:16 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_files_set(t_options *options, t_files **pointer_to_head, char *s)
{
	t_files	*temp;

	options->error_file_name = 1;
	temp = *pointer_to_head;
	while (temp)
	{
		if ((ft_strcmp(temp->file_name, s)) == 0)
		{
			temp->to_display = 2;
			options->error_file_name = 0;
		}
		else
		{
			if (temp->to_display != 2)
				temp->to_display = 0;
		}
		temp = temp->next;
	}
	if (options->error_file_name)
		ft_print_error_file(s);
}
