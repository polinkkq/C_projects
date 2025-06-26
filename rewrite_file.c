#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	int fd = open("example.txt", O_WRONLY | O_TRUNC);
	if (fd == -1) {
		perror("open");
		return 1;
	}
	
	const char *text = "New file content\n";
	write(fd, text, strlen(text));
	close(fd);
	return 0;
}
