/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_set_hidden.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:06:02 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/17 17:43:17 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_files_set_hidden(t_files **pointer_to_head, int hide_or_disp)
{
	t_files		*temp;

	temp = *pointer_to_head;
	while (temp)
	{
		if (*(temp->file_name + 0) == '.')
		{
			temp->to_display = hide_or_disp;
		}
		else
			temp->to_display = 1;
		temp = temp->next;
	}
}
