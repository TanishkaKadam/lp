/*Experiment No.: 4
Problem Statement : Write a Java/C++ program to simulate memory placement strategies
1. First Fit
2. Best Fit
3. Worst Fit */



//3. worst fit



#include <stdio.h>

#define max 25

void main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, largest;
    static int bf[max], ff[max];



    printf("\n\tMemory Management Scheme - Worst Fit\n");

   
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

  
    printf("\nEnter the size of the blocks:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    
    printf("\nEnter the size of the files:\n");
    for (i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    
    for (i = 0; i < nb; i++) {
        bf[i] = 0;
    }

  
    for (i = 0; i < nf; i++) {
        largest = -1;  
        for (j = 0; j < nb; j++) {
            
            if (bf[j] != 1 && b[j] >= f[i]) {
                temp = b[j] - f[i];  
                if (temp > largest) {
                    ff[i] = j;  
                    largest = temp;  
                }
            }
        }

        
        if (largest != -1) {
            frag[i] = largest;  
            bf[ff[i]] = 1;  
        } else {
            frag[i] = -1; 
        }
    }

 
    printf("\nFile_no\tFile_size\tBlock_no\tBlock_size\tFragment\n");
    for (i = 0; i < nf; i++) {
        if (ff[i] != -1) {  
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, f[i], ff[i] + 1, b[ff[i]], frag[i]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\t\t-\t\t-\n", i + 1, f[i]);
        }
    }
}
