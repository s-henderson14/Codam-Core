#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i] != '\0')
                i++;
        return (i);
}

char    *ft_strchr(const char *s, int c)
{
        while (*s != '\0')
        {
                if (*s == (char) c)
                        return ((char *)s);
                s++;
        }
        if (*s == '\0' && (char) c == '\0')
                return ((char *) s);
        else
                return (0);
}

char	*get_line(char *string, int c)
{	
	size_t	line_len;
	size_t		i;
	char	*line;

	i = 0;
	line_len = 0;
	if (strchr(string, '\n'))
		line_len = (int)ft_strlen(string) - (int)strlen(strchr(string, c));
	line = malloc(sizeof(char) * line_len + 2);
	if (!line)
		return(free(line), NULL);
	line[line_len] = '\0';
	line[line_len - 1] = '\n';
	while (line && string && i < line_len)
	{	
		line[i] = string[i];
		i++;
	}
	return (line);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*buff;
	int		tot;
	int	len1;
	int	len2;

	len1 = (int)ft_strlen(s1);
	len2 = (int)ft_strlen(s2);
	buff = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!buff)
		return (free(buff), NULL);
	tot = len1 + len2;
	memmove(buff, s1, len1);
	memmove(buff + len1, s2, len2);
	buff[tot] = '\0';
	return (free(s1),buff);
}

char *reader(int fd, int readsize)
{	
	char		buf[readsize + 1];
	int		bytes_read;
	char	*line;
	char	*tmp;
	char	*txt;
	
	txt = "\0";
	bytes_read = 1;
	while (bytes_read >= 1)
	{	
		bytes_read = read(fd, buf, readsize);
		if (bytes_read == -1)
			break ;
		buf[bytes_read] = '\0';
		tmp = ft_strjoin(buf, txt);
		if (!tmp)	
			return(free(tmp), NULL);
		line = tmp;
		if (bytes_read == 0)
			return (line);
	}
	return (NULL);
	
}

int	main()
{
	int	fd;
	
	fd = open("dhumma.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	printf("%s", reader(fd, BUFFER_SIZE ));
}