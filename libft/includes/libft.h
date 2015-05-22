/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggozlan <ggozlan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 17:38:00 by ggozlan           #+#    #+#             */
/*   Updated: 2014/06/10 14:29:34 by btournoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "libft_struct.h"
# include "get_next_line.h"

# define BUFF_SIZE 32
# define UNINT unsigned int

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_putstr(char const *c);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putnbr_uint(unsigned int n);
void	ft_putnbr_double(double n);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
void	ft_putendl(char const *c);
void	ft_putstr_fd(char const *c, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char const *c, int fd);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
int		ft_stronlydigit(char *str);
int		ft_strsignanddigit(char *str);
char	**ft_strsplit(char const *s, char c);
char	**ft_strsplitslash(char const *s, char c);
char	*ft_itoa(int n);
int		ft_verif_occurence(const char *s, int c, int occur);

t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstnextadd(t_list **alst, t_list *new);
void	ft_lstendadd(t_list **alst, t_list *new);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void	ft_delnodecontent(void *content, size_t content_size);
void	ft_putlst(t_list *lst);
void	ft_putlstsize(t_list *lst);
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char	**ft_tabcpy(char **tab, char **tab2);
char	**ft_tabnew(size_t size);
size_t	ft_tablen(char **tab);
void	ft_puttab(char **tab);
char	**ft_tabdup(char **tab);
void	ft_tabdel(char **tab);
char	**ft_tabncpy(char **tab, char **tab2, int n);
char	**ft_tabdelline(char **tab, int line);
char	*ft_chrset(char *str, int c, int c_r);
char	*ft_strrev(char *str);
int		ft_ismemchr(const void *s, int c, size_t n);
size_t	ft_memchrlen(const void *s, int c, size_t n);
void	*ft_memjoin(void *s1, void const *s2, size_t n1, size_t n2);
char	**ft_strsplit_not_quote(char const *s, char c);
char	**ft_wordsplit(char const *s, char *split);
int		ft_tputchar(int c);
int		ft_hexstrtoi(char *str);
char	*ft_insert_char_in_str(char *s, char c, int pos);
int		ft_isnalpha(char c, int n);
int		ft_strhexa(char *str);
int		ft_ishexa(char c);
int		ft_isstrint(char *str);
double	ft_pow(double x, double y);
long	ft_atob(char *s);
UNINT	ft_atoui(const char *str);
char	*ft_btoa(long x);
long	ft_btoi(long n);
long	ft_itob(long n);
long	ft_itob(long n);
char	*ft_itoa_long(long n);
char	*ft_ctobtoa(long c);
int		ft_abs(int nb);

#endif
