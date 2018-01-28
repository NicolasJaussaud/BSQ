/*
** EPITECH PROJECT, 2017
** key
** File description:
** read&save file 
*/

#include "./include/my.h"

char	*get_file(char *path)
{
	char *file = NULL;
	struct stat buf;
	int fd;
	int ret = 0;

	stat(path, &buf);
	file = malloc(sizeof(char) * buf.st_size);
	if ((fd = open(path, O_RDONLY)) == -1)
		exit(84);
	ret = read(fd, file, buf.st_size);
		if (ret == -1)
			exit(84);
	file[ret] = '\0';
	close(fd);
	return (file);
}
