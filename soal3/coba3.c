#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
  pid_t child_id;
  int status;

  child_id = fork();
  
  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

  if (child_id == 0) {
    char *argv[] = {"mkdir", "-p", "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie", NULL};
    execv("/bin/mkdir", argv);
  } else {
    // this is parent
    while ((wait(&status)) > 0);

        pid_t child_id2;
        int status2;

        child_id2 = fork();
        
        if (child_id2 < 0) {
            exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
        }

        if (child_id2 == 0) {
            sleep(5);
            char *argv[] = {"mkdir", "-p", "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/sedaap", NULL};
            execv("/bin/mkdir", argv);
        } else {
            // this is parent
            while ((wait(&status2)) > 0);
            
                pid_t child_id3;
                int status3;

                child_id3 = fork();
                
                if (child_id3 < 0) {
                    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
                }

                if (child_id3 == 0) {
                    // sleep(5);
                    char *argv[] = {"unzip", "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/jpg.zip", NULL};
                    execv("/usr/bin/unzip", argv);
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

                            strcpy(dir2,dir);
                            strcat(dir2,entry->d_name);
                            pid_t child_id5;

                            child_id5 = fork();
                            
                            if (child_id5 < 0) {
                                exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
                            }

                            if (child_id5 == 0 && entry->d_type == 8) {
                                char *arg4v[] = {"mv",dir2,"/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/sedaap/", NULL};
                                execv("/bin/mv", arg4v);
                            }

                            if (child_id5 == 0 && entry->d_type == 4) {
                                char *argv5[] = {"mv",dir2,"/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie/", NULL};
                                execv("/bin/mv", argv5);
                            }
                            }
                        } else {
                            // this is parent
                            while ((wait(&status4)) > 0);

                            DIR *folder;
                            struct dirent *entry;
                            int files = 0,iter = 0;
                            char dir[100] = "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie/" , dir2[100], dir3[100]="/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/indomie/";

                            folder = opendir("/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie");
                            if(folder == NULL)
                            {
                                perror("Unable to read directory");
                                return(1);
                            }
                            
                            while( (entry=readdir(folder)) )
                            {
                                files++;
                                printf("File %3d: %d name 11: %s\n",
                                        files,
                                        entry->d_type,entry->d_name
                                        );
                                if (!strcmp (entry->d_name, "."))
                                    continue;
                                if (!strcmp (entry->d_name, ".."))    
                                    continue;

                                pid_t child_id6;
                                int status6;

                                child_id6 = fork();
                                
                                if (child_id6 < 0) {
                                    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
                                }

                                if (child_id6 == 0) {
                                    strcpy(dir2,dir3);
                                    strcat(dir2,entry->d_name);
                                    strcat(dir2,"/coba1.txt");
                                    char *argv6[] = {"touch",dir2, NULL};
                                    execv("/usr/usr/bin/touch", argv6);  
                                }
                                else {
                                while ((wait(&status)) > 0);
                                    sleep(3);
                                    strcpy(dir2,dir3);
                                    strcat(dir2,entry->d_name);
                                    strcat(dir2,"/coba2.txt");
                                    char *argv6[] = {"touch",dir2,NULL};
                                    execv("/usr/bin/touch", argv6);  
                                // char *argv[] = {"touch", "folderku/fileku.txt", NULL};
                                // execv("/usr/bin/touch", argv);
                                }

                                // if (child_id6 == 0 && iter == 1 && entry->d_type == 4) {
                                // }
                            }

                        }

                }

        }
           
  }
}