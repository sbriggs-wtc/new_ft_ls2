/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:53:00 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/20 14:11:41 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_args(char **argv, t_options *p_options, t_files **p_head)
{
	int			i;
	t_options	*options;
	t_files		*head;

	options = p_options;
	head = *p_head;
	i = 1;
	while (*(argv + i))
	{
		if (*(*(argv + i) + 0) == '-')
			ft_opt_set(options, &head, *(argv + i));
		else if (*(*(argv + i) + 0) != '-')
			ft_files_set(options, &head, *(argv + i));
		i++;
	}
}
