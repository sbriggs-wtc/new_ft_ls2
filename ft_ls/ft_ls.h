/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:23:45 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/20 15:20:52 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

//added some files here but forgot to add them in makefile

#include <stdio.h> //remove this
# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h> //duplicate
# include <pwd.h>
# include <grp.h>
# include <time.h>
# define OPTIONS "-atrRl"
# define HIDE 0
# define DISPLAY 1

typedef struct		s_options
{
	int				error_option;
	int				error_file_name;
	int				file_name_switch;
	int				disp_hidden;
	int				list_long;
	int				time;
	int				reverse;
	int				recursive;
}					t_options;

typedef struct		s_files
{
	int				to_display;
	char			*permissions;
	int				links;
	char			*owner;
	char			*group;
	int				size;
	long			time_last_mod;
	char			*file_name;
	struct s_files	*next;
}					t_files;

int	                ft_strncmp(const char *s1, const char *s2, size_t n);
char	            *ft_strcat(char *s1, const char *s2);
void				ft_putstr(char *s);
void				ft_putchar(char c);
size_t				ft_strlen(const char *s);
int					ft_strcmp_ascending(const char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_putnbr(int n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(const char *s1, const char *s2);
void				ft_print_ls_rev(t_files **p_head, t_options **p_options);
void				ft_read_print_dir(char *dir_name, t_options **p_options);
void				ft_add_link_end(t_files **pointer_to_head, char *s);
void				ft_sort_list(t_files **pointer_to_head);
void				ft_sort_list_time(t_files **pointer_to_head);
void				ft_print_elem(t_files **p_file, t_options **p_options);
void				ft_swap_file_name(t_files *temp1, t_files *temp2);
void				ft_puttime(char *s);
void				ft_files_set_hidden(t_files **p_head, int hide_or_disp);
void				ft_print_list(t_files **p_head, t_options **p_options);
void				ft_files_stat(char *dir_name, t_files **pointer_to_head);
void				ft_set_permissions(t_files **p_head, struct stat **p_buf);
void				ft_print_parse_opt(t_options *options, t_files **p_head);
void				ft_print_ls(t_files **p_head, t_options **p_options);
void				ft_files_set(t_options *option, t_files **p_head, char *s);
void				ft_print_error_file(char *s);
void				ft_print_error_option(char c);
void				ft_options_zero(t_options *options);
int					ft_opt_set(t_options *options, t_files **p_head, char *s);
int					ft_files_pars_opt(t_options **p_options, t_files **p_head);
char				*ft_free_strjoin(char *s1, char *s2);
void				ft_swap_to_display(t_files *temp1, t_files *temp2);
void				ft_swap_permissions(t_files *temp1, t_files *temp2);
void				ft_swap_links(t_files *temp1, t_files *temp2);
void				ft_args(char **argv, t_options *p_opt, t_files **p_head);
void				ft_free_list(t_files **p_head);
void				ft_strdel(char **as);
char				*ft_strcpy(char *dst, char const *src);

#endif
