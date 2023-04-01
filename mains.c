// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;

// 	fd1 = open("tests/test.txt", O_RDONLY);
// 	fd2 = open("tests/test2.txt", O_RDONLY);
// 	fd3 = open("tests/test3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		if (!line)
// 			printf("line [%d]: %s\n", i, line);
// 		else
// 			printf("line [%d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		if (!line)
// 			printf("line [%d]: %s\n", i, line);
// 		else
// 			printf("line [%d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		if (!line)
// 			printf("line [%d]: %s\n", i, line);
// 		else
// 			printf("line [%d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }

// int	main(void)
// {
// 	int		fd;
// 	char	*toread;
// 	int		i;
// 	// char	buf[210];

// 	fd = open("tests/test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Failed to open file\n");
// 		return (1);
// 	}
// 	// i = read(fd, buf, BUFFER_SIZE);
// 	// buf[BUFFER_SIZE] = '\0';
// 	// printf("%s", buf);
// 	i = 0;
// 	while (i < 12)
// 	{
// 		toread = get_next_line(fd);
// 		printf("%d: %s", i, toread);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
