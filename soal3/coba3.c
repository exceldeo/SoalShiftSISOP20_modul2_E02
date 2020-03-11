#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>

void langkah1(char dir2[100]){
            char *arg4v[] = {"mv",dir2,"/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/sedaap/", NULL};
            execv("/bin/mv", arg4v);
}

void langkah2(char dir2[100]){
                char *argv5[] = {"mv",dir2,"/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie/", NULL};
            execv("/bin/mv", argv5);
}

void langkah3(char dir2[100]){
    char *argv6[] = {"mv",dir2,"/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie/", NULL};
            execv("/bin/mv", argv6);

}

void langkah4(char dir2[100]){
    char *argv[] = {"mv",dir2,"/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie/", NULL};
            execv("/bin/mv", argv);
}

int main()
{
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

    // printf
    int iter = 10;
    while( 1 )
    {
        entry=readdir(folder);
        if(entry == NULL)
        break;
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

            printf("langkah1\n");
            strcpy(dir2,dir);
            strcat(dir2,entry->d_name);
            langkah1(dir2);
            continue;
        }
        if(entry->d_type == 4 ){

            printf("langkah2\n");
            strcpy(dir2,dir);
            strcat(dir2,entry->d_name);
            langkah2(dir2);
            // char *argv5[] = {"mv",dir2,"/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie/", NULL};
            // execv("/bin/mv", argv5);
            printf("langkah3\n");
            


            strcpy(dir2,dir3);
            strcat(dir2,entry->d_name);
            strcat(dir2,"/coba1.txt");

            // char *argv6[] = {"mv",dir2,"/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie/", NULL};
            // execv("/bin/mv", argv6);
            langkah3(dir2);
            // sleep(3);

            printf("langkah4\n");
            strcpy(dir2,dir3);
            strcat(dir2,entry->d_name);
            strcat(dir2,"/coba2.txt");
            langkah4(dir2);
            // char *argv[] = {"mv",dir2,"/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal3/indomie/", NULL};
            // execv("/bin/mv", argv);

        }
    }

    closedir(folder);

    return(0);
}