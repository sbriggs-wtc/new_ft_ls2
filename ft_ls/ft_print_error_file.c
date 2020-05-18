/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:34:27 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/17 17:44:03 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_error_file(char *s)
{
	ft_putstr("ls: ");
	ft_putstr(s);
	ft_putstr(": No such file or directory");
	ft_putstr("\n");
}
