/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_stat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 14:13:47 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/20 15:21:51 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_files_read_stat(char *dir_name, t_files **p_head, char *file_name)
{
	struct stat		*buf;
	t_files			*temp;
	struct passwd	*pwd;
	struct group	*grp;
	char			*file_path;
    char            *file_path2;

	file_path = ft_strjoin(dir_name, "/");
	file_path2 = ft_free_strjoin(file_path, file_name);
	buf = (struct stat *)malloc(sizeof(struct stat));
	temp = *p_head;
	temp->permissions = (char *)malloc(sizeof(char) * 10 + 1);
	lstat(file_path2, buf);
	ft_set_permissions(p_head, &buf);
	temp->links = buf->st_nlink;
	(pwd = getpwuid(buf->st_uid)) != NULL ? (temp->owner = pwd->pw_name) : 0;
	(grp = getgrgid(buf->st_gid)) != NULL ? (temp->group = grp->gr_name) : 0;
	temp->size = buf->st_size;
	temp->time_last_mod = buf->st_mtime;
	ft_strdel(&file_path2);
	free(buf);
}

void	ft_files_stat(char *dir_name, t_files **p_head)
{
	t_files *temp;

	dir_name = ft_strdup(dir_name);
	temp = *p_head;
	while (temp)
	{
		ft_files_read_stat(dir_name, &temp, temp->file_name);
		temp = temp->next;
	}
	free(dir_name);
	free(temp);
}
