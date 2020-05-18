/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_print_directory.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:40:37 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/20 14:17:01 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_read_print_dir(char *dir_name, t_options **p_options)
{
	DIR				*dirp;
	struct dirent	*sd;
	t_files			*head;
	t_options		*options;
	char			*x;

	options = *p_options;
	head = NULL;
	dirp = opendir(dir_name);
	while ((sd = readdir(dirp)))
	{
		ft_add_link_end(&head, sd->d_name);
	}
	closedir(dirp);
	ft_sort_list(&head);
	ft_files_set_hidden(&head, HIDE);
	x = ft_strjoin("./", dir_name);
	ft_files_stat(x, &head);
	if (options->disp_hidden == 1)
		ft_files_set_hidden(&head, DISPLAY);
	if (options->time == 1)
		ft_sort_list_time(&head);
	ft_putstr("\n");
	ft_putstr(dir_name);
	ft_print_list(&head, p_options);
	ft_free_list(&head);
	free(x);
}
