/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:48:49 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/17 17:49:12 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sort_list(t_files **pointer_to_head)
{
	t_files	*temp1;
	t_files	*temp2;

	temp1 = *pointer_to_head;
	temp2 = *pointer_to_head;
	while (temp1)
	{
		while (temp2)
		{
			if (ft_strcmp_ascending(temp1->file_name, temp2->file_name))
				ft_swap_file_name(temp2, temp1);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
		temp2 = temp1;
	}
}
