
//FIRST-FIT:

#include <iostream>
#include <vector>

#define MAX 25

int main() {
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp;
    std::vector<int> bf(MAX, 0), ff(MAX, 0);
   
    std::cout << "\n\tMemory Management Scheme - First Fit";
    std::cout << "\nEnter the number of blocks: ";
    std::cin >> nb;

    std::cout << "Enter the number of files: ";
    std::cin >> nf;

    std::cout << "\nEnter the size of the blocks:-\n";
    for(i = 1; i <= nb; i++) {
        std::cout << "Block " << i << ": ";
        std::cin >> b[i];
    }

    std::cout << "Enter the size of the files :-\n";
    for(i = 1; i <= nf; i++) {
        std::cout << "File " << i << ": ";
        std::cin >> f[i];
    }

    for(i = 1; i <= nf; i++) {
        for(j = 1; j <= nb; j++) {
            if(bf[j] != 1) {
                temp = b[j] - f[i];
                if(temp >= 0) {
                    ff[i] = j;
                    break;
                }
            }
        }
        frag[i] = temp;
        bf[ff[i]] = 1;
    }

    std::cout << "\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement";
    for(i = 1; i <= nf; i++) {
        std::cout << "\n" << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i];
    }

    return 0;
}
