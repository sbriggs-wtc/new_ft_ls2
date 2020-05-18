# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 09:53:52 by sbriggs           #+#    #+#              #
#    Updated: 2018/09/20 15:21:08 by sbriggs          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FLAGS += -g -Wall -Werror -Wextra -I./

ATTACH = 

COMPILER = gcc

HEADERS =

DIR_S = ./ 

DIR_O = 

SOURCES = 	ft_strncmp.c \
			ft_strcat.c \
			main.c \
			ft_putstr.c \
			ft_putchar.c \
			ft_strlen.c \
			ft_strcmp_ascending.c \
			ft_strchr.c \
			ft_putnbr.c \
			ft_strcmp.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_print_ls_rev.c \
			ft_read_print_dir.c \
			ft_add_link_end.c \
			ft_sort_list.c \
			ft_sort_list_time.c \
			ft_print_elem.c \
			ft_swap_file_name.c \
			ft_puttime.c \
			ft_files_set_hidden.c \
			ft_print_list.c \
			ft_files_stat.c \
			ft_set_permissions.c \
			ft_print_parse_opt.c \
			ft_print_ls.c \
			ft_files_set.c \
			ft_print_error_file.c \
			ft_print_error_option.c \
			ft_options_zero.c \
			ft_opt_set.c \
			ft_files_parse_opt.c \
			ft_free_strjoin.c \
			ft_swap_to_display.c \
			ft_swap_permissions.c \
			ft_swap_links.c \
			ft_args.c \
			ft_free_list.c \
			ft_strdel.c

OBJECTS = $(SOURCES:.c=.o)

%.o:	%.c 
	$(COMPILER) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJECTS)
	$(COMPILER) $(FLAGS) -o $(NAME) $(OBJECTS) $(ATTACH)

all: $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean clean all

run: re
	make clean
	./$(NAME)

.PHONY: re all fclean clean
