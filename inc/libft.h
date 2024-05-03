/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:22:18 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 15:12:48 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdint.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <stdio.h>

// LIBFT

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp( const void *s1, const void *s2, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strnstr(const char *big,	const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// PRINTF
int		ft_printf(const char *c, ...);
int		ft_getformat(va_list args, const char form);
int		ft_putstr(char *str);
int		ft_putptr(unsigned long long ptr);
int		ft_putnbr(int n);
int		ft_put_unsigned(unsigned int u);
int		ft_put_hex(unsigned int hex, const char format);
int		ft_put_pourcent(void);
int		ft_putchar(char c);
void	ft_print_ptr(uintptr_t num);
char	*ft_uitoa(unsigned int u);
void	ft_print_hex(unsigned int num, const char format);
int		ft_hex_len(unsigned int num);
int		ft_ptr_len(uintptr_t num);
void	ft_printstr(char *str);

// GNL
char	*get_next_line(int fd);
int		read_to_buf(int fd, char **res, char *buf);
char	*finish_line(char *res, char *buf, size_t *start, size_t *len);
int		add_buf_to_res(char **res, char *buf, size_t *start, size_t *len);
char	*append_line(char *old_res, char *buf, size_t start, size_t len);
size_t	find_newline(char *buf, size_t start_index);
size_t	ft_strlen(const char *s);
int		init_res(char **res);

#endif