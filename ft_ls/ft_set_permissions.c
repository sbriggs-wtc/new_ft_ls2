/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_permissions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:16:23 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/17 17:49:00 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_set_permissions(t_files **p_head, struct stat **p_buf)
{
	struct stat *buf;
	t_files		*temp;

	buf = *p_buf;
	temp = *p_head;
	*(temp->permissions + 0) = (S_ISDIR(buf->st_mode)) ? 'd' : '-';
	*(temp->permissions + 1) = (buf->st_mode & S_IRUSR) ? 'r' : '-';
	*(temp->permissions + 2) = (buf->st_mode & S_IWUSR) ? 'w' : '-';
	*(temp->permissions + 3) = (buf->st_mode & S_IXUSR) ? 'x' : '-';
	*(temp->permissions + 4) = (buf->st_mode & S_IRGRP) ? 'r' : '-';
	*(temp->permissions + 5) = (buf->st_mode & S_IWGRP) ? 'w' : '-';
	*(temp->permissions + 6) = (buf->st_mode & S_IXGRP) ? 'x' : '-';
	*(temp->permissions + 7) = (buf->st_mode & S_IROTH) ? 'r' : '-';
	*(temp->permissions + 8) = (buf->st_mode & S_IWOTH) ? 'w' : '-';
	*(temp->permissions + 9) = (buf->st_mode & S_IXOTH) ? 'x' : '-';
	*(temp->permissions + 10) = '\0';
}
