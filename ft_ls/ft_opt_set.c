/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:42:51 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/20 14:10:38 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_opt_set(t_options *options, t_files **pointer_to_head, char *s)
{
	int		j;

	j = 0;
	while (*(s + j))
	{
		if (ft_strchr(OPTIONS, *(s + j)))
		{
			if (*(s + j) == 'a')
				options->disp_hidden = 1;
			if (*(s + j) == 'l')
				options->list_long = 1;
			if (*(s + j) == 'r')
				options->reverse = 1;
			if (*(s + j) == 't')
				options->time = 1;
		}
		else
		{
			options->error_option = 1;
			ft_print_error_option(*(s + j));
			return (-1);
		}
		j++;
	}
	return (ft_files_pars_opt(&options, pointer_to_head));
}
