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
#include <dirent.h>
#include <string.h>
#include <wait.h>

int main() {
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

    int iterator = 0;
  while (1) {
    char temp[100] = "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal2/",namafolder[100];
    pid_t child_id;
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    // sprintf(output, "[%d %d %d %d:%d:%d]",timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    char output[20],save[20];
    sprintf( output, "%d-%d-%d_%d:%d:%d",timeinfo->tm_year+1900,timeinfo->tm_mon+1,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec );
    
    strcat(temp,output);
    
    if(iterator%6==0){
        pid_t child_id;
        int status;

        child_id = fork();
        
        if (child_id < 0) {
            exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
        }

        if (child_id == 0) {    
            char *argv[] = {"mkdir", "-p", temp, NULL};
            execv("/bin/mkdir", argv);
        }
        // else{
        //   while ((wait(&status)) > 0 && iterator == 0);
        //   DIR *folder1;
        // struct dirent *entry1;
        // int files1 = 0;
        // folder1 = opendir("/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal2/");
        // if(folder1 == NULL)
        // {
        //     perror("Unable to read directory");
        //     return(1);
        // }
        
        // while( (entry1=readdir(folder1)) )
        // {
        //     files1++;
        //     printf("File %3d: %d name : %s\n",
        //             files1,
        //             entry1->d_type,entry1->d_name
        //             );
        //     if ((strcmp(entry1->d_name, ".")) != 0 && (strcmp (entry1->d_name, "..")) != 0)
        //         break;
        // }
        // strcpy(namafolder,entry1->d_name);
        // printf("nama folder %s\n",namafolder);
        // }
    }

    if(iterator % 21 == 0 || iterator == 1 ){
        char tempat2[100]="/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal2/";
        if(iterator %21 == 0 && iterator != 0){
          pid_t child_id3;
          int status3;
          char tempat5[200],tempat3[200],tempat4[200];
          strcpy(tempat3,tempat2);
          strcat(tempat3,namafolder);
          strcpy(tempat4,tempat3);
          strcpy(tempat5,tempat4);
          strcat(tempat3,".zip");
          strcat(tempat5,"aaaa.txt");

          child_id3 = fork();
          if (child_id3 < 0) {
            char *argv[] = {"touch",tempat5, NULL};
            execv("/usr/bin/touch", argv);
            exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
          }

          if (child_id3 == 0) {
            char *argv[] = {"zip", "-r",tempat3,tempat4, NULL};
            execv("/usr/bin/zip", argv);
          } else {
            // this is parent
            while ((wait(&status3)) > 0);
              pid_t child_id4;
              int status4;

              child_id4 = fork();
              
              if (child_id4 < 0) {
                  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
              }

              if (child_id4 == 0) {
                  char *argv[] = {"rm", "-r",tempat4, NULL};
                  execv("/bin/rm", argv);
              } 
          }
        }


        DIR *folder1;
        struct dirent *entry1;
        int files1 = 0;
        folder1 = opendir("/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal2/");
        if(folder1 == NULL)
        {
            perror("Unable to read directory");
            return(1);
        }
        
        while( (entry1=readdir(folder1)) )
        {
            files1++;
            printf("File %3d: %d name : %s\n",
                    files1,
                    entry1->d_type,entry1->d_name
                    );
            if ((strcmp(entry1->d_name, ".")) != 0 && (strcmp (entry1->d_name, "..")) != 0)
                break;
        }
        strcpy(namafolder,entry1->d_name);
        printf("nama folder %s\n",namafolder);
        
    }

    if(iterator != 0){

        time_t rawtime1;
        struct tm * timeinfo1;

        time ( &rawtime1 );
        timeinfo1 = localtime ( &rawtime1 );

        char detik[100],tempatnama[100];
        int t = (timeinfo1->tm_sec%1000)+100;
        sprintf( detik, "%d", t );
        strcpy(tempatnama,detik);
        strcat(tempatnama,".jpg");

        char dir[100] = "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal2/" , dir2[100], aa[100];
        // https://loremflickr.com/320/240/cat -O pdkt_kusuma_$num.jpg
        // https://picsum.photos/200/300.jpg

        
        char alamat[100] = "https://picsum.photos/",tempat1[100]="‐-directory-prefix=";
        strcat(alamat,detik);
        strcat(alamat,"/");
        strcat(alamat,detik);
        strcat(alamat,".jpg");
        sprintf( detik, "%d-%d-%d_%d:%d:%d",timeinfo1->tm_year+1900,timeinfo1->tm_mon+1,timeinfo1->tm_mday,timeinfo1->tm_hour,timeinfo1->tm_min,timeinfo1->tm_sec );

        strcat(tempat1,dir);
        strcat(tempat1,namafolder);
        strcat(tempat1,"/");
        strcpy(dir2,dir);
        strcat(dir2,namafolder);
        strcat(dir2,"/");
        strcat(dir2,detik);
        strcat(dir2,".jpg");

        strcpy(aa,dir);
        strcat(aa,namafolder);
        strcat(aa,"/");
        strcat(aa,detik);
        strcat(aa,".txt");

        pid_t child_id1;
        int status1;

        child_id1 = fork();
        
        if (child_id1 < 0) {
            exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
        }

        if (child_id1 == 0) {    
            // char *argv[] = {"touch",aa, NULL};
            // execv("/usr/bin/touch", argv);
            char *argv[] = {"wget",tempat1, alamat,"-O",dir2, NULL};
            execv("/usr/bin/wget", argv);
        }
        
    }
    
    iterator++;
    sleep(1);
  }
}