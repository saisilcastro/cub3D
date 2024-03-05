/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:47:27 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/05 12:49:23 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

extern int		ft_isalpha(int arg);
extern int		ft_isdigit(int arg);
extern int		ft_isalnum(int arg);
extern int		ft_isascii(int arg);
extern int		ft_isprint(int arg);
extern int		ft_strlen(const char *str);
extern void		*ft_memset(void *str, int c, size_t n);
extern void		ft_bzero(void *s, size_t n);
extern void		*ft_memcpy(void *dest, const void *src, size_t n);
extern void		*ft_memmove(void *dest, const void *src, size_t n);
extern size_t	ft_strlcpy(char *dest, const char *src, size_t n);
extern size_t	ft_strlcat(char	*dest, const char *src, size_t n);
extern int		ft_toupper(int arg);
extern int		ft_tolower(int arg);
extern char		*ft_strchr(const char *str, int c);
extern char		*ft_strrchr(const char *str, int c);
extern int		ft_strncmp(const char *s1, const char *s2, size_t n);
extern void		*ft_memchr(const void *str, int c, size_t n);
extern int		ft_memcmp(const void *m1, const void *m2, size_t n);
extern char		*ft_strnstr(const char *big, const char *little, size_t n);
extern int		ft_atoi(const char *str);
extern void		*ft_calloc(size_t len, size_t size);
extern char		*ft_strdup(char *src);

extern void		*ft_memalloc(size_t size);
extern void		ft_memdel(void **ap);
extern char		*ft_strnew(size_t size);
extern void		ft_strdel(char **as);
extern void		ft_strclr(char *s);
extern void		ft_striter(char *s, void (*f)(char *));
extern void		ft_striteri(char *s, void (*f)(unsigned int, char *));
extern char		*ft_strmap(char const *s, char (*f)(char));
extern char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
extern int		ft_strequ(char const *s1, char const *s2);
extern int		ft_strnequ(char const *s1, char const *s2, size_t n);
// Allocates (with malloc(3)) and returns a substring from the string ’s’. The
// substring begins at index ’start’ and is of maximum size ’len’
extern char		*ft_substr(char const *s, size_t start, size_t len);
// Allocates (with malloc(3)) and returns a new string, which is the result of
// the concatenation of ’s1’ and ’s2’
extern char		*ft_strjoin(char const *s1, char const *s2);
// Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
// specified in ’set’ removed from the beginning and the end of the string.
extern char		*ft_strtrim(char const *s, const char *set);
// Allocates (with malloc(3)) and returns an array of strings obtained by
// splitting ’s’ using the character ’c’ as a delimiter. The array must end with
// a NULL pointer.
extern char		**ft_split(char const *s, char c);
// Allocates (with malloc(3)) and returns a string representing the integer
// received as an argument. Negative numbers must be handled.
extern char		*ft_itoa(int n);
extern void		ft_putchar(char c);
extern void		ft_putstr(char *str);
extern void		ft_putendl(char const *s);
extern void		ft_putnbr(int n);
extern void		ft_putchar_fd(char c, int fd);
extern void		ft_putstr_fd(char const *s, int fd);
extern void		ft_putendl_fd(char const *s, int fd);
extern void		ft_putnbr_fd(int n, int fd);

extern int		ft_itoa_base(int nb, unsigned char base);
extern int		ft_printf(const char *buffer, ...);

struct					s_list
{
	void				*content;
	struct s_list		*next;
};
typedef struct s_list	t_list;

extern t_list	*ft_lstnew(void *content);
extern void		ft_lstadd_front(t_list **lst, t_list *new);
extern void		ft_lstadd_back(t_list **lst, t_list *new);
extern int		ft_lstsize(t_list *lst);
extern t_list	*ft_lstlast(t_list *lst);
extern void		ft_lstdelone(t_list *alst, void (*del)(void *));
extern void		ft_lstclear(t_list **lst, void (*del)(void *));
extern void		ft_lstadd(t_list **alst, t_list *set);
extern void		ft_lstiter(t_list *lst, void (*f)(void *elem));
extern t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif // LIBFT_H
