/*Experiment No. 2
Problem Statement : Design suitable data structures and implement Pass-I of a two pass macro
processor using OOP features in Java/C++. The output of Pass-I (MNT, MDT, ALA &
Intermediate code file without any macro definitions) should be input for Pass-II.*/


//pass1



class MNT {
    int index;
    String name;
    int defIndex;

    MNT(int i, String a, int j) {
        index = i;
        name = a;
        defIndex = j;
    }
}

class MDT {
    int index;
    String[] def;

    MDT() {
        index = 0;
        def = new String[4];
    }

    void print() {
        for (String s : def) {
            if (s != null) {
                System.out.print(s + " ");
            }
        }
        System.out.println();
    }
}

public class Pass1Macro {
    public static void main(String[] args) {
        String[][] input = {
            {"MACRO", "INCR", "&A", "&B", "&REC"},
            {null, "MOVER", "&REG", "&A", null},
            {null, "ADDS", "&A", "&B", null},
            {null, "MOVEM", "&REG", "&A", null},
            {"MEND", null, null, null, null},
            {"MACRO", "ADDS", "&F", "&S", null},
            {null, "MOVER", "AREG", "&F", null},
            {null, "ADD", "AREG", "&S", null},
            {null, "MOVEM", "AREG", "&S", null},
            {null, "WRITE", "&S", null, null},
            {"MEND", null, null, null, null},
            {"MACRO", "SUBS", "&F", "&S", null},
            {null, "MOVER", "BREG", "&F", null},
            {null, "SUB", "BREG", "&S", null},
            {null, "MOVEM", "BREG", "&S", null},
            {null, "WRITE", "&S", null, null},
            {"MEND", null, null, null, null},
            {null, "START", null, "200", null},
            {null, "READ", "N1", null, null},
            {null, "READ", "N2", null, null},
            {null, "ADDS", "N1", "N2", null},
            {null, "SUBS", "N1", "N2", null},
            {null, "INCR", "N1", "N2", "DREG"},
            {null, "STOP", null, null, null},
            {"N1", "DS", "2", null, null},
            {"N2", "DS", "2", null, null},
            {null, "END", null, null, null}
        };

        MNT[] n = new MNT[20];
        MDT[] d = new MDT[20];

        int i = 0, nc = 0, dc = 0;

        while (i < input.length) {
            String arr1 = null, arr2 = null, arr3 = null, arr4 = null, arr5 = null;

            if (input[i][0] != null) arr1 = input[i][0];
            if (input[i][1] != null) arr2 = input[i][1];
            if (input[i][2] != null) arr3 = input[i][2];
            if (input[i][3] != null) arr4 = input[i][3];
            if (input[i][4] != null) arr5 = input[i][4];

            if ("MACRO".equals(arr1)) {
                n[nc] = new MNT(nc, arr2, dc);
                nc++;

                while (!"MEND".equals(arr1)) {
                    d[dc] = new MDT();
                    d[dc].index = dc;
                    d[dc].def[0] = arr2;

                    if (arr3 != null) {
                        d[dc].def[1] = arr3;
                    }
                    if (arr4 != null) {
                        d[dc].def[2] = arr4;
                    }
                    if (arr5 != null) {
                        d[dc].def[3] = arr5;
                    }

                    dc++;
                    i++;
                    if (i < input.length) {
                        arr1 = input[i][0];
                        arr2 = input[i][1];
                        arr3 = input[i][2];
                        arr4 = input[i][3];
                        arr5 = input[i][4];
                    } else {
                        break;
                    }
                }
            }

            if ("MEND".equals(arr1)) {
                d[dc] = new MDT();
                d[dc].index = dc;
                d[dc].def[0] = arr1;
                dc++;
            }

            i++;
        }

        System.out.print("MNT\nIndex\tName\tMDT_Index\n");
        for (i = 0; i < nc; i++) {
            System.out.println(n[i].index + "\t" + n[i].name + "\t" + n[i].defIndex);
        }

        System.out.print("\nMDT\nIndex\tDefinition\n");
        for (i = 0; i < dc; i++) {
            System.out.print(d[i].index + "\t");
            d[i].print();
        }
    }
}



/*to run this program
 
 ubuntu@Tanishka:~$ cd Desktop
ubuntu@Tanishka:~/Desktop$ javac Pass1Macro.java
ubuntu@Tanishka:~/Desktop$ java Pass1Macro
 */
