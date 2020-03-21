#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[]) {

    int cekd = 0 , cekm = 0 , cekj = 0;
    char cekdetik[5]="*";

    for(int i = 59 ; i >= 0 ; --i ){

        if(strcmp(argv[1], cekdetik) == 0 && cekd == 0)
            cekd = 1;

        if(strcmp(argv[2], cekdetik) == 0 && cekm == 0)
            cekm = 1;

        if(strcmp(argv[3], cekdetik) == 0 && (i < 24 || i == 59) && cekj == 0)
            cekj = 1;

        sprintf( cekdetik, "%d", i );
    }

    pid_t pid, sid;     // Variabel untuk menyimpan PID
    pid = fork();       // Menyimpan PID dari Child Process

    // Keluar saat fork gagal (nilai variabel pid < 0)
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    // Keluar saat fork berhasil (nilai variabel pid adalah PID dari child process)
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    if ((chdir("/")) < 0) {
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1) {

        time_t rawtime;
        struct tm * timeinfo;

        time ( &rawtime );
        timeinfo = localtime ( &rawtime );

        char detik[10],menit[10],jam[10];
        sprintf( detik, "%d", timeinfo->tm_sec );
        sprintf( menit, "%d", timeinfo->tm_min );
        sprintf( jam, "%d", timeinfo->tm_hour );

        if (cekd == 0 || cekm == 0|| cekj == 0) {
            char path[100] = "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal1/error.txt";
            char *argv2[] = {"touch", path, NULL};
            execv("/usr/bin/touch", argv2);
            perror("error\n");
            exit(EXIT_FAILURE);
        }

        if ((strcmp(argv[1], "*") == 0 || strcmp(argv[1], detik) == 0) && (strcmp(argv[2], "*") == 0 || strcmp(argv[2], menit) == 0) &&
            (strcmp(argv[3], "*") == 0 || strcmp(argv[3], jam) == 0)) {
            
            pid_t child_id = fork();
            
            if (child_id < 0) {
                perror("error\n");
                exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
            }
            
            if (child_id == 0){
                char *argv2[] = {"bash",argv[4], NULL};
                execv("/bin/bash", argv2);
            }    
        }
        sleep(1);
    }
}