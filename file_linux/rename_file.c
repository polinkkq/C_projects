#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
	int fd = open("example.txt", O_CREAT | O_WRONLY, 0644);
	if (fd == -1) {
		perror("open");
		return 1;
	}
	
	if (rename("example.txt", "newname.txt") == -1) {
		perror("rename");
		return 1;
	}
	
	return 0;
}
