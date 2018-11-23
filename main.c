// File ini merupakan main program dari kalkulator

#include "Kalkulator.c"

int main()
    {
        // Kamus Lokal
        newstring inp;
        TabChar readArray;
        string str;
        boolean success;
        int count;
		float hasilakhir;
		boolean errormath;
		string parseinp;
        int i;
		int pilihan;
		
        // Algoritma
        
        success = true;
        char titik[] = ".";
        count = 0;
        errormath = false;
        hasilakhir = 0;
        
        MakeEmptyArray(&readArray);
        
        printf(" SELAMAT DATANG DI KALKULATOR AJAIB \n");
        printf(" Silahkan pilih : \n");
        printf(" 1. Menggunakan kalkulator \n");
        printf(" 2. Exit\n");
        printf(" 3. Credit\n");
        scanf("%d",&pilihan);
        
        while ( pilihan != 2 && pilihan != 3)
        	{
        		printf("Masukkan ekspresi yang akan dihitung : \n");
		        scanf("%s",inp);
		        
		        for(i = 0; i<100; i++){
		        	parseinp.s[i] = inp[i];
				}
				
				strcat(parseinp.s, titik);
		        parser(&readArray, parseinp, &count, &success);
		        
		        if(success)
		        	{
		        		Value(inp,&errormath,&hasilakhir);
		        		
		        		if ( !errormath )
		        			{
		        				printf("Hasilnya adalah %f\n",hasilakhir);
							}
						else
							{
								printf("Math Error\n");
							}
					}
		         else
		        	{
		        		printf("Syntax Error\n");
					}

		        printf(" Silahkan pilih : \n");
		        printf(" 1. Menggunakan kalkulator \n");
		        printf(" 2. Exit\n");
		        printf(" 3. Credit\n");
		        scanf("%d",&pilihan);
			};
		
		if ( pilihan == 3)
			{
				printf("Calculator made by : \n");
				printf("13517003\n");
				printf("13517015\n");
				printf("13517057\n");	
			} 
		
		printf("Thankyou for using this calculator :D \n");
		
			
        
        
        return 0;
    }
