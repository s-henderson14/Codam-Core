/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: shenders <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 19:50:05 by shenders      #+#    #+#                 */
/*   Updated: 2022/10/18 20:16:36 by shenders      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

int		ft_toupper(int c);

int		ft_tolower(int c);

int		ft_atoi(const char *str);

void	*ft_calloc(size_t count, size_t size);

void	*ft_memset(void *b, int c, size_t len);

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t len);

void	ft_bzero(void *s, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

char	*ft_strnstr(const char *hs, const char *n, size_t len);

char	*ft_strdup(const char *s1);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif