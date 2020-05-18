/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:40:30 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/16 14:41:08 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_options_zero(t_options *options)
{
	options->file_name_switch = 0;
	options->error_file_name = 0;
	options->disp_hidden = 0;
	options->list_long = 0;
	options->reverse = 0;
	options->error_option = 0;
}
