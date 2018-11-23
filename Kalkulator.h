// File ini merupakan header untuk fungsi dan prosedur yang akan digunakan
// di program utama

#ifndef KALKULATOR_H
#define KALKULATOR_H

// ----------- Include module yang dibutuhkan ------------ //
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "boolean.h"
#include "Stacktop.c"
#include "Stacktval.c"
#include "parser_try.c"
#include "type.h"

	
// ----------- Deklarasi fungsi dan prosedur yang akan digunakan ---------- //

boolean IsNumberValid(char a);
// Mengembalikan true jika input yang dimasukkan antara 0..9
// Mengembalikan false jika kurang dari 0 dan lebih dari 9

int Priority(char op);
// Mengembalikan nilai prioritas dari operator yang dipakai

float applyOp(float a, float b, char op);
// Menghitung 2 buah bilangan dengan operator 

void Value(newstring input,boolean *matherror, float *hasil);
// Mengembalikan nilai dengan tipe float dari stack, dan akan dijadikan
// return dari program utama ini

boolean IsOperatorValid(char c);
// Mengembalikan true jika input char yang dimasukkan mmerupakan operator
// yang valid sesuai spek, yaitu simbol aritmatika biasa (+, -, *, /), perpangkatan (^)

#endif
