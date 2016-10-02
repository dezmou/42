#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int 			ft_atoi(const char *str);
int 			ft_strlen(const char *s);
char 			*ft_strdup(const char *s);
char 			*ft_strcpy(char *dest, const char *src);
char 			*ft_strncpy(char *dest, const char *src,size_t n);
char 	 		*ft_strcat(char *dest, const char *src);
char 			*ft_strncat(char *dest, const char *src, size_t n);
char 			*ft_strchr(const char *s, int c);
char 			*ft_strrchr(const char *s, int c);
char 			*ft_strstr(const char *dest, const char *src);
char 			*ft_strnstr(const char *dest, const char *src, size_t n);


#endif