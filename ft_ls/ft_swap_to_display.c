/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_to_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:18:07 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/17 10:18:37 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap_to_display(t_files *temp1, t_files *temp2)
{
	int		temp_store;

	temp_store = temp2->to_display;
	temp2->to_display = temp1->to_display;
	temp1->to_display = temp_store;
}
