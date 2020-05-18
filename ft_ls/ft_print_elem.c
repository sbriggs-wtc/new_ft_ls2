/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_elem_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:56:54 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/19 10:54:32 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_elem(t_files **p_file, t_options **p_options)
{
	t_files		*temp;
	t_options	*options;

	temp = *p_file;
	options = *p_options;
	if (options->list_long == 1)
	{
		ft_putstr(temp->permissions);
		ft_putstr("  ");
		ft_putnbr(temp->links);
		ft_putstr("\t");
		ft_putstr(temp->owner);
		ft_putstr(" ");
		ft_putstr(temp->group);
		ft_putstr("  ");
		ft_putnbr(temp->size);
		ft_putstr("\t");
		ft_puttime(ctime(&temp->time_last_mod));
		ft_putstr(" ");
	}
	ft_putstr(temp->file_name);
	ft_putstr("\n");
}
