#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *filename = "lock.txt";
    
    int fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Устанавливаем эксклюзивную блокировку на ВЕСЬ файл
    struct flock lock = {
        .l_type = F_WRLCK,     // Блокировка на запись (эксклюзивная)
        .l_whence = SEEK_SET,  // Отсчёт от начала файла
        .l_start = 0,          // Начало блокировки
        .l_len = 0             // 0 = блокируем до конца файла
    };


    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl lock");
        close(fd);
        return 1;
    }
    return 0;
}
