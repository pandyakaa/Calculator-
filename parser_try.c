#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "array.c"
#include "type.h"


void expect(TabChar *L, string str, int *count, char token, boolean *c);//
void parser(TabChar *L, string str, int *count, boolean *c);
void S(TabChar *L, string str, int *count, boolean *c);
void E(TabChar *L, string str, int *count, boolean *c);
void Eprime(TabChar *L, string str, int *count, boolean *c);
void F(TabChar *L, string str, int *count, boolean *c);//
void G(TabChar *L, string str, int *count, boolean *c);
void H(TabChar *L, string str, int *count, boolean *c);


void expect(TabChar *L, string str, int *count, char token, boolean *c){
	if (*c){
	    if (str.s[*count] == token){
	        AddAsLastEl(L, str.s[*count]);
	        *count += 1;
	    }
	    else{
	        *c = false;
	        printf("\nINVALID SYNTAX, expected {%c}, got {%c}\n", token, str.s[*count]);
	        //break;
	    }
	}
}

void parser(TabChar *L, string str, int *count, boolean *c){
	if (*c){
		S(L, str, count, c);
	    expect(L, str, count, '.', c);
	}   
}

void S(TabChar *L, string str, int *count, boolean *c){
    //printf("\nchar S now %c: ", str.s[*count]);
    if(*c){
	    if (str.s[*count] == '-'){
	        //printf("now: %c", str.s[*count]);
	        AddAsLastEl(L, str.s[*count]);
	        //PrintForward(*L);
	        *count += 1;
	    }
	    E(L, str, count, c);
	}
}

void E(TabChar *L, string str, int *count, boolean *c){
    //printf("\nchar E now %c: ", str.s[*count]);
    if(*c){
        F(L, str, count, c);
        Eprime(L, str, count, c);
    }
    //else
        //break;
}

void Eprime(TabChar *L, string str, int *count, boolean *c){
	if(*c){
	    if ((str.s[*count] == '+') || (str.s[*count] == '-') || (str.s[*count] == '*') || (str.s[*count] == '/') || (str.s[*count] == '^')){
	        AddAsLastEl(L, str.s[*count]);
	        *count += 1;
	        E(L, str, count, c);
	        Eprime(L, str, count, c);  
	    }
	}
}

void F(TabChar *L, string str, int *count, boolean *c){
    int i;

    char num[] = "1234567890";

    i = 0;

    //printf("\nchar now F %c: ", str.s[*count]);
    if(*c){
	    while (str.s[*count] != num[i])
	        i += 1;
	    if (i <= 9){
	        //printf("now:%d")
	        AddAsLastEl(L, str.s[*count]);
	        *count += 1; 
	        G(L, str, count, c);
	    }
	    else if (str.s[*count] ==  '('){
	        AddAsLastEl(L, str.s[*count]);
	        *count += 1;
	        //printf("\nchar now F %c: ", str.s[*count]);
	        if (str.s[*count] == '-'){
	            AddAsLastEl(L, str.s[*count]);
	            *count += 1;
	        }
	        //printf("\nchar now F %c: ", str.s[*count]);
	        E(L, str, count, c);
	        expect(L, str, count, ')', c);
	    }
	    else{
	        if (*count != 0){
	            *c = false;
	            printf("\nINVALID SYNTAX. found {%c} after {%c}.\n", str.s[*count], Elmt(*L,(NbElmt(*L))));
	            //break;
	        }
	        else{
	            *c = false;
	            printf("\nINVALID SYNTAX. Found {%c} in the beginning.\n", str.s[*count]);
	            //break;
	        }
	    }
	}
}

void G(TabChar *L, string str, int *count, boolean *c){
    char num[] = "1234567890";
    int i = 0;

    //printf("\nchar now G %c: ", str.s[*count]);
    if (*c){
	    if(str.s[*count] == ','){
	        AddAsLastEl(L, str.s[*count]);
	        *count += 1;
	        while (str.s[*count] != num[i])
	            i += 1;
	        if (i <= 9){
	            AddAsLastEl(L, str.s[*count]);
	            *count += 1; 
	            H(L, str, count, c);
	        }
	    }
	    else{
	        while (str.s[*count] != num[i])
	            i += 1;
	        if (i <= 9){
	            //printf("now:%d")
	            AddAsLastEl(L, str.s[*count]);
	            *count += 1; 
	            G(L, str, count, c);
	        }
	    }
	}
}

void H(TabChar *L, string str, int *count, boolean *c){
    char num[] = "1234567890";
    int i = 0;
    
    if(*c){
	    while (str.s[*count] != num[i])
	        i += 1;
	    if (i <= 9){
	        AddAsLastEl(L, str.s[*count]);
	        *count += 1; 
	        H(L, str, count, c);
	    }
	}
}

