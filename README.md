# SoalShiftSISOP20_modul2_E02

### Outline
1. [Soal #1](#soal-1) (Source Code : [soal1.c](https://github.com/exceldeo/SoalShiftSISOP20_modul2_E02/blob/master/soal1/soal1.c))
2. [Soal #2](#soal-2) (Source Code : [soal2.c](https://github.com/exceldeo/SoalShiftSISOP20_modul2_E02/blob/master/soal2/soal2.c))
3. [Soal #3](#soal-3) (Source Code : [soal3.c](https://github.com/exceldeo/SoalShiftSISOP20_modul2_E02/blob/master/soal3/soal3.c))

## Soal #1
Buatlah program C yang menyerupai crontab untuk menjalankan script bash dengan ketentuan sebagai berikut:

a. Program menerima 4 argumen berupa:

    i.   Detik: 0-59 atau * (any value)

    ii.  Menit: 0-59 atau * (any value)

    iii. Jam: 0-23 atau * (any value)

    iv.  Path file .sh

b. Program akan mengeluarkan pesan error jika argumen yang diberikan tidak sesuai

c. Program hanya menerima 1 config cron

d. Program berjalan di background (daemon)

e. Tidak boleh menggunakan fungsi system()

### Penyelesaian

Agar program dapat menerima argumen maka pada `int main ()` ditambahkan parameter `int argc` dan `char *argv[]` dimana `argc` menampung banyak string yang ditunjukkan oleh array `argv`.

Setelah itu, kita akan mengecek apakah argumen yang diberikan sesuai atau tidak dengan permintaan soal dengan kode berikut. Adapun pada mulanya array `cekdetik` berisi nilai `*`.
```c
for (i = 59 ; i >= 0 ; --i ){

    if(strcmp(argv[1], cekdetik) == 0 && cekd == 0)
        cekd = 1;

    if(strcmp(argv[2], cekdetik) == 0 && cekm == 0)
        cekm = 1;

    if(strcmp(argv[3], cekdetik) == 0 && (i < 24 || i == 59) && cekj == 0)
        cekj = 1;

    sprintf( cekdetik, "%d", i );
}
```
+ `for (i = 59 ; i >= 0 ; --i )` melakukan perulangan sebanyak 60 kali (karena detik dan menit mempunyai nilai maksimum 59).
+ `if(strcmp(argv[1], cekdetik) == 0 && cekd == 0)` mengecek selama `cekd` masih `0` dan argumen detik yang diinputkan sama dengan nilai dari array cekdetik maka variabel `cekd` berubah menjadi `1` (`cekd = 1`).
+ `if(strcmp(argv[2], cekdetik) == 0 && cekm == 0)` mengecek selama `cekm` masih `0` dan argumen menit yang diinputkan sama dengan nilai dari array cekdetik maka variabel `cekd` berubah menjadi `1` (`cekm = 1`).
+ `if(strcmp(argv[3], cekdetik) == 0 && (i < 24 || i == 59) && cekj == 0)` mengecek selama `cekj` masih `0` dan argumen jam yang diinputkan sama dengan nilai dari array cekdetik serta iterator sama dengan 59 atau kurang dari 24 maka variabel `cekj` berubah menjadi `1` (`cekj = 1`).
+ `sprintf( cekdetik, "%d", i )` digunakan untuk mengubah nilai dari array `cekdetik` menjadi nilai dari iterator saat ini.

Kode untuk mengeluarkan pesan error terdapat dalam main program `while (1)`, dengan kondisi ketika argumen detik tidak sesuai (`cekd = 0`) atau argumen menit tidak sesuai (`cekm = 0`) atau argumen jam tidak sesuai (`cekj = 0`).
```c
if (cekd == 0 || cekm == 0|| cekj == 0) {
    char aaa[100] = "/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal1/error.txt";
    char *argv2[] = {"touch",aaa, NULL};
    execv("/usr/bin/touch", argv2);
    perror("error\n");
    exit(EXIT_FAILURE);
}
```
Pesan error akan muncul dalam bentuk file `error.txt` dengan keadaan kosong serta pesan `error` pada terminal.

```c
time_t rawtime;
struct tm * timeinfo;

time ( &rawtime );
timeinfo = localtime ( &rawtime );

char detik[10], menit[10], jam[10];
sprintf( detik, "%d", timeinfo->tm_sec );
sprintf( menit, "%d", timeinfo->tm_min );
sprintf( jam, "%d", timeinfo->tm_hour );
```
Kode di atas digunakan untuk mendapatkan localtime ketika proses dijalankan. Detik dari localtime akan disimpan dalam array `detik`, menit disimpan dalam array `menit` dan jam disimpan dalam array `jam` dengan fungsi `sprintf()`.

```c
if ((strcmp(argv[1], "*") == 0 || strcmp(argv[1], detik) == 0) && (strcmp(argv[2], "*") == 0 || strcmp(argv[2], menit) == 0) && (strcmp(argv[3], "*") == 0 || strcmp(argv[3], jam) == 0)) {
	pid_t child_id = fork();
    if (child_id < 0) {
        perror("error\n");
        exit(EXIT_FAILURE);
    }

  if (child_id == 0){
        char *argv2[] = {"bash",argv[4], NULL};
        execv("/bin/bash", argv2);
    } 
}
```
+ `if ((strcmp(argv[1], "*") == 0 || strcmp(argv[1], detik) == 0) && (strcmp(argv[2], "*") == 0 || strcmp(argv[2], menit) == 0) && (strcmp(argv[3], "*") == 0 || strcmp(argv[3], jam) == 0))` mengecek apakah waktu ketika proses ini dijalankan sama dengan argumen yang diinputkan.
+ `pid_t child_id = fork()` untuk membuat proses baru.
+ `if (child_id < 0)` jika parent process gagal membuat proses baru maka akan muncul pesan error dengan `perror("error\n")` dan program akan berhenti.
+ `if (child_id == 0)` jika parent process berhasil membuat proses baru maka argumen script bash yang input akan dijalankan dengan kode `char *argv2[] = {"bash",argv[4], NULL}` dan `execv("/bin/bash", argv2)`.

Terakhir kita lakukan `sleep(1)` agar perulangannya berjalan setiap 1 detik karena bisa saja argumen yang diinputkan meminta agar proses berjalan setiap 1 detik.

---

## Soal #2

Shisoppu mantappu! itulah yang selalu dikatakan Kiwa setiap hari karena sekarang dia merasa sudah jago materi sisop. Karena merasa jago, suatu hari Kiwa iseng membuat sebuah program.

a. Pertama-tama, Kiwa membuat sebuah folder khusus, di dalamnya dia membuat sebuah program C yang per 30 detik membuat sebuah folder dengan nama timestamp YYYY-mm-dd_HH:ii:ss.

b. Tiap-tiap folder lalu diisi dengan 20 gambar yang di download dari https://picsum.photos/, dimana tiap gambar di download setiap 5 detik. Tiap gambar berbentuk persegi dengan ukuran (t%1000)+100 piksel dimana t adalah detik Epoch Unix. Gambar tersebut diberi nama dengan format timestamp [YYYY- mm-dd_HH:ii:ss].

c. Agar rapi, setelah sebuah folder telah terisi oleh 20 gambar, folder akan di zip dan folder akan di delete(sehingga hanya menyisakan .zip).

d. Karena takut program tersebut lepas kendali, Kiwa ingin program tersebut men- generate sebuah program "killer" yang siap di run(executable) untuk menterminasi semua operasi program tersebut. Setelah di run, program yang menterminasi ini lalu akan mendelete dirinya sendiri.

e. Kiwa menambahkan bahwa program utama bisa dirun dalam dua mode, yaitu MODE_A dan MODE_B. untuk mengaktifkan MODE_A, program harus dijalankan dengan argumen -a. Untuk MODE_B, program harus dijalankan dengan argumen -b. Ketika dijalankan dalam MODE_A, program utama akan langsung menghentikan semua operasinya ketika program killer dijalankan. Untuk MODE_B, ketika program killer dijalankan, program utama akan berhenti tapi membiarkan proses di setiap folder yang masih berjalan sampai selesai(semua folder terisi gambar, terzip lalu di delete).

Kiwa lalu terbangun dan sedih karena menyadari programnya hanya sebuah mimpi. Buatlah program dalam mimpi Kiwa jadi nyata!

### Penyelesaian

Karena program utamanya harus detach dari terminal, maka kita gunakan daemon process. Adapun kode-kode di bawah terdapat pada loop utama daemon process (`while(1)`). Untuk poin (a), timestamp YYYY-mm-dd_HH:ii:ss dapat diperoleh dengan cara berikut ini.
```c
time_t rawtime;
struct tm * timeinfo;

time ( &rawtime );
timeinfo = localtime ( &rawtime );

char output[20];
sprintf( output, "%d-%d-%d_%d:%d:%d",timeinfo->tm_year+1900,timeinfo->tm_mon+1,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec );
```
Sedangkan untuk membuat foldernya, terlebih dahulu kita buat proses baru dengan `child_id1 = fork()` lalu jika berhasil maka kode di bawah akan dieksekusi dan menghasilkan folder dengan nama YYYY-mm-dd_HH:ii:ss. `foldera` disini berisi path ke folder YYYY-mm-dd_HH:ii:ss.

```c
if (child_id1 == 0) {    
    char *argv[] = {"mkdir", "-p", foldera, NULL};
    execv("/bin/mkdir", argv);
}
```
Kode tersebut berada dalam `if(iterator%6==0)` dimana nilai iterator awalnya `iterator = 0` agar folder YYYY-mm-dd_HH:ii:ss dapat dibuat setiap 30 detik. Nilai 1 iterator sama dengan 5 detik.

Setelah membuat folder, maka pada parent processnya akan kita lakukan pembuatan proses baru lagi untuk mendownload gambar pertama dari https://picsum.photos/ ke dalam folder.
```c
else {
    while ((wait(&status1)) > 0);
    child_id1 = fork();
    if(child_id1 == 0){
        strcpy(tempat11,tempat1);
        strcat(tempat11,foldera);
        strcpy(dir3,foldera);
        strcat(dir3,"/");
        strcat(dir3,output);
        strcat(dir3,".jpg");
        char *argv[] = {"wget",tempat11, alamat,"-O",dir3, NULL};
        execv("/usr/bin/wget", argv);
    }
}
```
+ `strcpy(tempat11,tempat1)` dan `strcat(tempat11,foldera)` untuk mengetahui dan menyimpan path dari folder YYYY-mm-dd_HH:ii:ss ke dalam array `tempat11`.
+ `strcpy(dir3,foldera)`, `strcat(dir3,"/")`, `strcat(dir3,output)`, dan `strcat(dir3,".jpg")` untuk menyimpan gambar dengan format jpg dengan nama file YYYY-mm-dd_HH:ii:ss.
+ `alamat` berisi link https://picsum.photos/(t%1000)+100 dimana t adalah detik Epoch Unix. `t` didapat dengan `t = (timeinfo->tm_sec)`.

Untuk mendownload gambar kedua dan seterusnya hingga 20 dilakukan dalam perulangan `while( (entry=readdir(folder1)) )` dimana `folder1 = opendir("/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal2/")`. Dalam perulangan ini kita akan membuat lagi proses baru untuk mendownload gambar tersebut.

```c
 if (child_id == 0) {    
                
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

    char *argv[] = {"wget",tempat1, alamat,"-O",dir2, NULL};
    execv("/usr/bin/wget", argv);
}
```
Penjelasan kode tersebut sama dengan penjelasan kode yang di atas.

Untuk men-zip folder ketika jumlah gambar sudah 20, pertama-tama kita hitung dulu jumlah file yang terdapat dalam folder.
```c
while( (masuk=readdir(folderopen)) )
    hitung++;
```
Dengan `folderopen = opendir(namafolder)` dan `namafolder` berisi `/home/excel/Desktop/SoalShiftSISOP20_modul2_E02/soal2/YYYY-mm-dd_HH:ii:ss`. Jika `hitung = 22` maka kita akan men-zip folder tersebut lalu menghapusnya sesuai dengan permintaan poin (c). Kenapa 22? Karena pada saat menghitung, direktori "." dan ".." juga termasuk sehingga untuk mendapatkan jumlah gambar yang ada kita harus menambahkan 2.

```c
pid_t child_id1 = fork();
int status1;
char tempat3[100], tempat4[100];

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
```
Proses baru yang pertama akan men-zip folder jika jumlah file gambar sudah 20. Kemudian, untuk menghapus folder tersebut, terlebih dahulu kita harus menunggu sampai proses baru pertama menyelesaikan tugasnya, baru kita buat proses baru lagi yang menghapus folder.

Loop utama daemon process ini diakhiri dengan penambahan iterator dan `sleep(5)` agar gambar dapat didownload setiap 5 detik.

Pembuatan mode killer dilakukan sebelum kita melalukan daemon process. Disini, kami hanya berhasil membuat MODE A dimana program utama akan langsung menghentikan semua operasinya ketika program killer dijalankan.
```c
if (strcmp(argv3[1],"-a") == 0)
    modea();
else if (strcmp(argv3[1],"-b") == 0) 
    modeb();
else exit(EXIT_FAILURE);
```
Kode di atas mengecek argumen yang diinputkan. Jika menginputkan -a maka akan menuju fungsi modea dengan kode di bawah ini. Jika menginputkan -b akan menuju fungsi modeb (tidak ada). Sedangkan jika tidak menginputkan apa-apa maka program akan berhenti.
```c
void modea(){
    FILE * file = fopen("killer","w+");
    fprintf(file,"#!/bin/bash\n");
    fprintf(file,"kill -9 $(pidof soal2)\n");
    fprintf(file,"rm -- \"$0\"\n");
    fclose(file);
    chmod("killer", ~0);
}
```
+ `FILE * file = fopen("killer","w+")` membuat file killer yang dapat di update.
+ `fprintf(file,"#!/bin/bash\n")` menuliskan `#!/bin/bash` pada file killer yang menandakan bahwa file ini merupakan script bash.
+ `fprintf(file,"kill -9 $(pidof soal2)\n")` menuliskan perintah kill pada file killer yang akan menghentikan semua operasi yang dijalankan soal2.
+ `fprintf(file,"rm -- \"$0\"\n")` menuliskan perintah remove agar ketika sudah selesai dijalankan file killer ini bisa terhapus dengan sendirinya.
+ `fclose(file)` menutup file.
+ `chmod("killer", ~0)` agar file killer bisa di execute.

---

## Soal #3

Jaya adalah seorang programmer handal mahasiswa informatika. Suatu hari dia memperoleh tugas yang banyak dan berbeda tetapi harus dikerjakan secara bersamaan (multiprocessing).

a. Program buatan jaya harus bisa membuat dua direktori di “/home/[USER]/modul2/”. Direktori yang pertama diberi nama “indomie”, lalu lima detik kemudian membuat direktori yang kedua bernama “sedaap”.

b. Kemudian program tersebut harus meng-ekstrak file jpg.zip di direktori “/home/[USER]/modul2/”. Setelah tugas sebelumnya selesai, ternyata tidak hanya itu tugasnya.

c. Diberilah tugas baru yaitu setelah di ekstrak, hasil dari ekstrakan tersebut (di dalam direktori “home/[USER]/modul2/jpg/”) harus dipindahkan sesuai dengan pengelompokan, semua file harus dipindahkan ke “/home/[USER]/modul2/sedaap/” dan semua direktori harus dipindahkan ke “/home/[USER]/modul2/indomie/”.

d. Untuk setiap direktori yang dipindahkan ke “/home/[USER]/modul2/indomie/” harus membuat dua file kosong. File yang pertama diberi nama “coba1.txt”, lalu 3 detik kemudian membuat file bernama “coba2.txt”. (contoh : “/home/[USER]/modul2/indomie/{nama_folder}/coba1.txt”).

Karena Jaya terlalu banyak tugas dia jadi stress, jadi bantulah Jaya agar bisa membuat program tersebut.

### Penyelesaian

Poin (a) dapat diselesaikan dengan kode berikut.
```c
pid_t child_id;
int status;

child_id = fork();
    
if (child_id < 0)
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti

if (child_id == 0) {
    char *argv[] = {"mkdir", "-p", "/home/qqdnada/modul2/indomie", NULL};
    execv("/bin/mkdir", argv);
}
else {
    // this is parent
    while ((wait(&status)) > 0);

    pid_t child_id2;
    int status2;

    child_id2 = fork();
            
    if (child_id2 < 0)
        exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
        
    if (child_id2 == 0) {
        sleep(5);
        char *argv[] = {"mkdir", "-p", "/home/qqdnada/modul2/sedaap", NULL};
        execv("/bin/mkdir", argv);
    } 
```
+ `pid_t child_id` inisialisasi untuk menyimpan child id.
+ `int status` inisialisasi untuk mengetahui status dari suatu proses.
+ `child_id = fork()` untuk membuat proses baru.
+ `if (child_id < 0) exit(EXIT_FAILURE)` apabila gagal membuat proses baru program akan berhenti.
+ `if (child_id == 0)` jika berhasil membuat proses baru maka program akan membuat folder indomie dengan menggunakan `execv("/bin/mkdir", argv)`.
+ `while ((wait(&status)) > 0)` menunggu child process selesai melakukan tugasnya (membuat folder indomie). Setelah itu, program akan membuat child process yang kedua.
+ `if (child_id2 == 0)` jika child process kedua berhasil dibuat, maka program terlebih dahulu akan di-pause selama lima detik sesuai permintaan soal dengan `sleep(5)` baru membuat folder sedaap.

Setelah selesai membuat folder indomie dan sedaap, program kemudian akan membuat child process ketiga untuk meng-ekstrak file jpg.zip (poin (b)) dengan kode berikut.
```c
if (child_id3 == 0) {
    char *argv[] = {"unzip", "/home/qqdnada/modul2/jpg.zip", NULL};
    execv("/usr/bin/unzip", argv);
}
```

Untuk memindahkan file dalam folder jpg ke folder sedaap serta memindahkan folder yang ada dalam folder jpg ke folder indomie digunakan kode berikut. Sebelumnya program harus membuat child process keempat terlebih dahulu.
```c
if (child_id4 == 0) {
                                
    DIR *folder1;
    struct dirent *entry;
    int files = 0;

    char dir[100] = "/home/qqdnada/SoalShiftSISOP20_modul2_E02/soal3/jpg/", dir2[100],
         dir3[100]="/home/qqdnada/SoalShiftSISOP20_modul2_E02/soal3/indomie/";

    folder1 = opendir("/home/qqdnada/SoalShiftSISOP20_modul2_E02/soal3/jpg");
                    
    if(folder1 == NULL) {
        perror("Unable to read directory");
        return(1);
    }
                                
    while( (entry=readdir(folder1))) {
                        
        files++;
        printf("File %3d: | Name : %s\n", files, entry->d_name);

        if (!strcmp (entry->d_name, "."))
            continue;
        if (!strcmp (entry->d_name, ".."))    
            continue;

        strcpy(dir2,dir);
        strcat(dir2,entry->d_name);

        pid_t child_id5;
        child_id5 = fork();
                                    
        if (child_id5 < 0)
            exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti

        if (child_id5 == 0 && entry->d_type == 8) {
            char *argv4[] = {"mv",dir2,"/home/qqdnada/SoalShiftSISOP20_modul2_E02/soal3/sedaap/", NULL};
            execv("/bin/mv", argv4);
        }

        if (child_id5 == 0 && entry->d_type == 4) {
            char *argv5[] = {"mv",dir2,"/home/qqdnada/SoalShiftSISOP20_modul2_E02/soal3/indomie/", NULL};
            execv("/bin/mv", argv5);
        }
    }
}
```
+ `DIR *folder1` menampung pointer tipe DIR.
+ `struct dirent *entry` merupakan pointer ke directory entry.
+ `int files = 0` inisialisasi variabel files untuk menghitung banyak file/folder yang terdapat dalam suatu folder.
+ `folder1 = opendir("/home/qqdnada/SoalShiftSISOP20_modul2_E02/soal3/jpg")` untuk membuka folder jpg dan mengembalikan pointer dari tipe DIR.
+ `char dir[100] = "/home/qqdnada/SoalShiftSISOP20_modul2_E02/soal3/jpg/", dir2[100], dir3[100]="/home/qqdnada/SoalShiftSISOP20_modul2_E02/soal3/indomie/"` inisialisasi array `dir` yang menampung path dari folder jpg, inisialisasi array `dir2` untuk menampung path dari file/direktori yang akan dipindahkan dari folder jpg, dan inisialiasi array `dir3` yang menampung path dari folder indomie.

Perulangan `while((entry=readdir(folder1)))` digunakan untuk mendaftarkan semua file/direktori pada folder jpg. Tipe file dapat diketahui dengan `entry->d_type` dimana 4 menunjukkan file dan 8 menunjukkan direktori. Nama dari file dapat diketahui dengan `entry->d_name`.

Agar direktori "." dan ".." tidak termasuk direktori yang dipindahkan dalam folder indomie digunakanlah `if (!strcmp (entry->d_name, "."))` dan `if (!strcmp (entry->d_name, ".."))`. Untuk menyimpan path dari file/folder pada folder jpg, digunakan `strcpy(dir2,dir)` yang menyalin array `dir` yang berisi path dari folder jpg ke array `dir2` dan `strcat(dir2,entry->d_name)` yang menambahkan nama file/direktori pada array `dir2`. Setelah itu, program akan membuat child process kelima untuk memindahkan semua file/direktori dari folder jpg ke folder yang sesuai dengan permintaan soal (poin (c)).

```c
if (child_id5 == 0 && entry->d_type == 8) {
    char *argv4[] = {"mv", dir2,"/home/qqdnada/SoalShiftSISOP20_modul2_E02/soal3/sedaap/", NULL};
    execv("/bin/mv", argv4);
}
```
Kode di atas akan memindahkan file ke dalam folder sedaap. Sedangkan kode di bawah ini akan memindahkan direktori ke dalam folder indomie.
```c
if (child_id5 == 0 && entry->d_type == 4) {
    char *argv5[] = {"mv", dir2,"/home/qqdnada/SoalShiftSISOP20_modul2_E02/soal3/indomie/", NULL};
    execv("/bin/mv", argv5);
}
```
Setelah selesai memindahkan folder, jangan lupa untuk menutup direktori dengan `closedir(folder1)`.

Untuk menyelesaikan poin d, terlebih dahulu kita harus menunggu child process keempat menyelesaikan tugasnya dengan `while ((wait(&status4)) > 0)`. Setelah itu, untuk membuat file coba1.txt dan coba2.txt pada folder-folder yang telah dipindahkan ke dalam folder indomie, kita gunakan kode di bawah ini. Adapun kode berikut ini terdapat dalam perulangan `while((entry=readdir(folder)))` dengan `folder = opendir("/home/qqdnada/SoalShiftSISOP20_modul2_E02/soal3/indomie")`.
```c
pid_t child_id6;
int status6;

child_id6 = fork();

if (child_id6 < 0) exit(0);

if (child_id6 == 0) {
    strcpy(dir2,dir);
    strcat(dir2,entry->d_name);
    strcat(dir2,"/coba1.txt");
    char *argv6[] = {"touch",dir2, NULL};
    execv("/usr/bin/touch", argv6);  
}
                        
else {
                            
    while((wait(&status6)) > 0);

    sleep(3);

    pid_t child_id7;
    child_id7 = fork();

    if (child_id7 < 0) exit(0);

    if (child_id7 == 0) {
        strcpy(dir2,dir);
        strcat(dir2,entry->d_name);
        strcat(dir2,"/coba2.txt");
        char *argv7[] = {"touch",dir2, NULL};
        execv("/usr/bin/touch", argv7);
    }
}
```
+ `child_id6 = fork()` membuat child process keenam yang akan membuat file coba1.txt.
+ `if (child_id6 == 0)` jika child process keenam berhasil dibuat maka `dir` yang berisi path ke folder indomie (`/home/qqdnada/SoalShiftSISOP20_modul2_E02/soal3/indomie/"`) akan disalin ke dalam array `dir2` kemudian array `dir2` ini akan ditambahkan nama folder yang terbaca pada `entry=readdir(folder)` dengan `strcat(dir2,entry->d_name)` dan ditambahkan lagi dengan nama file /coba1.txt agar coba1.txt berada dalam folder yang namanya sedang terbaca dengan `strcat(dir2,"/coba1.txt")`.
+ `char *argv6[] = {"touch",dir2, NULL}` dan `execv("/usr/bin/touch", argv6)` membuat file kosong coba1.txt.

Agar tiga detik setelah dibuatnya file coba1.txt file coba2.txt dibuat, maka terlebih dahulu kita harus menunggu child process keenam selesai lalu programnya kita `sleep(3)` selama tiga detik. Kemudian kita buat child process ketujuh yang akan membuat file coba2.txt.
