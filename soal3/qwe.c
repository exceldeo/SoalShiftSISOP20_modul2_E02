#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>

int main() {
  pid_t child_id,child_id3,child_id2;
  int status,status2;

  child_id = fork();
  
  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

  if (child_id == 0) {
    // this is child
    
    char *argv[] = {"mkdir", "-p", "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie", NULL};
    execv("/bin/mkdir", argv);
  } else {
    // this is parent
    while ((wait(&status)) > 0);

        child_id2 = fork();
      
      if (child_id2 < 0) {
        exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
      }

      if (child_id2 == 0) {
        // this is child
        sleep(1);
        char *argv[] = {"mkdir", "-p", "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/sedaap", NULL};
        execv("/bin/mkdir", argv);
      } else {
        // this is parent
        while ((wait(&status2)) > 0);

        child_id3 = fork();
      
      if (child_id3 < 0) {
        exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
      }

      if (child_id3 == 0) {
        // this is child
        sleep(1);
        char *argv[] = {"mkdir", "-p", "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/sedaap", NULL};
        execv("/bin/mkdir", argv);
      } else {
        // this is parent
        while ((wait(&status3)) > 0);
        
      }

      }
  }
}