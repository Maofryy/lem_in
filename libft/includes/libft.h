/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:05:59 by mbenhass          #+#    #+#             */
/*   Updated: 2019/09/16 11:01:06 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "ft_printf.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 4096
# define TRUE 1

typedef	struct	s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}				t_list;

typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
long int	ft_atol(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
char			*ft_strtoupper(char *s);
int				ft_tolower(int c);
char			*ft_strtolower(char *s);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lst_pop(t_list **s);
t_list			*ft_lst_pop_tail(t_list **s);
void			ft_lst_push(t_list **alst, t_list *new);
void			ft_lst_push_tail(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_lst_size(t_list *s);
void			ft_sort_integer_list(int *tab, int size);
long int		ft_power(long int nb, int power);
double			ft_dpower(double nb, int power);
int				ft_sqrt(int nb);
int				ft_find_next_prime(int nb);
char			*ft_strcapitalize(char *str);
char			*ft_strjoinfree(char *s1, char *s2, int n);
int				get_next_line(const int fd, char **line);
char			*ft_strnjoinfree(char *s1, char *s2, size_t n);
char			*ft_itoa(int n);
char			*ft_itoa_base(int n, int base);
char			*ft_itoa_majbase(int n, int base);
char			*ft_lltoa(long long int n);
char			*ft_lltoa_base(long long int n, int base);
char			*ft_ulltoa_base(unsigned long long int n, int base);
char			*ft_ulltoa_majbase(unsigned long long int n, int base);
char			*ft_ulltoa(unsigned long long int n);
void 			ft_reverse_str(char *str, int len);
int       		ft_min(int a, int b);
int       		ft_max(int a, int b);
int	    		ft_abs(int n);
int				ft_isnum(char *str);
size_t			count_words(char *str, char c);
t_stack			*ft_stack_new(int const data);
void			ft_stack_push_tail(t_stack **s, int new_data);
long int		ft_stack_pop_tail(t_stack **s);
long int		ft_stack_pop(t_stack **s);
void			ft_stack_push(t_stack **s, int new_data);
t_stack			*ft_stack_copy(t_stack *s);
int				ft_stack_size(t_stack *s);
void			ft_stack_del(t_stack **s);
void			ft_stack_print(t_stack *s);
int				ft_stack_contains(t_stack *s, int n);
void			ft_stack_print_labels(t_stack *s, char **labels);
void 			ft_stack_reverse(t_stack **s);

#endif
