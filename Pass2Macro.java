/*Experiment No. 2
Problem Statement : Design suitable data structures and implement Pass-I of a two pass macro
processor using OOP features in Java/C++. The output of Pass-I (MNT, MDT, ALA &
Intermediate code file without any macro definitions) should be input for Pass-II.*/



//pass2





import java.util.ArrayList;

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

    MDT(int i, String m, String op1, String op2, String op3) {
        index = i;
        def = new String[4];
        def[0] = m;
        def[1] = op1;
        def[2] = op2;
        def[3] = op3;
    }
}

public class Pass2Macro {
    public static void main(String[] args) {
        // Example MNT and MDT from the first pass
        MNT[] mnt = new MNT[3];
        mnt[0] = new MNT(0, "INCR", 0);
        mnt[1] = new MNT(1, "ADDS", 5);
        mnt[2] = new MNT(2, "SUBS", 11);

        MDT[] mdt = new MDT[20];
        mdt[0] = new MDT(0, "INCR", "&A", "&B", "&REG");
        mdt[1] = new MDT(1, "MOVER", "#3", "#1", null);
        mdt[2] = new MDT(2, "ADDS", "#1", "#2", null);
        mdt[3] = new MDT(3, "MOVEM", "#3", "#1", null);
        mdt[4] = new MDT(4, "MEND", null, null, null);
        mdt[5] = new MDT(5, "ADDS", "&F", "&S", null);
        mdt[6] = new MDT(6, "MOVER", "AREG", "#1", null);
        mdt[7] = new MDT(7, "ADD", "AREG", "#2", null);
        mdt[8] = new MDT(8, "MOVEM", "AREG", "#2", null);
        mdt[9] = new MDT(9, "WRITE", "#2", null, null);
        mdt[10] = new MDT(10, "MEND", null, null, null);
        mdt[11] = new MDT(11, "SUBS", "&F", "&S", null);
        mdt[12] = new MDT(12, "MOVER", "BREG", "#1", null);
        mdt[13] = new MDT(13, "SUB", "BREG", "#2", null);
        mdt[14] = new MDT(14, "MOVEM", "BREG", "#2", null);
        mdt[15] = new MDT(15, "WRITE", "#2", null, null);
        mdt[16] = new MDT(16, "MEND", null, null, null);

        String[][] inputProgram = {
            {null, "START", null, "200", null},
            {null, "READ", "N1", null, null},
            {null, "READ", "N2", null, null},
            {null, "INCR", "N1", "N2", "DREG"},
            {null, "STOP", null, null, null},
            {"N1", "DS", "2", null, null},
            {"N2", "DS", "2", null, null},
            {null, "END", null, null, null}
        };

        ArrayList<String[]> outputProgram = new ArrayList<>();

        for (String[] line : inputProgram) {
            if (line[1] != null) {
                String macroName = line[1];
                MNT macro = findMacro(mnt, macroName);
                if (macro != null) {
                    int mdtIndex = macro.defIndex;

                    while (mdtIndex < mdt.length) {
                        if (mdt[mdtIndex].def[0].equals("MEND")) {
                            break; // Exit on "MEND"
                        }

                        String[] newLine = new String[5];
                        newLine[0] = line[0]; // Copy the label if it exists
                        newLine[1] = mdt[mdtIndex].def[0]; // Opcode

                        // Handle parameters
                        for (int i = 1; i <= 3; i++) {
                            if (mdt[mdtIndex].def[i] != null) {
                                if (mdt[mdtIndex].def[i].startsWith("&")) {
                                    // Replace parameter placeholders
                                    newLine[i + 1] = line[i]; 
                                } else {
                                    newLine[i + 1] = mdt[mdtIndex].def[i]; // Use the defined value
                                }
                            }
                        }

                        outputProgram.add(newLine);
                        mdtIndex++; // Move to the next MDT entry
                    }
                } else {
                    // If not a macro, add the line as it is
                    outputProgram.add(line);
                }
            } else {
                outputProgram.add(line);
            }
        }

        // Print the output program
        System.out.println("Output Program:");
        for (String[] outLine : outputProgram) {
            for (String s : outLine) {
                if (s != null) {
                    System.out.print(s + "\t");
                }
            }
            System.out.println();
        }
    }

    private static MNT findMacro(MNT[] mnt, String macroName) {
        for (MNT macro : mnt) {
            if (macro != null && macro.name.equals(macroName)) {
                return macro;
            }
        }
        return null; // Not found
    }
}


/* to run this program use 

ubuntu@Tanishka:~/Desktop$ javac Pass2Macro.java
ubuntu@Tanishka:~/Desktop$ java Pass2Macro*/
