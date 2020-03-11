 
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

// Driver code 
int main() 
{ 
	int pid,pid1,pid2,pid3,pid4; 
    int i = 0;
	// variable pid will store the 
	// value returned from fork() system call 
	pid = fork(); 

    if (pid < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
	if (pid == 0) { 
                printf("3\n");
				DIR *folder;
                struct dirent *entry;
                int files = 0;
                char dir[100] = "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/jpg/" , dir2[100], dir3[100]="/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/indomie/";


                folder = opendir("/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/jpg");
                if(folder == NULL)
                {
                printf("2\n");
                    perror("Unable to read directory");
                    return(1);
                }
                while( (entry=readdir(folder)) )
                {
                    printf("1\n");
                    files++;
                    printf("File %3d: %d name : %s\n",
                            files,
                            entry->d_type,entry->d_name
                            );
                    if (!strcmp (entry->d_name, "."))
                        continue;
                    if (!strcmp (entry->d_name, ".."))    
                        continue;
                    // sleep(1);
                }
                closedir(folder);
                printf("\naajja\n"); 
	} 


	else { 
		pid1 = fork();

          if (pid1 < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

		if (pid1 == 0) { 
    char *argv2[] = {"mkdir", "-p", "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie", NULL};
            printf("aaa %d\n",pid1);
    execv("/bin/mkdir", argv2);
		} 
		else { 
			pid2 = fork();

              if (pid2 < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

			if (pid2 == 0) {  
			sleep(1); 
            char *argv2[] = {"mkdir", "-p", "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/sedaap", NULL};
            execv("/bin/mkdir", argv2);
                    printf("4\n");
			} 

			else { 
                    char *argv3[] = {"unzip", "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/jpg.zip", NULL};
                    execv("/usr/bin/unzip", argv3);
            }
        } 
	} 

	return 0; 
} 
