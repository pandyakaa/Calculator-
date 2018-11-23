// Body untuk stackt.h
// Pandyaka Aptanagi / 13517003

#include <stdio.h>
#include "Stacktop.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyOp (Stacktop *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
	{
		// Kamus
		
		// Algoritma
		(*S).TOP = Nil;
		
	};

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyOp (Stacktop S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
	{
		// Kamus
		
		// Algoritma
		return ( (S).TOP == Nil);
		
	};
	
boolean IsFullOp (Stacktop S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
	{
		// Kamus
		
		// Algoritma
		return ((S).TOP == MaxEl);
	};
	
/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushOp (Stacktop * S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
	{
		// Kamus
		
		// Algoritma
		if ( IsEmptyOp(*S) )
			{
				(*S).TOP = 1;
			}
		else
			{
				(*S).TOP = (*S).TOP +1;
			}
		
		InfoTop(*S) = X;
	};

/* ************ Menghapus sebuah elemen Stack ************ */
void PopOp (Stacktop * S, infotype* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
	
	{
		// Kamus
		
		// Algoritma
		*X = InfoTop(*S);
		
		if ( (*S).TOP == 1)
			{
				CreateEmptyOp(S);
			}
		else
			{
				(*S).TOP = (*S).TOP - 1;
			};
	};
