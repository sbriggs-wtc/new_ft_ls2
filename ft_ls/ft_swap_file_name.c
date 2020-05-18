/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_file_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:01:36 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/17 11:59:43 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap_file_name(t_files *temp1, t_files *temp2)
{
	char	*temp_string;

	temp_string = temp2->file_name;
	temp2->file_name = temp1->file_name;
	temp1->file_name = temp_string;
}
