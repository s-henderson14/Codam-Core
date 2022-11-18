#include <unistd.h>
#include <stdio.h> //testing
		   //
void	ft_putstr_fd(char *s, int fd);

void	ft_putstr_fd(char *s, int fd)
{
        while (*s != '\0')
        {
                write(fd, s, 1);
                s++;
        }
}

