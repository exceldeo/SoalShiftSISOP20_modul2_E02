#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

void fungsimkdir1(){
    char *argv1[] = {"mkdir", "-p", "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie", NULL};
    execv("/bin/mkdir", argv1);
}

void fungsimkdir2(){
    char *argv2[] = {"mkdir", "-p", "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/sedaap", NULL};
    execv("/bin/mkdir", argv2);
}

int main() {
  pid_t child_id,child_id2;
  int status,status2;

  child_id = fork();
  
  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

  if (child_id == 0) {
    // this is child
    
    char *argv1[] = {"mkdir", "-p", "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie", NULL};
    execv("/bin/mkdir", argv1);
    // printf("apalo\n");
    sleep(5);
    // printf("apalo2\n");
    char *argv2[] = {"mkdir", "-p", "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/sedaap", NULL};
    execv("/bin/mkdir", argv2);

  } else {
    // this is parent
    while ((wait(&status)) > 0);
    child_id2 = fork();
  
    if (child_id2 < 0) {
        exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
    }

    if (child_id2 == 0) {
      char *argv3[] = {"unzip", "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/jpg.zip", NULL};
      execv("/usr/bin/unzip", argv3);
    }
    else {
    // this is parent
      while ((wait(&status2)) > 0);

      DIR *folder;
      struct dirent *entry;
      int files = 0;
      char dir[100] = "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/jpg/" , dir2[100], dir3[100]="/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/indomie/";


      folder = opendir("/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/jpg");
      if(folder == NULL)
      {
          perror("Unable to read directory");
          return(1);
      }
      
      while( (entry=readdir(folder)) )
      {
          files++;
          printf("File %3d: %d name : %s\n",
                  files,
                  entry->d_type,entry->d_name
                );
          if (!strcmp (entry->d_name, "."))
              continue;
          if (!strcmp (entry->d_name, ".."))    
              continue;
          if(entry->d_type == 8){
              strcpy(dir2,dir);
              strcat(dir2,entry->d_name);
              char *arg4v[] = {"mv",dir2,"/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/sedaap/", NULL};
              execv("/bin/mv", arg4v);
          }
          if(entry->d_type == 4 ){
              strcpy(dir2,dir);
              strcat(dir2,entry->d_name);
              char *argv5[] = {"mv",dir2,"/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie/", NULL};
              execv("/bin/mv", argv5);
              
              strcpy(dir2,dir3);
              strcat(dir2,entry->d_name);
              strcat(dir2,"/coba1.txt");

              char *argv6[] = {"mv",dir2,"/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie/", NULL};
              execv("/bin/mv", argv6);

              sleep(3);

              strcpy(dir2,dir3);
              strcat(dir2,entry->d_name);
              strcat(dir2,"/coba2.txt");

              char *argv[] = {"mv",dir2,"/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie/", NULL};
              execv("/bin/mv", argv);

          }
      }

      closedir(folder);

      printf("cobacoba\n");
    }

  }
}