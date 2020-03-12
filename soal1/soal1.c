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
  for(int i = 60 ; i >= 0 ; --i ){
    if(strcmp(argv[1], cekdetik) == 0 && cekd == 0){
      cekd = 1;
      // break;
    }

    if(strcmp(argv[1], cekdetik) == 0 && cekm == 0){
      cekm = 1;
      // break;
    }

    if(strcmp(argv[3], cekdetik) == 0 && i < 24 && cekj == 0){
      cekj = 1;
      // break;
    }
    sprintf( cekdetik, "%d", i );
  }
  pid_t pid, sid;        // Variabel untuk menyimpan PID

  pid = fork();     // Menyimpan PID dari Child Process

  /* Keluar saat fork gagal
  * (nilai variabel pid < 0) */
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  /* Keluar saat fork berhasil
  * (nilai variabel pid adalah PID dari child process) */
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
      char temp[100] = "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal1/";
      pid_t child_id;
        time_t rawtime;
        struct tm * timeinfo;

      time ( &rawtime );
      timeinfo = localtime ( &rawtime );


      // sprintf(output, "[%d %d %d %d:%d:%d]",timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
      char detik[10],menit[10],jam[10];
      sprintf( detik, "%d", timeinfo->tm_sec );
      sprintf( menit, "%d", timeinfo->tm_min );
      sprintf( jam, "%d", timeinfo->tm_hour );
      // detik = (char*)&timeinfo->tm_sec;
      // strcpy(argv[4],temp);
      // strcat(argv[4],detik);
      // strcat(argv[4],menit);
      // strcat(argv[4],jam);

      child_id = fork();
      
      if (child_id < 0 || cekd == 0 || cekm == 0|| cekj == 0) {
        printf("error\n");
        exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
      }

        // if (child_id == 0 ) {
        //   char *argv2[] = {"bash",argv[4], NULL};
        //   execv("/bin/bash", argv2);
        // }


      if(strcmp(argv[1], detik) == 0 && strcmp(argv[2], menit) == 0 && strcmp(argv[3], jam) == 0){
        if (child_id == 0 ) {
          char *argv2[] = {"bash",argv[4], NULL};
          execv("/bin/bash", argv2);
        }
      }
      else if(strcmp(argv[1], "*") == 0 && strcmp(argv[2], "*") == 0 && strcmp(argv[3], "*") == 0){
        if (child_id == 0 ) {
          char *argv2[] = {"bash",argv[4], NULL};
          execv("/bin/bash", argv2);
        }
      }
      else if(strcmp(argv[1], "*") == 0 && strcmp(argv[2], "*") == 0){
        if(strcmp(argv[3], jam) == 0){
          if (child_id == 0 ) {
            char *argv2[] = {"bash",argv[4], NULL};
            execv("/bin/bash", argv2);
          }
        }
      }
      else if(strcmp(argv[1], "*") == 0 && strcmp(argv[3], "*") == 0)
      if(strcmp(argv[2], menit) == 0){
        if (child_id == 0 ) {
          char *argv2[] = {"bash",argv[4], NULL};
          execv("/bin/bash", argv2);
        }
      }
      else if(strcmp(argv[3], "*") == 0 && strcmp(argv[2], "*") == 0)
      if(strcmp(argv[1], detik) == 0){
        if (child_id == 0 ) {
          char *argv2[] = {"bash",argv[4], NULL};
          execv("/bin/bash", argv2);
        }
      }
      else if(strcmp(argv[1], "*") == 0)
      if(strcmp(argv[2], menit) == 0 && strcmp(argv[3], jam) == 0){
        if (child_id == 0 ) {
          char *argv2[] = {"bash",argv[4], NULL};
          execv("/bin/bash", argv2);
        }
      }
      else if(strcmp(argv[2], "*") == 0)
      if(strcmp(argv[1], detik) == 0 && strcmp(argv[3], jam) == 0){
        if (child_id == 0 ) {
          char *argv2[] = {"bash",argv[4], NULL};
          execv("/bin/bash", argv2);
        }
      }
      else if(strcmp(argv[3], "*") == 0)
      if(strcmp(argv[2], menit) == 0 && strcmp(argv[1], detik) == 0){
        if (child_id == 0 ) {
          char *argv2[] = {"bash",argv[4], NULL};
          execv("/bin/bash", argv2);
        }
      }
    sleep(1);
  }
}