/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:54:05 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/17 17:49:31 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap_time_last_mod(t_files *temp1, t_files *temp2)
{
	long	temp_long;

	temp_long = temp2->time_last_mod;
	temp2->time_last_mod = temp1->time_last_mod;
	temp1->time_last_mod = temp_long;
}

void	ft_swap_size(t_files *temp1, t_files *temp2)
{
	int		temp_store;

	temp_store = temp2->size;
	temp2->size = temp1->size;
	temp1->size = temp_store;
}

void	ft_swap_group(t_files *temp1, t_files *temp2)
{
	char		*temp_store;

	temp_store = temp2->group;
	temp2->group = temp1->group;
	temp1->group = temp_store;
}

void	ft_swap_owner(t_files *temp1, t_files *temp2)
{
	char		*temp_store;

	temp_store = temp2->owner;
	temp2->owner = temp1->owner;
	temp1->owner = temp_store;
}

void	ft_sort_list_time(t_files **pointer_to_head)
{
	t_files	*temp1;
	t_files	*temp2;

	temp1 = *pointer_to_head;
	temp2 = *pointer_to_head;
	while (temp1)
	{
		while (temp2)
		{
			if (temp1->time_last_mod < temp2->time_last_mod)
			{
				ft_swap_to_display(temp2, temp1);
				ft_swap_permissions(temp2, temp1);
				ft_swap_links(temp2, temp1);
				ft_swap_owner(temp2, temp1);
				ft_swap_group(temp2, temp1);
				ft_swap_size(temp2, temp1);
				ft_swap_time_last_mod(temp2, temp1);
				ft_swap_file_name(temp2, temp1);
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
		temp2 = temp1;
	}
}
