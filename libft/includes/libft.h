/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:27:25 by ngrasset          #+#    #+#             */
/*   Updated: 2018/05/02 10:50:27 by ngrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# define FT_C_RED "31m"
# define FT_C_BLUE "34m"
# define FT_C_GREEN "32m"
# define FT_C_YELLOW "33m"
# define FT_C_MAGENTA "35m"
# define FT_C_CYAN "36m"
# define FT_C_WHITE "37m"
# define FT_C_RESET "\x1B[0m"
# define LIBFT_BUFF_SIZE 100
# define LIBFT_MAX_FD 255

/*
** Linked lists
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstpop(t_list **head);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstpush_back(t_list **alst, t_list *new);
void				ft_lstsort(t_list *lst, int (*f)(t_list *a, t_list *b));

/*
** Memory
*/
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_realloc(void *ptr, size_t o_size, size_t n_size);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);

/*
** Number
*/
char				*ft_itoa(int n);
char				*ft_uitoa_base(unsigned long long nbr, int base);
char				*ft_itoa_base(long long nbr, int base);
char				*ft_ltostr(long long n);
int					ft_atoi(const char *str);
float				ft_rand(void);

/*
** Reader
*/
int					ft_getchar(int fd);
int					get_next_line(int const fd, char **line);

/*
** String
*/
char				**ft_strsplit(char const *s, char c);
char				*ft_search_and_replace(char *s, char a, char b);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_delim(char *s1, char *s2, char *delim);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dst, const char *src, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_count_words(char const *s, char c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_str_isalpha(char const *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
void				ft_delstrtab(char **tab);
void				ft_putstrtab(char **tab);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
** Writer
*/
void				ft_print_color(char const *str, char const *color,
						int light);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
int					ft_putnchar(char c, int i);

#endif
