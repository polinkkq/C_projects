#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	int fd = creat("newfile.txt", 0644);
	if (fd == -1) {
		perror("open");
		return 1;
	}
	const char *string = "Hello from Ubuntu";
	write(fd, string, strlen(string));
}
