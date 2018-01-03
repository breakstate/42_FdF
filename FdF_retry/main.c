#include <fcntl.h>
#include "libft/includes/libft.h"

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	//if (argc != 2)
	//	throw error;
	ft_putstr("1\n");
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
	}
	ft_putstr("2\n");
	close(fd);
	fd = open(argv[1], O_RDONLY);	
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
	}
	return (0);
}
