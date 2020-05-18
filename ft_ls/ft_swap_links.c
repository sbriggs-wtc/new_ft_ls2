/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:20:36 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/17 10:20:53 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap_links(t_files *temp1, t_files *temp2)
{
	int		temp_store;

	temp_store = temp2->links;
	temp2->links = temp1->links;
	temp1->links = temp_store;
}
