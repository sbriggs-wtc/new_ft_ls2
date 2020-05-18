/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_parse_options.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:26:57 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/18 14:09:18 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_parse_opt(t_options *options, t_files **pointer_to_head)
{
	if (options->error_option == 0 && options->error_file_name == 0)
	{
		if (options->reverse == 1)
		{
			ft_print_ls_rev(pointer_to_head, &options);
		}
		else
			ft_print_ls(pointer_to_head, &options);
	}
}
