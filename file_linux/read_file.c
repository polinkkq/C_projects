#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	int fd = open("example.txt", O_RDONLY);
	if (fd == -1) {
		perror("open");
		return 1;
	}
	
	char buffer[1024];
	ssize_t bytes_read;
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
		write(STDOUT_FILENO, buffer, bytes_read);
	}
	close(fd);
	return 0;
}
