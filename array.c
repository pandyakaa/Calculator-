/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit, 
   memori tabel statik */

#include "boolean.h"
#include "array.h"
#include "stdio.h"


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyArray (TabChar * T) {
	Neff(*T) = 0;
}
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabChar T) {
	return(Neff(T));
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbEl (TabChar T) {
	return (100);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabChar T) {
	return (Neff(T) == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabChar T) {
	return (Neff(T) == IdxMax);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

void TulisIsiTab (TabChar T) {
	int i;
	
	printf("[");
	for (i=1; i<=T.Neff; i++) {
		printf("%c", Elmt(T,i));
		if (i != T.Neff) {
			printf(",");
		}
	}
	printf("]");
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */


boolean SearchB (TabChar T, ElType X) {
	int i;
	boolean Found;
	
	Found = false;
	i = 1;
	while (!Found && (i<=T.Neff)) {
		if (T.TI[i] == X) {
			Found = true;
		}
		i += 1;
	}
	return (Found);
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
/* ********** NILAI EKSTREM ********** */


/* ********** OPERASI LAIN ********** */
void CopyTab (TabChar Tin, TabChar * Tout) {
	int i;
	
	Neff(*Tout) = Tin.Neff;
	for (i = 1; i<=Tin.Neff; i++) {
		Elmt(*Tout,i) = Tin.TI[i];
	}
}
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */


/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabChar * T, ElType X) {
	Neff(*T) += 1;
	Elmt(*T,Neff(*T)) = X;
}
