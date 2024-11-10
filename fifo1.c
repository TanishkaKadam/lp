/*Experiment no :5
Write a program to  simulate page replacement Algorithm: FIFO
Write a program to  simulate page replacement Algorithm:  LRU
 Write a program to  simulate page replacement Algorithm: LFU */
 
 
 
 //1. fifo
 
 

#include <stdio.h>

int main() {
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;
    
   
    printf("\nEnter the length of reference string: ");
    scanf("%d", &n);
    
   
    printf("\nEnter the reference string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }
    
  
    printf("\nEnter number of frames: ");
    scanf("%d", &f);
    
    
    for(i = 0; i < f; i++) {
        m[i] = -1;
    }
    
    printf("\nThe Page Replacement Process is:\n");
    
  
    for(i = 0; i < n; i++) {
        int pageFound = 0;
        
      
        for(k = 0; k < f; k++) {
            if(m[k] == rs[i]) {
                pageFound = 1;  
                break;
            }
        }
        
       
        if(pageFound == 0) {
            m[count] = rs[i]; 
            pf++;  
            count++;
            if(count == f) {
                count = 0;  
            }
        }
        
       
        for(j = 0; j < f; j++) {
            printf("\t%d", m[j]);
        }
        
       
        if(pageFound == 0) {
            printf("\tPF No. %d", pf);
        }
        
        printf("\n");
    }
    
   
    printf("\nThe number of page faults using FIFO are: %d\n", pf);
    
    return 0;
}
