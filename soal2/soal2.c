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

int main(int argc3, char *argv3[]) {
    if (strcmp(argv3[1],"-a") == 0) {
      char *argv[] = {"killall", "-9", "soal2", NULL};
      execv("/usr/bin/killall", argv);
    }
    if (strcmp(argv3[1],"-b") == 0) {
      char *argv[] = {"killall", "-9", "soal2", NULL};
      execv("/usr/bin/killall", argv);
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

int iterator = 0;
    while (1) {
    char temp[100] = "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal2/",namafolder[100],foldera[100];
    printf("aaa\n");
    // masuk
    pid_t child_id;
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    // sprintf(output, "[%d %d %d %d:%d:%d]",timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    char output[20],save[20];
    sprintf( output, "%d-%d-%d_%d:%d:%d",timeinfo->tm_year+1900,timeinfo->tm_mon+1,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec );
    strcpy(foldera,temp);
    strcat(foldera,output);
    char detik[100],tempatnama[100];
    int t = (timeinfo->tm_sec%1000)+100;
    
    if(iterator%6==0){
        pid_t child_id1;
        int status1;

        child_id1 = fork();
        
        if (child_id1 < 0) {
            exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
        }

        if (child_id1 == 0) {    
            char *argv[] = {"mkdir", "-p", foldera, NULL};
            execv("/bin/mkdir", argv);
        }
    }
    // keluar
    DIR *folder1, *folderopen;
    struct dirent *entry;
    struct dirent *masuk;
    int files1 = 0;
    folder1 = opendir("/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal2/");
    if(folder1 == NULL)
    {
        printf("vv\n");
        perror("Unable to read directory");
        return(1);
    }
    
    while( (entry=readdir(folder1)) )
    {
        printf("aaaaaadddd\n");
        files1++;
        int hitung = 0;
        if ((strcmp(entry->d_name, ".")) == 0 || (strcmp (entry->d_name, "..")) == 0 || entry->d_type == 8)
            continue;
        strcpy(namafolder,temp);
        strcat(namafolder,entry->d_name);
        pid_t child_id;
        int status;

        child_id = fork();
        if (child_id < 0) exit(EXIT_FAILURE); 
        if (child_id == 0) {    
            
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
            // sprintf( detik, "%d-%d-%d_%d:%d:%d",timeinfo1->tm_year+1900,timeinfo1->tm_mon+1,timeinfo1->tm_mday,timeinfo1->tm_hour,timeinfo1->tm_min,timeinfo1->tm_sec );

            strcat(tempat1,dir);
            strcat(tempat1,entry->d_name);
            strcat(tempat1,"/");
            strcpy(dir2,dir);
            strcat(dir2,entry->d_name);
            strcat(dir2,"/");
            strcat(dir2,output);
            strcat(dir2,".jpg");

            strcpy(aa,dir);
            strcat(aa,entry->d_name);
            strcat(aa,"/");
            strcat(aa,detik);
            strcat(aa,".txt");

            // char *argv[] = {"wget",tempat1, alamat,"-O",dir2, NULL};
            // execv("/usr/bin/wget", argv);
            char *argv3[] = {"touch",aa, NULL};
            execv("/usr/bin/touch", argv3);
        }
        folderopen = opendir(namafolder);
        if(folderopen == NULL)
        {
            perror("Unable to read directory");
            return(1);
        }
        
        while( (masuk=readdir(folderopen)) )
        {
            hitung++;
        }
        

        if(hitung == 22){
            pid_t child_id1 = fork();
            int status1;
            char tempat3[100],tempat4[100];
            strcpy(tempat3,namafolder);
            strcpy(tempat4,namafolder);
            strcat(tempat3,".zip");
            if (child_id1 < 0) exit(EXIT_FAILURE); 
            if (child_id1 == 0) {    
                char *argv[] = {"zip", "-r",tempat3,tempat4, NULL};
                execv("/usr/bin/zip", argv);
            }
            while ((wait(&status1)) > 0);
            child_id1 = fork();
            if (child_id1 < 0) exit(EXIT_FAILURE); 
            if (child_id1 == 0) {    
                char *argv[] = {"rm", "-r",namafolder, NULL};
                execv("/bin/rm", argv);
            }
        }
        printf("File %3d: %d name : %s jumlah %d\n",
                files1,
                entry->d_type,entry->d_name,hitung-2
                );

      }
      
        iterator++;
        sleep(5);
    }
  
}