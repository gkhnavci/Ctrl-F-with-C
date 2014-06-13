#include <time.h>
#include<conio.h>
#define MAX 2000000
#include <limits.h>
#include <string.h>
#include <stdio.h>
# define NO_OF_CHARS 256
#define ALPHABET_LEN 256
#define NOT_FOUND patlen
#define max(a, b) ((a < b) ? b : a)
//These our function of algorithms
int brute(char * text  ,char  *pattern);//for brute force algorıthms

int horspool(char *src,char * p);//for horspool

void BM2(char *txt,  char *pat);
clock_t ticcc ;
clock_t toccc ;
char mArray[MAX];//for text			
int t[MAX];//for pattern
int locationsBrute[MAX];
int locationsH[MAX];
int locationsBoyer[MAX];
int tab[NO_OF_CHARS];
int goodSuffix[NO_OF_CHARS];
int badchar[NO_OF_CHARS];
int times=0;
//Main function
int main(){
	 
     FILE *dosyam; 
     char hede; 
     int i  ; 
      for(i=0;i<MAX;i++){
    	locationsBrute[i]=-1;
    	locationsBoyer[i]=-1;
    	locationsH[i]=-1;
    }
     i=0;
     dosyam=fopen("input.html","r" );
	 if(dosyam == 0)
	{
		puts("File does not exist!");
		exit(0);
	}
     do{ 
     hede = getc(dosyam ); 
     mArray[i]=hede;
     i++;
    }while(hede!=EOF ); 
    
    
    char*  p="AT_THAT";
    int index=0; 
    FILE *output=fopen("output.txt","w");
    
    printf("The pattern is %s\n\n\n",p);
    fprintf(output,"The pattern is %s\n\n\n",p);
	/*Time calculate brute force*/
	clock_t tic = clock();
	printf("BRUTE_FORCE ALGORITHMS\n");
	fprintf(output,"BRUTE_FORCE ALGORITHMS\n");
	brute(mArray,p);
    clock_t toc = clock();
    fprintf(output,"Number of character comparisons = %d\n",times);
    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    fprintf(output,"Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	/*Time calculate hoorspool*/
	clock_t ticc = clock();
	printf("\n\nHORSPOOL ALGORITHMS\n");
	fprintf(output,"\n\nHORSPOOL ALGORITHMS\n");
	times=0;
    horspool(mArray,p);
    clock_t tocc = clock();
    fprintf(output,"Number of character comparisons = %d\n",times);
    fprintf(output,"Elapsed: %f seconds\n", (double)(tocc - ticc)/ CLOCKS_PER_SEC);
    printf("Elapsed: %f seconds\n", (double)(tocc - ticc)/ CLOCKS_PER_SEC);
	/*Time calculate Boyeer-Moore*/
    printf("\n\nBOYER_MOORE ALGORITHMS\n");
    fprintf(output,"\n\nBOYER_MOORE ALGORITHMS\n");
    times=0;
	BM2(mArray,p);
    fprintf(output,"Number of character comparisons = %d\n",times);
    fprintf(output,"Elapsed: %f seconds\n", (double)(toccc - ticcc)/ CLOCKS_PER_SEC);
    printf("Elapsed: %f seconds\n", (double)(toccc - ticcc)/ CLOCKS_PER_SEC);
    
    
	fprintf(output,"\n\n =====Badchar table for Boyer and Horspool===== \n  ");	
	printf("\n\n =====Badchar table for Boyer and Horspool===== \n  ");
	for (i=0; i < strlen(p); i++) {
        fprintf(output,"\tfor %c value %d \n",p[i],badchar[p[i]]);
        printf("\tfor %c value %d \n",p[i],badchar[p[i]]);
        
    }
    
    fprintf(output,"\tfor other  characters value is  %d \n",strlen(p));
    printf("\tfor other  characters value is  %d \n",strlen(p));
    
    preBmGs(p, strlen(p), goodSuffix);
	
    i=0;
	
	fprintf(output,"\n\n =====Good sufix table for Boyer===== \n\n");	
	printf("\n\n =====Good sufix table for Boyer===== \n\n");						
    fprintf(output,"     %6   match  %6 shift \n");
    printf("     %6   match  %6 shift \n");
    
    for(i = 0; i<=strlen(p)-1;i++)
    {
    	 fprintf(output,"      %6d  %6d \n", strlen(p)-i-1, goodSuffix[i]);
    	 printf("      %6d  %6d \n", strlen(p)-i-1, goodSuffix[i]);
    	 
	}
    /*HERE BEGINS WRITING CODE OF MARKING*/
    FILE *outputBrute;
	outputBrute=fopen("outputBrute.html","a");
	FILE *outputHdosyam=fopen("outputHorspool.html","a" );
	FILE *outputBoyerDosyam=fopen("outputBoyer.html","a" );
	int o=0;//how many  OCUURENCE  MARK
	int v=0;//this  mARRAY İN the İNDEX
    fprintf(outputBrute," ");
   
   int size=strlen(mArray);
   int size2=strlen(p);
   //Write brute force html file and mark
	while(locationsBrute[o] != -1 || v<size-1){
		
		
		
		if(v==locationsBrute[o]){
			fputs("<MARK>",outputBrute);
		}
		else if(v==locationsBrute[o]+size2){
			
			fputs("</MARK>",outputBrute);
			o++;
		
		}
	
			
		fprintf(outputBrute,"%c",mArray[v]);
		v++;
		
				 
	
		
	}
    
    fclose(outputBrute);
    o=0; v=0;
    //Write horspool html file and mark
    while(locationsH[o] != -1 || v<size-1){
		
		
		
		if(v==locationsH[o]){
			fputs("<MARK>",outputHdosyam);
		    
		}
		else if(v==locationsH[o]+size2){
			
			fputs("</MARK>",outputHdosyam);
			o++;
		
		}
	
			
		fprintf(outputHdosyam,"%c",mArray[v]);
		v++;
		
				 
	
		
	}
    
    fclose(outputHdosyam);
    
    v=0; o=0;
    //Write boyer-moore html file and mark
    while(locationsBoyer[o] != -1 || v<size-1){
		
		
		
		if(v==locationsBoyer[o]){
			fputs("<MARK>",outputBoyerDosyam);
		    
		}
		else if(v==locationsBoyer[o]+size2){
			
			fputs("</MARK>",outputBoyerDosyam);
			o++;
		
		}
	
			
		fprintf(outputBoyerDosyam,"%c",mArray[v]);
		v++;
		
				 
	
		
	}
    
    fclose(outputBoyerDosyam);
    
	return 1;
}


/*Brute force algorithms function*/
int brute(char * text ,char * pattern){
 int n = strlen(text); ;   // n is length of text.
 int m = strlen(pattern) ; // m is length of pattern
 int j;
 int i;
 int l=0;

 for(i=0; i <= (n-m); i++) {
    times++;
    j = 0;
    while ((j < m) && (text[i+j] == pattern[j]) ){
       times++;
       j++;
	}
    
    if (j == m){
     locationsH[l]=i;
     l++;
    }
}
	//Number of comparision characters
	printf("Number of character comparisons = %d\n",times);
    return -1; // no match
}


/*Hoorspol algorıthm function*/
int horspool(char *text,char*pat){
    int l=0;
	int i,j,t,p;
    t=strlen(text);
    p=strlen(pat);
    
    for(i=0;text[i]!=0;i++);//Shift
    t=i;					//Table
    for(i=0;i<pat[i]!=0;i++);//Part
    p=i;

  for(i=0;i<t;i++)
    {
        tab[(int)text[i]]=p;
    }
    for(i=0;i<p-1;i++)
    {
        tab[(int)pat[i]]=p-i-1;
    }
    
    
    i=p-1;
   
   
   
    while(i<t-1){
        for(j=0;j<p;j++){
        	times++;
            if(pat[p-1-j]!=text[i-j]){
                break;
            }
        }
        if(j==p){
            locationsBrute[l]=i+1-p;
            l++;
        }
        i=i+tab[(int)text[i]];
    }
    //Number of comparision characters
	printf("Number of character comparisons = %d\n",times);
    return -1;
}


/*BOYER MOORE and good suffix table*/
void preBmBc(char *x, int m, int bmBc[]) {
   int i;
 
   for (i = 0; i < 256; ++i)
      bmBc[i] = m;
   for (i = 0; i < m - 1; ++i)
      bmBc[x[i]] = m - i - 1;
}
 
void suffixes(char *x, int m, int *suff) {
   int f, g, i;
 
   suff[m - 1] = m;
   g = m - 1;
   for (i = m - 2; i >= 0; --i) {
      if (i > g && suff[i + m - 1 - f] < i - g)
         suff[i] = suff[i + m - 1 - f];
      else {
         if (i < g)
            g = i;
         f = i;
         while (g >= 0 && x[g] == x[g + m - 1 - f])
            --g;
         suff[i] = f - g;
      }
   }
}
 
void preBmGs(char *x, int m, int bmGs[]) {
   int i, j, suff[strlen(x)];
 
   suffixes(x, m, suff);
 
   for (i = 0; i < m; ++i)
      bmGs[i] = m;
   j = 0;
   for (i = m - 1; i >= 0; --i)
      if (suff[i] == i + 1)
         for (; j < m - 1 - i; ++j)
            if (bmGs[j] == m){
            bmGs[j] = m - 1 - i;
          }
               
   for (i = 0; i <= m - 2; ++i)
      bmGs[m - 1 - suff[i]] = m - 1 - i;
}
 
 

   /*Boyer Moore Algorithm */
void BM2(char *txt,  char *pat) {
    int a = 0;
	int m = strlen(pat);
    int n = strlen(txt);
    int bmGs[strlen(pat)];
    
  
    
    int l=0;
    
    preBmBc(pat, m, badchar);
	preBmGs(pat, m, bmGs);
	
    
    ticcc=clock();
    
    int s = 0;  
    while(s <= (n - m)) {
        int j = m-1;
       
        while(j >= 0 && pat[j] == txt[s+j]){
            j--;
            times++;
        }
 
        //Pattern is finding
        if (j < 0) {
            a++;
            locationsBoyer[l]=s;
            l++;
            
            s += strlen(pat);
            
 
        }
		 else {
        
	        if(bmGs[j] < max(1,  badchar[txt[s+j]]-j)){
	           
			   s+=max(1,  badchar[txt[s+j]]-j);
	          
	 
			}
	        else{
	            s+=bmGs[j];
	           
			}
    	}
	}
	toccc=clock();
	//Number of comparision characters
	printf("Number of character comparisons = %d\n",times);
}
