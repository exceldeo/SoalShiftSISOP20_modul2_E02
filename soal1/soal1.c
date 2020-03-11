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
      char temp[100] = "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal1/",temp2[100];
      pid_t child_id;
      // time_t t ; 
      //   struct tm *tmp; 
      //   char detik[2],menit[2],jam[2]; 
      //   time( &t ); 
        
      //   tmp = localtime( &t );
      //   strftime(detik, sizeof(detik), "%S", tmp);
      //   strftime(menit, sizeof(menit), "%M", tmp);
      //   strftime(jam, sizeof(jam), "%H", tmp);
        // menit = localtime( &t );
        // strftime(MY_TIME, sizeof(MY_TIME), "%M", menit);
        // jam = localtime( &t ); 
        // strftime(MY_TIME, sizeof(MY_TIME), "%H", jam);
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
      strcpy(temp2,temp);
      strcat(temp2,detik);
      strcat(temp2,menit);
      strcat(temp2,jam);

      child_id = fork();
      
      if (child_id < 0) {
        exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
      }
      // if(strcmp(argv[1], detik) == 0 && strcmp(argv[2], menit) == 0 && strcmp(argv[3], jam) == 0)
        if (child_id == 0 ) {
          char *argv2[] = {"touch",temp2, NULL};
          execv("/usr/bin/touch", argv2);
        }
      
      // if(argv[1] == "*" && argv[2] == "*" && argv[3] == "*"){
      //   if (child_id == 0 ) {
      //     char *argv2[] = {"touch",temp2, NULL};
      //     execv("/usr/bin/touch", argv2);
      //   }
      // }
      // if(argv[1] == "*" && argv[2] == "*" )
      // if(argv[3] == jam){
      //   if (child_id == 0 ) {
      //     char *argv2[] = {"touch",temp2, NULL};
      //     execv("/usr/bin/touch", argv2);
      //   }
      // }
      // if(argv[1] == "*" && argv[3] == "*" )
      // if(argv[2] == menit){
      //   if (child_id == 0 ) {
      //     char *argv2[] = {"touch",temp2, NULL};
      //     execv("/usr/bin/touch", argv2);
      //   }
      // }
      // if(argv[3] == "*" && argv[2] == "*" )
      // if(argv[1] == detik){
      //   if (child_id == 0 ) {
      //     char *argv2[] = {"touch",temp2, NULL};
      //     execv("/usr/bin/touch", argv2);
      //   }
      // }
      // if(argv[1] == "*")
      // if(argv[2] == menit && argv[3] == jam){
      //   if (child_id == 0 ) {
      //     char *argv2[] = {"touch",temp2, NULL};
      //     execv("/usr/bin/touch", argv2);
      //   }
      // }
      // if(argv[2] == "*")
      // if(argv[1] == detik && argv[3] == jam){
      //   if (child_id == 0 ) {
      //     char *argv2[] = {"touch",temp2, NULL};
      //     execv("/usr/bin/touch", argv2);
      //   }
      // }
      // if(argv[3] == "*")
      // if(argv[2] == menit && argv[2] == detik){
      //   if (child_id == 0 ) {
      //     char *argv2[] = {"touch",temp2, NULL};
      //     execv("/usr/bin/touch", argv2);
      //   }
      // }
    sleep(1);
  }
}