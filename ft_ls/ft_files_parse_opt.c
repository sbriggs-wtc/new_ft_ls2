/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_parse_options.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:44:30 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/20 14:10:51 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_files_pars_opt(t_options **p_options, t_files **p_head)
{
	t_options	*options;

	options = *p_options;
	if (options->disp_hidden == 1)
		ft_files_set_hidden(p_head, DISPLAY);
	if (options->time == 1)
		ft_sort_list_time(p_head);
	return (0);
}
