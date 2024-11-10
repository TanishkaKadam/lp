/*Experiment No.: 4
Problem Statement : Write a Java/C++ program to simulate memory placement strategies
1. First Fit
2. Best Fit
3. Worst Fit */



//1. firstfit :

#include <stdio.h>
#include <stdlib.h>  

#define max 25

void main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, highest = 0;
    static int bf[max], ff[max];  

  
    system("clear");

    
    printf("\n\tMemory Management Scheme - Worst Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

   
    printf("\nEnter the size of the blocks:\n");
    for(i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

   
    printf("\nEnter the size of the files:\n");
    for(i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

   
    for(i = 1; i <= nb; i++) {
        bf[i] = 0;  
    }

    
    for(i = 1; i <= nf; i++) {
        highest = -1;
        for(j = 1; j <= nb; j++) {
            if(bf[j] == 0) {  
                temp = b[j] - f[i];  
                if(temp >= 0 && highest < temp) {
                    ff[i] = j;  
                    highest = temp;  
                }
            }
        }

        
        if(highest != -1) {
            bf[ff[i]] = 1;  
            frag[i] = highest;  
        } else {
            ff[i] = -1;  
            frag[i] = -1; 
        }
    }

    
    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragmentation");
    for(i = 1; i <= nf; i++) {
        if(ff[i] != -1) {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
        } else {
            printf("\n%d\t\t%d\t\tNot Allocated\t\t\t\t-", i, f[i]);
        }
    }

    
    getchar();  
}


/* to run this program use 
gcc first1.c
./a.out */
