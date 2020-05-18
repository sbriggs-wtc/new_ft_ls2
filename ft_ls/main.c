/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:50:26 by sbriggs           #+#    #+#             */
/*   Updated: 2018/09/20 15:30:11 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <string.h>
#include <errno.h>

int is_reg(const char *path)
{
   struct stat statbuf;

   if (stat(path, &statbuf) != 0)
       return 0;
    return S_ISREG(statbuf.st_mode);
}

int is_dir(const char *path)
{
   struct stat statbuf;

   if (stat(path, &statbuf) != 0)
       return 0;
   return S_ISDIR(statbuf.st_mode);
}

void ft_print_and_exit(char *s1, char c)
{
    ft_putstr(s1);
    ft_putstr("");
    ft_putchar(c);
    ft_putstr("\n");
    exit(EXIT_FAILURE);
}

void ft_display_l_row(struct dirent *sd)
{
    char *permissions = (char *)malloc(sizeof(char) * 10 + 1);
    struct stat *buf = (struct stat *)malloc(sizeof(struct stat));

    lstat(sd->d_name, buf);
    if(sd->d_type == DT_DIR)
        permissions[0] = 'd';
    else if(sd->d_type == DT_LNK)
        permissions[0] = 'l';
    else
        permissions[0] = '-';
    permissions[1] = (buf->st_mode & S_IRUSR) ? 'r' : '-';
    permissions[2] = (buf->st_mode & S_IWUSR) ? 'w' : '-';
    permissions[3] = (buf->st_mode & S_IXUSR) ? 'x' : '-';
    permissions[4] = (buf->st_mode & S_IRGRP) ? 'r' : '-';
    permissions[5] = (buf->st_mode & S_IWGRP) ? 'w' : '-';
    permissions[6] = (buf->st_mode & S_IXGRP) ? 'x' : '-';
    permissions[7] = (buf->st_mode & S_IROTH) ? 'r' : '-';
    permissions[8] = (buf->st_mode & S_IWOTH) ? 'w' : '-';
    permissions[9] = (buf->st_mode & S_IXOTH) ? 'x' : '-';
    permissions[10] = '\0';
    ft_putstr("\t");
    ft_putstr(permissions);
    ft_putstr(" ");
    ft_putnbr(buf->st_nlink);
    ft_putstr("\t");
    ft_putstr(getpwuid(buf->st_uid)->pw_name);
    ft_putstr(" ");
    ft_putstr(getgrgid(buf->st_gid)->gr_name);
    ft_putstr(" ");
    ft_putnbr(buf->st_size);
    ft_putstr("\t");
    ft_puttime(ctime(&buf->st_mtime));
    ft_putstr(" ");
    free(buf);
    free(permissions);
}

void ft_put_path(char *path)
{
    ft_putstr("\n");
    ft_putstr(path);
    ft_putstr(" :\n");
}

void print_entries_rec(char *path, char *opts)
{
    char            *path_slash;
    DIR             *dp;
    struct dirent   *sd;
    char            *newdir;

    if(!(dp = opendir(path)))
        ft_print_and_exit("There was a problem opening the directory", ' ');
    ft_put_path(path);
    while((sd = readdir(dp)))
    {
        if(!ft_strchr(opts, 'a'))
        {
            if(ft_strncmp(sd->d_name, ".", 1))
            {
            	if (ft_strchr(opts, 'l'))
                    ft_display_l_row(sd);
                (sd->d_type == DT_LNK && ft_strchr(opts, 'l')) ? ft_putstr(ft_strcat(sd->d_name, " -> ")) : ft_putstr("");
                ft_putstr(ft_strcat(sd->d_name, "\n"));
            }
        }
        else 
        {
            if(ft_strchr(opts, 'l'))
                    ft_display_l_row(sd);

            ft_putstr(sd->d_name);
            if(sd->d_type == DT_LNK && ft_strchr(opts, 'l'))
            {
                ft_putstr(" -> ");
                ft_putstr(sd->d_name);
            }
            ft_putstr("\n");
        }
    }
    closedir(dp);
    dp = opendir(path);
    while((sd = readdir(dp))) 
        if(strncmp(sd->d_name, ".", 1))
            if(ft_strchr(opts, 'R') && sd->d_type == 4)
            {
                path_slash = ft_strjoin(path, "/");
                newdir = ft_strjoin(path_slash, sd->d_name);
                free(path_slash);
                print_entries_rec(newdir, opts);
                free(newdir);
            }
    closedir(dp);
}

int print_entries(char **av, char* opts)
{
    int i = 0;

    while(av[++i])
        if(av[i][0] != '-')
            if(is_dir(av[i]))
                print_entries_rec(av[i], opts);
    return(0);
}

int		main(int ac, char **av)
{
    int dir_count;
    int i;
    int j;
    int k;
    char *opts;

    dir_count = 0;
    k = 0;
    i = 0;
    opts = (char *)malloc(sizeof(char *) * 7);
    while(av[++i])
    {
        if(av[i][0] != '-' && (!is_dir(av[i]) && !is_reg(av[i])))
            ft_print_and_exit("No such file or directory", ' ');
        else if(av[i][0] != '-' && (is_dir(av[i]) || is_reg(av[i])) && ++dir_count)
            dir_count++;
        else if(strlen(av[i]) > 1)
        {
            j = 0;
            while(av[i][++j])
            {
                if(ft_strchr("larRt", av[i][j]))
                {
                    if(!ft_strchr(opts, av[i][j]))
                        opts[k++] = av[i][j];
                }
                else
                    ft_print_and_exit("ls: invalid option ", av[i][j]);
            }
        }
        else
            ft_print_and_exit("flag failed" , ' ');
    }
    if(dir_count == 0 || ac == 1)
    {
        av[1] = ft_strdup("./");
        print_entries( av, opts);
        free(av[1]);
    }
    else
        print_entries(av, opts);
    free(opts);
    return(0);
}





/* perror("opendir"); */
/* printf("directory failed errno: %s\n",strerror(errno)); */
//check ac against buffer
/*     printf("DT_UNKNOWN: %d\n",DT_UNKNOWN);
        printf("DT_REG: %d \n", DT_REG);
        printf("DT_DIR: %d \n", DT_DIR);
        printf("DT_FIFO: %d\n", DT_FIFO);
        printf("DT_SOCK: %d\n", DT_SOCK);
        printf("DT_CHR: %d\n",DT_CHR);
        printf("DT_BLK: %d\n", DT_BLK);
        printf("DT_LNK: %d \n", DT_LNK); */

/*     int n;
    printf("Before sorting the list is: \n");
    for( n = 0 ; n < i; n++ ) {
        printf("%s \n", dir_arr[n]);
    }
    qsort(dir_arr, i, sizeof(char*), cmp_time);
    printf("\nAfter sorting the list is: \n");
    for( n = 0 ; n < i; n++ ) {
        printf("%s --\n", dir_arr[n]);
    }
    i = 0;
    while(dir_arr[i]){
        free(dir_arr[i++]);
    }
    free(dir_arr); */

    /*                             printf("DT_UNKNOWN: %d\n",DT_UNKNOWN);
        printf("DT_REG: %d \n", DT_REG);
        printf("DT_DIR: %d \n", DT_DIR);
        printf("DT_FIFO: %d\n", DT_FIFO);
        printf("DT_SOCK: %d\n", DT_SOCK);
        printf("DT_CHR: %d\n",DT_CHR);
        printf("DT_BLK: %d\n", DT_BLK);
        printf("DT_LNK: %d \n", DT_LNK); */

        /*                         struct stat *sb = (struct stat *)malloc(sizeof(struct stat)); //this is still a bit fuzzy
                        char *linkname;
                        ssize_t r;
                        char *full_path = ft_strdup(sd->d_name);
                            printf("--%s--", full_path);
                        if (lstat(full_path, sb) == -1) {
                            perror("lstat");
                            exit(EXIT_FAILURE);
                        } else {
                            //linkname = malloc(sb->st_size + 1);
                            //linkname = (char *) realloc (linkname, size);
                            linkname = (char *)malloc(sizeof(char *) * sb->st_size + 1);
                            if (linkname == NULL) {
                                fprintf(stderr, "insufficient memory\n");
                                exit(EXIT_FAILURE);
                            }
                            r = readlink(full_path, linkname, sb->st_size + 1);
                            if (r < 0) {
                                perror("lstat");
                                exit(EXIT_FAILURE);
                            }
                            if (r > sb->st_size) {
                                fprintf(stderr, "symlink increased in size between lstat() and readlink()\n");
                                exit(EXIT_FAILURE);
                            }
                            printf("1");

                            linkname[sb->st_size] = '\0';
                            ft_putstr(" -> ");
                            ft_putstr(linkname);
                            free(linkname);
                            free(full_path);
                            free(sb);
                            printf("2");
                        } */

                        /* void remove_element(char **array, int index, int array_length)
{
   int i;
   for(i = index; i < array_length - 1; i++) array[i] = array[i + 1];
} */

/* struct stat get_stats(const char* filename)
{
    char path[1024];
    sprintf(path, "%s/%s", global_dir, filename);
    struct stat sb;

    if (lstat(path, &sb) < 0)
    {   
        perror(path);
        exit(EXIT_FAILURE);
    }

    return sb;
} */
/* static int cmp_time(const void* p1, const void* p2)
{
    const char* str1 = *(const char**)p1;
    const char* str2 = *(const char**)p2;

    time_t time1 = get_stats(str1).st_mtime;
    time_t time2 = get_stats(str2).st_mtime;

    return time1 < time2;
} */
/* 
char *
readlink_malloc (const char *filename)
{
  int size = 100;
  char *buffer = NULL;

  while (1)
    {
      buffer = (char *) realloc (buffer, size);
      int nchars = readlink (filename, buffer, size);
      if (nchars < 0)
        {
          free (buffer);
          return NULL;
        }
      if (nchars < size)
        return buffer;
      size *= 2;
    }
} */

/* int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
} */




/* 
    char** args_arr;
    //args_arr = NULL;
    args_arr = (char**)malloc(sizeof(char*) * ac);

    i = -1;
    while(++i < ac)
        args_arr[i] = ft_strdup(av[i]);

    i = 1;
 */
/*     i = -1;
    while(++i < ac)
    {
        ft_putstr(args_arr[i]);
        ft_putstr("\n");
        free(args_arr[i]);
    } */
    // free(args_arr);


//sd = (struct dirent* )malloc(sizeof(struct dirent* ));
//sprintf(newdir, "%s/%s", path, sd->d_name); 
//newdir = (char *)malloc(sizeof(char *) * 512);
//path = ft_strdup(ft_strcat(path, "/"));

/* if(S_ISDIR(buf->st_mode)) */