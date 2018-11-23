// File ini merupakan body dari header kalkulator.h , merupakan implementasi dari fungsi dan prosedur yang sudah dideklarasikan di header
// Kelompok : 
// Kelas : K3
// Pandyaka A / 13517003
// I Putu Gede W / 13517015
// Ainun Fitryh V. / 13517057

// -------- Include header --------- //	
#include "Kalkulator.h"
 
// -------- Implementasi fungsi dan prosedur -------- //

boolean IsNumberValid(char a)
// Mengembalikan true jika input yang dimasukkan antara 0..9
// Mengembalikan false jika kurang dari 0 dan lebih dari 9
    {
        // Kamus Lokal

        // Algoritma
        if((int)a-(int)'0'>=0 && (int)a-(int)'0'<=9)
            {
                return true; // Menghasilkan true jika ada string yang di'cast' ke integer, di antara 0-9
            }
        else
            {
                return false;
            };
	};

int Priority(char op)
// Mengembalikan nilai prioritas dari operator yang dipakai
    {
        // Kamus Lokal

        // Algoritma
        if (op == '+'||op == '-') 
            {
                return 1; // Menghasilkan prioritas terendah
            }
        else
        if(op == '*'||op == '/') 
            {
                return 2; // Menghasilkan prioritas yang lebih tinggi dari penjumlahan dan pengurangan
            }
        else
        if(op == '^' )
            {
                return 3; // Menghasilkan prioritas tertinggi, sehingga akan dilakukan terlebih dahulu
            }
        else
            {
                return 0; // default 
            }
    };

float applyOp(float a, float b, char op)
// Menghitung 2 buah bilangan dengan operator 
    {
        // Kamus Lokal

        // Algoritma
        switch(op) // bergantung pada jenis op
            {
                case '+': return a + b;  // Menjumlahkan float a dengan float b
                case '-': return a - b;  // Mengurangi float a dengan float b
                case '*': return a * b;  // Mengalikan float a dengan float b
                case '/': return a / b;  // Membagi float a dengan float b
                case '^': return pow(a,b); // Memangkatkan float a dengan float b
            } 
    };

boolean IsOperatorValid(char c)
// Mengembalikan true jika input char yang dimasukkan mmerupakan operator
// yang valid sesuai spek, yaitu simbol aritmatika biasa (+, -, *, /), perpangkatan (^)
   {
        // Kamus Lokal

        // Algoritma
        if ( c == '*' || c =='/' || c == '+' || c == '-' || c == '^'  )
            {
                return true;
            }
        else    
            {
                return false;
            };
    };

void Value(newstring input, boolean *matherror,float *hasil)
// Mengembalikan nilai dengan tipe float dari stack, dan akan dijadikan
// return dari program utama ini
    {
        // Kamus Lokal
        int i;
        Stacktval ValStack;
        Stacktop OpsStack;
        char opchar;
        float valint;
        char op;
        float val;
        float val1;
        float val2;
        float temp;
        float dec;
        char optemp;
       

        // Algoritma
       CreateEmptyVal(&ValStack); // Membuat empty stack value
       CreateEmptyOp(&OpsStack); // Membuat empty stack operator
       val1 = 0;
       val2 = 0;
       InfoTop(ValStack) = 0;
       i = 0;
       while ( i < strlen(input) ) // membuat loop hingga panjang dari string input
            {

                // Membaca tanda kurung buka //

                if (input[i] == '(') // ketika input = char '('
                    {   
                        PushOp(&OpsStack,input[i]); // akan push '(' ke dalam stack operator
                        i = i +1; // iterator bertambah
                    }
                    
                else
                
                // MEMBACA ANGKA POSITIF //

                if (IsNumberValid(input[i])) // ketika input = number valid
                    {
                    	val = 0; // assign nilai value ke 0
                        while ( i < strlen(input) && IsNumberValid(input[i]))
                            {
                                val = (val * 10) + ( (int)input[i] - (int)'0'); 
                                i = i+1;
                            };
                        
                        if ( input[i] == ',' ) // Cek nilai decimal
                            {
                                dec = 0.1;
                                i = i + 1;

                                 while ( i < strlen(input) && IsNumberValid(input[i]))
                                    {
                                        val = val + dec*( (int)input[i] - (int)'0');
                                        dec = dec  * 0.1;
                                        i = i + 1;
                                    };
                            };
                        
                        // Akan mempush nilai dari string berbentuk angka
                        PushVal(&ValStack,val);
                    }

               else

               // MEMBACA ANGKA NEGATIF //

               if ((IsOperatorValid(input[i-1]) || input[i-1] == '(') && input[i] == '-' && IsNumberValid(input[i+1])  ) // Cek bilangan negatif
                    {
                        val = 0;
                        i = i + 1;

                         while ( i < strlen(input) && IsNumberValid(input[i])) // cek bilangan bulat
                            {
                                val = val * 10 + ( (int)input[i]-(int)'0' );
                                i = i + 1;
                            };
                        
                        if ( input[i] == ',' ) // cek nilai decimal
                            {
                                dec = 0.1;
                                i = i + 1;

                               while ( IsNumberValid(input[i]) )
                                   {
                                       val = val + dec * ( (int)input[i]-(int)'0' );
                                       dec = dec * 0.1;
                                       i = i + 1;
                                   };
                            };

                    val = val * (-1);
                    PushVal(&ValStack,val);

                    }
               else

               // MEMBACA TUTUP KURUNG //

               if ( input[i] == ')' ) // Cek jika nilai input adalah tutup kurung ')' sehingga akan dihitung terlebih dahulu
                    {
                        while (!IsEmptyOp(OpsStack) && InfoTop(OpsStack) != '(')
                            {
                                val2 = InfoTop(ValStack);
                                PopVal(&ValStack,&valint);

                                val1 = InfoTop(ValStack);
                                PopVal(&ValStack,&valint);

                                op = InfoTop(OpsStack);
                                PopOp(&OpsStack,&opchar);

                                if ( op == '/' && val2 == 0 )
		                            {
		                                *matherror = true;
		                                break;
		                           }
		                        else
		                        if ( op == '^' && val1 < 0 && val2 != 0 && val2 < 1 && val2 > -1 )
		                        	{ 
		                               *matherror = true;
		                                break;
		                            }
		                        else
		                        	{
		                        		PushVal(&ValStack,applyOp(val1,val2,op));
									}
                            };

                        // Akan menghitung nilai yang memiliki tanda kurung terlebih dahulu
                        PopOp(&OpsStack,&opchar);
                        i = i + 1;
                    }
                else

                // MENGHITUNG JIKA PANGKAT BERTEMU PANGKAT //

                if ( InfoTop(OpsStack) == '^' && input[i] == '^' ) // Apabila pangkat bertemu pangkat
                    {
                        PushOp(&OpsStack,input[i]);
                        i = i + 1;
                    }
                else
                
                // Jika dibagi dengan 0
                if ( input[i] == '/' && input[i+1] == '0' )
                	{
                		*matherror = true;
                		break;
					}
					
				else
				
				 // MENGHITUNG JIKA ADA OPERATOR YANG LEBIH KUAT
                    {
                        while (!IsEmptyOp(OpsStack) && Priority(InfoTop(OpsStack)) >= Priority(input[i]) ) // Apabila bertemu dengan operator lain yang lebih kecil prioritasnya
                            {
                                val2 = InfoTop(ValStack);
                                PopVal(&ValStack,&valint);

                                val1 = InfoTop(ValStack);
                                PopVal(&ValStack,&valint);

                                op = InfoTop(OpsStack);
                                PopOp(&OpsStack,&opchar);
								
                                if ( op == '/' && val2 == 0 )
		                            {
		                                *matherror = true;
		                                break;
		                           }
		                        else
		                        if ( op == '^' && val1 < 0 && val2 != 0 && val2 < 1 && val2 > -1 )
		                        	{ 
		                               *matherror = true;
		                                break;
		                            }
		                        else
		                        	{
		                        		PushVal(&ValStack,applyOp(val1,val2,op));
									}
                                       
                            };
                            
                        PushOp(&OpsStack,input[i]);
                        i = i +1;
                    };
            };

        // MENGHITUNG SAMPAI STACK OPERATOR EMPTY

        while (!IsEmptyOp(OpsStack)) // Menyelesaikan sampai stack operator empty
                    {
                        val2 = InfoTop(ValStack);
                        PopVal(&ValStack,&valint);

                        val1 = InfoTop(ValStack);
                        PopVal(&ValStack,&valint);

                        op = InfoTop(OpsStack);
                        PopOp(&OpsStack,&opchar);

                         if ( op == '/' && val2 == 0 )
		                            {
		                                *matherror = true;
		                                break;
		                           }
		                        else
		                        if ( op == '^' && val1 < 0 && val2 != 0 && val2 < 1 && val2 > -1 )
		                        	{ 
		                               *matherror = true;
		                                break;
		                            }
		                        else
		                        	{
		                        		PushVal(&ValStack,applyOp(val1,val2,op));
									}
                    };
                    
        	*hasil = InfoTop(ValStack);
    };


