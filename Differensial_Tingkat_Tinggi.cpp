#include <iostream>
#include <conio.h>
#include <math.h>
#include <windows.h>

using namespace std;

/*-----------------------------------< PEMBATAS LUAR >-----------------------------------*/

//Deklarasi Variabel Global
double a,b,h,k,x,fx,fx1,fx2,e,f1,f2;
int i,n;
char pilihan;

/*-----------------------------------< PEMBATAS LUAR >-----------------------------------*/

//Deklarasi Void
void program_utama();
void opsi();

/*-----------------------------------< PEMBATAS LUAR >-----------------------------------*/

//UTAMA
int main(){
	system("color F");
	program_utama();
	opsi();
}

/*-----------------------------------< PEMBATAS LUAR >-----------------------------------*/

//VOID PENGATUR KOORDINAT
void gotoxy(int x, int y){
	COORD k;
	k.X = x;
	k.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),k);
}

/*-----------------------------------< PEMBATAS LUAR >-----------------------------------*/

//Operasi f(x)
double f(double x){
	return (4*x+5*pow(x,2))+8*pow(x,3)+15;
}

/*-----------------------------------< PEMBATAS LUAR >-----------------------------------*/

//Operasi f"(x)
double FX1(double x){
	return ((4*x+(5*pow(x,2))+(8*pow(x,3))+15-(2*h))-((4*x+(5*pow(x,2))+(8*pow(x,3))+15))+((4*x+(5*pow(x,2))+(8*pow(x,3))+15+(2*h)))/4*pow(h,2));
}

/*-----------------------------------< PEMBATAS LUAR >-----------------------------------*/

//Operasi [Eksak](x)
double fek(double x){
	return (4+10*x+24*pow(x,2));
}

/*-----------------------------------< PEMBATAS LUAR >-----------------------------------*/

//VOID PROGRAM UTAMA
void program_utama(){
	system("cls");
	cout<<" ______________________________________________________"<<endl;
	cout<<"|               MATA KULIAH METODE NUMERIK             |"<<endl;
	cout<<"|             -[DIFFERENSIAL TINGKAT TINGGI]-          |"<<endl;
	cout<<"| ==================================================== |"<<endl;
	cout<<"|             NAMA : DEVAN CAKRA MUDRA WIJAYA          |"<<endl;
	cout<<"|______________________________________________________|"<<endl<<endl;;	

	cout<<" Masukkan batas bawah (a)	= "; cin>>a;
	cout<<" Masukkan batas atas (b)	= "; cin>>b;
	cout<<" Masukkan toleransi error (h)	= ";cin>>h;
	cout<<" Masukkan iterasi (n)		= ";cin>>n;
	
	f1=f(a);
	f2=f(b);
	
	cout<<endl;
	gotoxy(0,16);cout<<" __________________________________________________________________________________________________________________________________________________________________________"<<endl;
	gotoxy(0,17);cout<<"|   n	|         a	        |       b       |        x       |          f(x)	   |         f''(x)         |         f[Eksak](X)       |          Error           |"<<endl;
	gotoxy(0,18);cout<<"|_______|_______________________|_______________|________________|_________________________|________________________|___________________________|__________________________|"<<endl;
	//perulangan
	i=0;
	x=a;
	do{
		//x
		x=x+h;
		
		//fx
		fx=f(x);
		
		//f"(x)
		fx1=FX1(x);
		
		//[Eksak](x)
		fx2=fek(x);
	
		//Error
		e=fx2-fx1;	
	
		printf("|   %d	|       %.6f	|    %.6f	|     %.6f 	 |         %.6f	   |        %.6f	    |          %.6f         |         %.6f	|\n",i+1,a,b,x,fx,fx1,fx2,e);
		
		if(f1<0){
			//b
			b=x;
			//f(b)
			f2=f(b);
		}
		else{
			//a
			a=x;
			//f(a)
			f1=f(a);
		}		
		i++;
	}while(i<n);
	cout<<"|_______|_______________________|_______________|________________|_________________________|________________________|___________________________|__________________________|"<<endl;		

	//output error
	if (e<0){
		e=fabs(e);
		printf(" Nilai error = %.6lf\n",e);
	}
	else{
		printf(" Nilai error = %.6lf\n",e);
	}
	
	cout<<endl<<endl;
	cout<<" [Keterangan] :"<<endl;
	cout<<" __________________________________________________________________________________ "<<endl;
	cout<<"| Hasil perhitungan differensial tingkat tinggi berhasil ditampilkan.....          |"<<endl;
	cout<<"|__________________________________________________________________________________|"<<endl<<endl<<endl;
	getch();
}

/*-----------------------------------< PEMBATAS LUAR >-----------------------------------*/

//VOID OPSI
void opsi(){
	system("cls");
	gotoxy(55,18);cout<<"+===========================================================+"<<endl;
	gotoxy(55,19);cout<<"|                         ULANGI LAGI ?                     |"<<endl;
	gotoxy(55,20);cout<<"+==============================+============================+"<<endl;
	gotoxy(55,21);cout<<"|              YA[Y]           |            TIDAK[N]        |"<<endl;
	gotoxy(55,22);cout<<"+==============================+============================+"<<endl;
	gotoxy(55,23);cout<<" Masukkan pilihan = ";cin>>pilihan;
	
	if(pilihan=='y' || pilihan=='Y'){
		system("cls");
		main();
	}
	else if(pilihan=='n' || pilihan=='N'){
		system("cls");
		cout<<endl;
		gotoxy(45,2);cout<<"+=============================================================================+"<<endl;
		gotoxy(45,3);cout<<"|    Terimakasih telah menggunakan Aplikasi Differensial Tingkat Tinggi....   |"<<endl;
		gotoxy(45,4);cout<<"+==============+================================================+=============+\n\n\n"<<endl;
		getch();
		exit(0);
	}
	else{
		system("cls");
		cout<<endl;
		cout<<"[Keterangan] :"<<endl;
		cout<<" ______________________________________________________ "<<endl;
		cout<<"| ERROR SYSTEM !!!                                     |"<<endl;
		cout<<"| Pilihan tidak sesuai...                              |"<<endl;
		cout<<"| Akan dialihkan ke menu dalam waktu beberapa detik... |"<<endl;
		cout<<"|______________________________________________________|"<<endl<<endl<<endl;
		Sleep(5000);
		main();
	}
}//Copyright (c) Differensial Tingkat Tinggi by Devan All Rights Reserved
