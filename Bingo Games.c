#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void menu();
void help();
void ask(int x);
void game(int a[], int b[], int x, int y, int z);
void hasil(int x, int y, int z);

void shwtab(int ar[],int x);

void intab(int ar[],int x);
void inurut(int ar[]);
void intabgangen(int ar[]);

void randintab(int ar[]);
void randgangen(int ar[]);

void cleantab();

int checker(int ar[]);

int tabel[5][25];
int wincount1 = 0;
int wincount2 = 0;

int main()
{
    srand(time(0));
    int pil, x;
    system("cls");
    cleantab();
    menu();
    scanf("%i",&pil);
    switch (pil)
    {
    case 1 :
        system("cls");
        ask(1);
        scanf("%i",&x);
        if(x==1)
        {
            intab(tabel[0],1);
        }
        if(x==2)
        {
            inurut(tabel[0]);
        }
        if(x==3)
        {
            intabgangen(tabel[0]);
        }
        if(x==4)
        {
            randintab(tabel[0]);
        }
        ask(2);
        scanf("%i",&x);
        if (x==1)
        {
            randintab(tabel[1]);
        }
        if (x==2)
        {
            randgangen(tabel[1]);
        }
        if (x==3)
        {
            ask(1);
            scanf("%i",&x);
            if(x==1)
            {
                intab(tabel[1],0);
            }
            if(x==2)
            {
                inurut(tabel[1]);
            }
            if(x==3)
            {
                intabgangen(tabel[1]);
            }
            if(x==4)
            {
                randintab(tabel[1]);
            }
        }
        ask(0);
        scanf("%i",&x);
        game(tabel[0],tabel[1],1,0,x);
        hasil(1,0,x);
        break;
    case 2 :
        system("cls");
        ask(1);
        scanf("%i",&x);
        if(x==1)
        {
            intab(tabel[0],1);
        }
        if(x==2)
        {
            inurut(tabel[0]);
        }
        if(x==3)
        {
            intabgangen(tabel[0]);
        }
        if(x==4)
        {
            randintab(tabel[0]);
        }
        ask(1);
        scanf("%i",&x);
        if(x==1)
        {
            intab(tabel[1],2);
        }
        if(x==2)
        {
            inurut(tabel[1]);
        }
        if(x==3)
        {
            intabgangen(tabel[1]);
        }
        if(x==4)
        {
            randintab(tabel[1]);
        }
        ask(0);
        scanf("%i",&x);
        game(tabel[0],tabel[1],1,2,x);
        hasil(1,2,x);
        break;
    case 3 :
        system("cls");
        ask(2);
        scanf("%i",&x);
        if (x==1)
        {
            randintab(tabel[0]);
        }
        if (x==2)
        {
            randgangen(tabel[0]);
        }
        if (x==3)
        {
            ask(1);
            scanf("%i",&x);
            if(x==1)
            {
                intab(tabel[0],-1);
            }
            if(x==2)
            {
                inurut(tabel[0]);
            }
            if(x==3)
            {
                intabgangen(tabel[0]);
            }
            if(x==4)
            {
                randintab(tabel[0]);
            }
        }
        ask(2);
        scanf("%i",&x);
        if (x==1)
        {
            randintab(tabel[1]);
        }
        if (x==2)
        {
            randgangen(tabel[1]);
        }
        if (x==3)
        {
            ask(1);
            scanf("%i",&x);
            if(x==1)
            {
                intab(tabel[1],-2);
            }
            if(x==2)
            {
                inurut(tabel[1]);
            }
            if(x==3)
            {
                intabgangen(tabel[1]);
            }
            if(x==4)
            {
                randintab(tabel[1]);
            }
            else
            {
                intab(tabel[1],-2);
            }
        }
        else
        {
            randintab(tabel[1]);
        }
        ask(0);
        scanf("%i",&x);
        game(tabel[0],tabel[1],-1,-2,x);
        hasil(-1,-2,x);
        break;
    case 4 :
        help();
        break;
    case 5 :
        exit(0);
        break;
    }
    main();
}

// Menujukkan menu utama dri game
void menu()
{
    printf("\n\n\n                                                   [ B I N G O ]\n\n");
    printf("                                     ===========================================\n");
    printf("                                    ||                                         ||\n");
    printf("                                    ||          1. Player vs Computer          ||\n");
    printf("                                    ||          2. Player vs Player            ||\n");
    printf("                                    ||          3. Computer vs Computer        ||\n");
    printf("                                    ||          4. Help                        ||\n");
    printf("                                    ||          5. Exit                        ||\n");
    printf("                                    ||                                         ||\n");
    printf("                                     ===========================================\n");
    printf("\n                                                    Pilih : ");

}

// Menunjukkan pertanyaan tertentu dalam menginput player ataupun komputer, dan pertanyaan jumlah permainan
void ask(int x)
{
    system("cls");
    if (x==0)
    {
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t=========================\n");
        printf("\t\t\t\t\t\t||                     ||\n");
        printf("\t\t\t\t\t\t||  Jumlah permainan?  ||\n");
        printf("\t\t\t\t\t\t||                     ||\n");
        printf("\t\t\t\t\t\t=========================\n\n");
        printf("\t\t\t\t\t\t\tPilih : ");
    }
    if (x==1)
    {
        printf("\n\n\n\n\n");
        printf("\t\t\t\t\t==================================\n");
        printf("\t\t\t\t\t||  Jenis input?                ||\n");
        printf("\t\t\t\t\t||                              ||\n");
        printf("\t\t\t\t\t||  1. Input manual             ||\n");
        printf("\t\t\t\t\t||  2. Input urut(1-25)         ||\n");
        printf("\t\t\t\t\t||  3. Input urut ganjil genap  ||\n");
        printf("\t\t\t\t\t||  4. Input random             ||\n");
        printf("\t\t\t\t\t||                              ||\n");
        printf("\t\t\t\t\t==================================\n\n");
        printf("\t\t\t\t\t\tPilih : ");
    }
    if (x==2)
    {
        printf("\n\n\n\n\n");
        printf("\t\t\t\t\t==============================\n");
        printf("\t\t\t\t\t||  Jenis input komputer    ||\n");
        printf("\t\t\t\t\t||                          ||\n");
        printf("\t\t\t\t\t||  1. Total random         ||\n");
        printf("\t\t\t\t\t||  2. Random ganjil genap  ||\n");
        printf("\t\t\t\t\t||  3. Aturan player        ||\n");
        printf("\t\t\t\t\t||                          ||\n");
        printf("\t\t\t\t\t==============================\n\n");
        printf("\t\t\t\t\t\tPilih : ");
    }
}

// Menunjukkan penjelasan game
void help()
{
    system("cls");
    printf("\n");
    printf("\t\t\t------------------------------------------------------------------\n");
    printf("\t\t\t||                                                              ||\n");
    printf("\t\t\t||   BINGO adalah game keberuntungan yang biasa dimainkan       ||\n");
    printf("\t\t\t||   banyak orang. Dengan angka yang random, orang berharap     ||\n");
    printf("\t\t\t||   memenangkan BINGO                                          ||\n");
    printf("\t\t\t||                                                              ||\n");
    printf("\t\t\t||   Dalam game ini pemain menginout angka 1-25 secara random   ||\n");
    printf("\t\t\t||   tanpa angka yang sama. Jika tidak memenuhi syarat maka     ||\n");
    printf("\t\t\t||   akan muncul peringatan input salah. Setelah input angka    ||\n");
    printf("\t\t\t||   maka game akan dimulai. Angka yang muncul akan random.     ||\n");
    printf("\t\t\t||                                                              ||\n");
    printf("\t\t\t||   Pemain dapat memenangkan game BINGO jika mendapat Line.    ||\n");
    printf("\t\t\t||   Line tersebut dapa berbentuk vertikal, horizotal, atau     ||\n");
    printf("\t\t\t||   Diagonal.                                                  ||\n");
    printf("\t\t\t||                                                              ||\n");
    printf("\t\t\t||         * * * * *       *           *                        ||\n");
    printf("\t\t\t||                         *             *                      ||\n");
    printf("\t\t\t||                         *               *                    ||\n");
    printf("\t\t\t||                         *                 *                  ||\n");
    printf("\t\t\t||                         *                   *                ||\n");
    printf("\t\t\t||                                                              ||\n");
    printf("\t\t\t||   Di game ini tersedia player vs player, dan player vs       ||\n");
    printf("\t\t\t||   computer. Jika melawan Computer maka musuh akan diinput    ||\n");
    printf("\t\t\t||   secara random tabelnya.                                    ||\n");
    printf("\t\t\t||                                                              ||\n");
    printf("\t\t\t||   Tekan apa saja untuk keluar                                ||\n");
    printf("\t\t\t||                                                              ||\n");
    printf("\t\t\t------------------------------------------------------------------\n");
    printf(" \n");

    getchar(); getchar();
}

// Modular utama dari game
//
// 2 array digunakan untuk dipertandingkan, 2 integer dipakai untuk menunjukkan player atau kompter
// integer z digunakan untuk menunjukkan banyaknya permainan akan diulang
// Game berjalan dengan clear screen dan sleep agar terlihat seperti animasi yang bergerak
//
// pertama game akan menyimpan tabel 0 dan tabel 1 ke tabel 3 dan ke tabel 4
// dummy array ini dipakai untuk menyimpan array yg akan dipakai berkali-kali karena akan berubah saat dimainkan
//
// tabel 2 akan diisi dengan angka yang random, angka ini akan menjadi penentu permainan
//
// Game berjalan secara otomatis, tidak perlu ada input macam-macam
// Saat game berjalan angka akan dimunculkan dari tabel 2
// pada saat tabel 2 dikeluarkan maka angka yang sama dengan tabel 2 di tabel 1 dan tabel 3 akan diubah menjadi 99
// pada show tabel, 99 akan ditulis sebagai x
//
// setelah dibuat x, lalu tabel diperiksa. jika tabel sudah membentuk garis BINGO maka ditemukan pemenangnya dan game akan berhenti
// Jika player 1 menang maka win 1 = 1, jika 2 maka win2 =2. Jika keduanya menang bersamaan maka hasilnya akan seri
//
// Jika z nilainya lebih dari 1, maka game akan diulangi dengan fungsi yang rekursif
//
// wincount1 dan wincount2 menunjukkan banyaknya kemenangan yang terjadi selama game diulang berkali-kali
void game(int a[], int b[], int x, int y, int z)
{
    int win1 = 0;
    int win2 = 0;

    for (int g=0;g<25;g++)
    {
        tabel[3][g]=a[g];
    }
    for (int g=0;g<25;g++)
    {
        tabel[4][g]=b[g];
    }
    randintab(tabel[2]);

    for (int i=0; i<25; i++)
    {
        system("cls");
        printf("\n\n\n                                            Angka yang muncul adalah  %i\n\n",tabel[2][i]);
        shwtab(a,x);
        printf("\n\n");
        shwtab(b,y);
        printf("\n");
        Sleep(1000);
        for (int j=0; j<25; j++)
        {
            if (a[j]==tabel[2][i])
            {
                a[j]=99;
            }
        }
        system("cls");
        printf("\n\n\n                                            Angka yang muncul adalah  %i\n\n",tabel[2][i]);
        shwtab(a,x);
        printf("\n\n");
        shwtab(b,y);
        printf("\n");
        Sleep(1000);
        for (int j=0; j<25; j++)
        {
            if (b[j]==tabel[2][i])
            {
                b[j]=99;
            }
        }
        system("cls");
        printf("\n\n\n                                            Angka yang muncul adalah  %i\n\n",tabel[2][i]);
        shwtab(a,x);
        printf("\n\n");
        shwtab(b,y);
        printf("\n");
        Sleep(1000);
        win1=checker(a);
        win2=checker(b);
        if (win1==1||win2==1)
        {
            i=99;
        }
    }
    printf("\n                                                     BINGO!\n\n");
    if (win1==1&&win2==1)
    {
        printf("                                                  HASILNYA SERI");
    }
    else if (win1==1)
    {
        wincount1++;
        if (x==-1)
        {
            printf("                                                COMPUTER1 MENANG!");
        }
        if (x==1)
        {
            printf("                                                 PLAYER1 MENANG!");
        }
    }
    else if (win2==1)
    {
        wincount2++;
        if (y==0)
        {
            printf("                                                COMPUTER MENANG");
        }
        if (y==-2)
        {
            printf("                                                COMPUTER2 MENANG");
        }
        if (y==2)
        {
            printf("                                                 PLAYER2 MENANG");
        }
    }
    for (int g=0;g<25;g++)
    {
        a[g]=tabel[3][g];
    }
    for (int g=0;g<25;g++)
    {
        b[g]=tabel[4][g];
    }
    win1=0;
    win2=0;
    printf("\n\n                                               Tunggu 3 detik...");
    Sleep(3000);
    system("cls");
    if (z>1)
    {
        game(a,b,x,y,z-1);
    }

}

// Menunjukkan hasil permainan
//
// Bila game diatur lebih dari 1 kali, maka hasil dari permainan akan dimunculkan pada hasil
// x dan y menunjukkan pemain ataupun komputer. z menunjukkan berapa kali game dimainkan
//
// hasil seri dari game didapat dari jumlah permainan - menang1 - menang2
void hasil(int x, int y, int z)
{
    printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t=========================\n");
        printf("\t\t\t\t\t\t||    Hasil menang     ||\n");
        printf("\t\t\t\t\t\t||                     ||\n");
        printf("\t\t\t\t\t\t||   ");
        if (x==1)
        {
            printf("Player1   : ");
        }
        if (x==-1)
        {
            printf("Computer1 : ");
        }
        if(wincount1<10)
        {
            printf(" %i    ||\n",wincount1);
        }
        if(wincount1>10)
        {
            printf("%i    ||\n",wincount1);
        }
        printf("\t\t\t\t\t\t||   ");
        if (y==0)
        {
            printf("Computer  : ");
        }
        if (y==2)
        {
            printf("Player2   : ");
        }
        if (y==-2)
        {
            printf("Computer2 : ");
        }
        if(wincount2<10)
        {
            printf(" %i    ||\n",wincount2);
        }
        if(wincount2>10)
        {
            printf("%i    ||\n",wincount2);
        }
        printf("\t\t\t\t\t\t||   ");
        printf("Seri      : ");
        if(z-wincount1-wincount2<10)
        {
            printf(" %i    ||\n",z-wincount1-wincount2);
        }
        if(z-wincount1-wincount2>10)
        {
            printf("%i    ||\n",z-wincount1-wincount2);
        }
        printf("\t\t\t\t\t\t||                     ||\n");
        printf("\t\t\t\t\t\t=========================\n\n");
        printf("\t\t\t\t\t  Tekan apa saja untuk kembali...");
        wincount1=0;
        wincount2=0;
        getchar();
        getchar();
}

// Menginput tabel secara manusal
//
// Menginput tabel dengan mengisi arraynya satu persatu
// variabel salah digunakan untuk menunjukkan apakah input salah
// Input dalam bingo ada 2 syarat yaitu angka diantara 1-25 dan tidak boleh berulang
// Bila tidak memenuhi syarat diatas maka salah = 1 dan input harus diulang di tempat yang sama dengan i--
// Untuk memeriksa apakah ada array yang sama, setelah menginput maka array yang diinput akan dibandingkan dengan array sebelumnya
// Jika sama dengan array sebelumnya maka akan dianggap salah
void intab(int ar[],int x)
{
	int salah=0;
	system("cls");
	for (int i = 0; i < 25; i++)
	{
	    printf("\n\n\n");
		shwtab(ar,x);
		printf("\n");
		if (salah==1)
		{
			printf("\n                                                   Input salah\n");
			salah=0;
		}
		else
        {
            printf("\n\n");
        }
		if (i<9)
		{
			printf("\n                                    Input angka 1-25, tidak boleh angka sama\n");
			printf("                                    Input kotak 0%i = ",i+1);
			scanf("%i",&ar[i]);
			system("cls");
		}
		else
		{
			printf("\n                                    Input angka 1-25, tidak boleh angka sama\n");
			printf("                                    Input kotak %i = ",i+1);
			scanf("%i",&ar[i]);
			system("cls");
		}

		if (ar[i]<=0||ar[i]>25)
		{
			salah=1;
		}
		for (int j = i; j > 0; j--)
		{
			if (ar[i]==ar[j-1])
			salah=1;
		}
		if (salah==1)
		{
			i--;
		}

	}

}

// Input urut
//
// Langsung menginput 1 sampai 25 secara utur di array
void inurut(int ar[])
{
    for (int i=0; i<25; i++)
    {
        ar[i]=i+1;
    }
}

// Random input tabel
//
// Mengisi array dengan angka yang random
// karena random maka harus diberi syarat
// random/25 lalu +1 yang artinya angka akan dioutput diantara 1-25
// Menggunakan variabel salah agar bila angkan berulang maka akan diambil angka baru sampai tepat tidak berulang
void randintab(int ar[])
{
    int salah=0;

	for (int i = 0; i < 25; i++)
	{
	    ar[i]=(rand()%25)+1;
	    for (int j = i; j > 0; j--)
        {
            if (ar[i]==ar[j-1])
            {
                salah=1;
            }
        }
        if (salah==1)
        {
            i--;
            salah=0;
        }
	}
}

// Random ganjil genap
//
// Mirip dengan random input tab, namun diberi syarat salah tambahan
// angka pada array ganjil hanya akan ada bilangan genap, dan sebaliknya
// hasilnya output random namun akan ganjil dan genap bergantian sampai akhir
void randgangen(int ar[])
{
    int salah=0;

	for (int i = 0; i < 25; i++)
	{
	    ar[i]=(rand()%25)+1;
	    if (i%2==0)
        {
            if (ar[i]%2==0)
            {
                salah=1;
            }
        }
        if (i%2==1)
        {
            if (ar[i]%2==1)
            {
                salah=1;
            }
        }
	    for (int j = i; j > 0; j--)
        {
            if (ar[i]==ar[j-1])
            {
                salah=1;
            }
        }
        if (salah==1)
        {
            i--;
            salah=0;
        }
	}
}

// Input tab ganjil genap
//
// Input secara berurutan, namun 13 angka awal hanya akan ada bilangan ganjil
// Lalu berikutnya hanya ada billangan genap
void intabgangen(int ar[])
{
    for (int i = 0; i < 25; i++)
    {
        if (i<13)
        {
            ar[i]= 1 + i*2;
        }
        else
        {
            ar[i]= (i-12)*2;
        }
    }
}

// Show table
//
// Output yang menunjukkan tabel
// int ar[] adalah array yang ditunjukkan, int x adalah pengenal.
// int x menunjukkan tabel ini milik siapa, player ataupun komputer
// output tabel dijalankan dengan loop, setiap 5 angka maka akan di enter
// khusus untuk angka 99, akan dioutput sebagai " x "
void shwtab(int ar[],int x)
{
    if (x==-1)
    {
        printf("\n                                                    COMPUTER1       \n");
    }
    if (x==-2)
    {
        printf("\n                                                    COMPUTER2       \n");
    }
    if (x==0)
    {
        printf("\n                                                    COMPUTER         \n");
    }
    if (x==1)
    {
        printf("\n                                                     PLAYER1       \n");
    }
    if (x==2)
    {
        printf("\n                                                     PLAYER2       \n");
    }
    printf("                                              ---------------------\n");
    for (int j = 0; j < 25; j++)
    {
        if (j%5==0)
        {
            printf("                                              |");
        }
        if (ar[j]<10)
        {
            printf(" 0%i|",ar[j]);
        }
        else if (ar[j]==99)
        {
            printf(" x |");
        }
        else
        {
            printf(" %i|",ar[j]);
        }
        if (j%5==4)
        {
            printf("\n");
        }
    }
    printf("                                              ---------------------");
}

// Clean table
//
// Membuat seluruh isi array menjadi 0
// Penting karena game akan dilakukan berulang
// Jika tidak dibersihkan, tabel sebelumnya akan membekas di permainan selanjutnya saat input manual
void cleantab()
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 25; j++)
		{
		    tabel[i][j]=0;
		}
	}
}

// Checker
//
// Mengecheck angka 99 bila membentuk pola tertentu
// Saat angka 99 padda array membentuk pola tertentu maka nilai akan di return 1
// bila tidak maka nilai akan di return 0
int checker(int ar[])
{
    int check=0;
    if (ar[0]==99&&ar[1]==99&&ar[2]==99&&ar[3]==99&&ar[4]==99||ar[5]==99&&ar[6]==99&&ar[7]==99&&ar[8]==99&&ar[9]==99||ar[10]==99&&ar[11]==99&&ar[12]==99&&ar[13]==99&&ar[14]==99||ar[15]==99&&ar[16]==99&&ar[17]==99&&ar[18]==99&&ar[19]==99||ar[20]==99&&ar[21]==99&&ar[22]==99&&ar[23]==99&&ar[24]==99||ar[0]==99&&ar[5]==99&&ar[10]==99&&ar[15]==99&&ar[20]==99||ar[1]==99&&ar[6]==99&&ar[11]==99&&ar[16]==99&&ar[21]==99||ar[2]==99&&ar[7]==99&&ar[12]==99&&ar[17]==99&&ar[22]==99||ar[3]==99&&ar[8]==99&&ar[13]==99&&ar[18]==99&&ar[23]==99||ar[4]==99&&ar[9]==99&&ar[14]==99&&ar[19]==99&&ar[24]==99||ar[0]==99&&ar[6]==99&&ar[12]==99&&ar[18]==99&&ar[24]==99||ar[4]==99&&ar[8]==99&&ar[12]==99&&ar[16]==99&&ar[20]==99)
    {
        check=1;
    }
    return check;
}

// PROGRAM INI DIBUAT OLEH :
//
// Mahasiswa Universitas Indonesia, jurusan Teknik komputer
//
// Aufa Dhiya Aydan (1706043260)
// Joshua Evans Todo Sidabutar (1706042850)
//
// contact : josua.white2@gmail.com
