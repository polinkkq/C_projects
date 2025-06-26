#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	int fd = open("example.txt", O_RDWR);
	if (fd == -1) {
		perror("open");
		return 1;
	}
	if (lseek(fd, 10, SEEK_SET) < 0){
		perror("lseek");
		close(fd);
		return 1;
	}
	const char *string = "HELLO";
	write(fd, string, strlen(string));
	close(fd);

	return 0;
}
