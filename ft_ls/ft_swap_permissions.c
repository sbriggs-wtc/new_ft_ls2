/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_permissions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:19:56 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/17 10:20:17 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap_permissions(t_files *temp1, t_files *temp2)
{
	char		*temp_store;

	temp_store = temp2->permissions;
	temp2->permissions = temp1->permissions;
	temp1->permissions = temp_store;
}
