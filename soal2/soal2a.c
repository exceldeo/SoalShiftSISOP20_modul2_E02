#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

int main () {

    pid_t pid, sid;
    pid = fork();   // Menyimpan PID dari child process

    // Keluar saat fork gagal (nilai variabel pid < 0)
    if (pid < 0)
        exit(EXIT_FAILURE);
    
    // Keluar saat fork berhasil (nilai variabel pid adalah PID dari child process)
    if (pid > 0)
        exit(EXIT_SUCCESS);
    
    umask(0);

    sid = setsid();

    if (sid < 0)
        exit(EXIT_FAILURE);
    
    if ((chdir("/")) < 0)
        exit(EXIT_FAILURE);
    
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1) {

        int status;

        time_t t;
        struct  tm *temp;
        char MY_TIME[50];

        time ( &t );
        temp = localtime ( &t );

        // Using strftime to display time
        strftime(MY_TIME, sizeof(MY_TIME), "%Y-%m-%d_%H:%M:%S", temp);

        char path[] = "/home/qqdnada/SoalShiftSISOP20_modul2_E02/soal2/";
        strcat(path, MY_TIME);

        status = mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

        // char *argv[] = {"mkdir", "-p", path, NULL};
        // execv("/bin/mkdir", argv);

        sleep(30);
    }
}