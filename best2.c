/*Experiment No.: 4
Problem Statement : Write a Java/C++ program to simulate memory placement strategies
1. First Fit
2. Best Fit
3. Worst Fit */



//2. Best fit


#include<stdio.h>

#define max 25

void main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, lowest;
    static int bf[max], ff[max];
    
   
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files:\n");
    for (i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

   
    for (i = 0; i < nb; i++) {
        bf[i] = 0;
    }

    
    for (i = 0; i < nf; i++) {
        lowest = 10000;  
        for (j = 0; j < nb; j++) {
            if (bf[j] != 1) {  
                temp = b[j] - f[i]; 
                if (temp >= 0 && temp < lowest) {
                    ff[i] = j;  
                    lowest = temp;  
                }
            }
        }

       
        if (lowest != 10000) {
            frag[i] = lowest;  
            bf[ff[i]] = 1;  
        } else {
            frag[i] = -1;  
        }
    }

   
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment\n");
    for (i = 0; i < nf; i++) {
        if (ff[i] != 0) {  
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\t\t-\t\t-\n", i + 1, f[i]);
        }
    }
}


/* to run this program use 
gcc best2.c
./a.out */
