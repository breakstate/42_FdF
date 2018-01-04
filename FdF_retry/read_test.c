#include <fcntl.h>
#include "libft/includes/libft.h"

ft_isgoodlen()
//checks if every subsequent line is equal to or longer than the first

ft_usage()
//checks if file exists, correct number of params are used

ft_readin()
//allocates memory internally
//reads entire file into internally allocated memory
//might have to split this one

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	ft_putstr("1\n");
	while (get_next_line(fd, &line) > 0)
		ft_putendl(line);
	ft_putstr("2\n");
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		ft_putendl(line);
	return (0);
}
