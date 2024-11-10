/*Experiment No. 1
Problem Statement : Design suitable data structures and implement pass1 and pass2 of a two pass
assembler for pseudo-machine. Implementation should consist of a few instructions from each category
and few assembler directives. The output of pass1 (intermediate code file and symbol table) should be
input for pass2. */


//pass1




class SymTab {
    int index;
    String name;
    int addr;

    SymTab(int i, String s, int a) {
        index = i;
        name = s;
        addr = a;
    }
}

class LitTab {
    int index;
    String name;
    int addr;





    LitTab(int i, String a, int addr) {
        index = i;
        name = a;
        this.addr = addr;
    }

    void setAddr(int a) {
        addr = a;
    }
}

class PoolTab {
    int pIndex;
    int lIndex;

    PoolTab(int i, int a) {
        pIndex = i;
        lIndex = a;
    }
}

public class Pass1 {
    public static void main(String[] args) {
        String[][] input = {
            {null, "START", "100", null},
            {null, "MOVER", "AREG", "A"},
            {"AGAIN", "ADD", "AREG", "='2"},
            {null, "ADD", "AREG", "B"},
            {"AGAIN", "ADD", "AREG", "='3"},
            {null, "LTORG", null, null},
            {"AGAIN2", "ADD", "AREG", "BREG"},
            {"AGAIN2", "ADD", "AREG", "CREG"},
            {"AGAIN", "ADD", "AREG", "='2"},
            {null, "DC", "B", "3"},
            {"LOOP", "DS", "A", "1"},
            {null, "END", null, null}
        };

        SymTab[] symTab = new SymTab[20];
        LitTab[] litTab = new LitTab[20];
        PoolTab[] poolTab = new PoolTab[20];

        int loc = Integer.parseInt(input[0][2]);
        int i = 1, sn = 0, ln = 0, Inc = 0, pn = 0;
        String m = input[1][1];

        while (!m.equals("END")) {
            if (check(m) == 1) {
                if (input[i][0] == null) {
                    String op1 = input[i][2];
                    String op2 = input[i][3];
                    if (comp(op2, symTab, sn) == 1) {
                        symTab[sn] = new SymTab(sn, op2, 0);
                        sn++;
                    } else if (comp(op2, symTab, sn) == 2) {
                        litTab[ln] = new LitTab(ln, op2, 0);
                        ln++;
                    }
                    loc++;
                    i++;
                } else {
                    String op1 = input[i][0];
                    symTab[sn] = new SymTab(sn, op1, loc);
                    sn++;
                    String op2 = input[i][3];
                    if (comp(op2, symTab, sn) == 1) {
                        symTab[sn] = new SymTab(sn, op2, 0);
                        sn++;
                    } else if (comp(op2, symTab, sn) == 2) {
                        litTab[ln] = new LitTab(ln, op2, 0);
                        ln++;
                    }
                    loc++;
                    i++;
                }
            } else if (check(m) == 2) {
                if (input[i][0] == null) {
                    String op1 = input[i][2];
                    String op2 = input[i][3];
                    int temp = comp(op1, symTab, sn);
                    if (temp != 99) {
                        symTab[temp] = new SymTab(temp, op1, loc);
                    }
                    loc += Integer.parseInt(op2);
                    i++;
                } else {
                    String op1 = input[i][0];
                    symTab[sn] = new SymTab(sn, op1, loc);
                    sn++;
                    String op2 = input[i][3];
                    int temp = comp(op1, symTab, sn);
                    if (temp != 99) {
                        symTab[temp] = new SymTab(temp, op1, loc);
                    }
                    loc += Integer.parseInt(op2);
                    i++;
                }
            } else if (check(m) == 3) {
                if (input[i][0] == null) {
                    String op1 = input[i][2];
                    String op2 = input[i][3];
                    int temp = comp(op1, symTab, sn);
                    if (temp != 99) {
                        symTab[temp] = new SymTab(temp, op1, loc);
                    }
                    loc++;
                    i++;
                } else {
                    String op1 = input[i][0];
                    symTab[sn] = new SymTab(sn, op1, loc);
                    sn++;
                    String op2 = input[i][3];
                    int temp = comp(op1, symTab, sn);
                    if (temp != 99) {
                        symTab[temp] = new SymTab(temp, op1, loc);
                    }
                    loc++;
                    i++;
                }
            } else if (check(m) == 4) {
                poolTab[pn] = new PoolTab(pn, ln);
                pn++;
                while (Inc != ln) {
                    litTab[Inc].setAddr(loc);
                    Inc++;
                    loc++;
                }
                i++;
            }
            m = input[i][1];
        }

        System.out.println("Symbol Table");
        System.out.println("Index\tSymbol\tAddress");
        for (i = 0; i < sn; i++) {
            System.out.println(symTab[i].index + "\t" + symTab[i].name + "\t" + symTab[i].addr);
        }

        System.out.println("\nLiteral Table");
        System.out.println("Index\tLiteral\tAddress");
        for (i = 0; i < ln; i++) {
            System.out.println(litTab[i].index + "\t" + litTab[i].name + "\t" + litTab[i].addr);
        }

        System.out.println("\nPool Table");
        System.out.println("Pool Index\tLiteral Index");
        for (i = 0; i < pn; i++) {
            System.out.println("\t" + poolTab[i].pIndex + "\t\t" + poolTab[i].lIndex);
        }

        System.out.println("\n\nIntermediate Code\n");
        i = 0;
        m = input[i][1];
        String op1 = input[i][2];
        String op2 = input[i][3];
        int point = 0, in1 = 0, in2 = 0, j = 0;

        System.out.print(ic(m) + ic(op1));
        while (!m.equals("END")) {
            if (check(m) == 1) {
                System.out.print(ic(m) + ic(op1));
                if (comp(op2, symTab, sn) == 0 && comp(op2, symTab, sn) == 99) {
                    System.out.print(ic(op2));
                } else if (comp(op2, symTab, sn) == 2) {
                    int temp = comp(op2, litTab, ln);
                    System.out.print("(L." + temp + ")");
                    j++;
                } else if (comp(op2, symTab, sn) != 1) {
                    int temp = comp(op2, symTab, sn);
                    System.out.print("(S," + temp + ")");
                }
            } else if (check(m) == 2 || check(m) == 3) {
                System.out.print(ic(m) + ic(op2));
                if (comp(op1, symTab, sn) != 1) {
                    int temp = comp(op1, symTab, sn);
                    System.out.print("(S," + temp + ")");
                }
            } else if (check(m) == 4) {
                if (point + 1 != pn) {
                    in1 = poolTab[point + 1].lIndex - poolTab[point].lIndex;
                    in2 = poolTab[point].lIndex;
                    point++;
                    while (in1 > 0) {
                        System.out.print(ic(m) + ic(litTab[in2].name));
                        in2++;
                        in1--;
                    }
                } else {
                    in2 = poolTab[point].lIndex;
                    while (in2 != ln) {
                        System.out.print(ic(m) + ic(litTab[in2].name));
                        in2++;
                    }
                }
            }
            i++;
            m = input[i][1];
            op1 = input[i][2];
            op2 = input[i][3];
            System.out.print("\n");
        }

        System.out.println(ic(m));
    }

    static int check(String m) {
        if (m.equals("MOVER") || m.equals("ADD")) {
            return 1;
        } else if (m.equals("DS")) {
            return 2;
        } else if (m.equals("DC")) {
            return 3;
        } else if (m.equals("LTORG")) {
            return 4;
        }
        return -1;
    }

    static int comp(String m, SymTab[] s, int sn) {
        if (m.equals("AREG") || m.equals("BREG") || m.equals("CREG"))
            return 0;
        else if (m.charAt(0) == '=')
            return 2;
        else if (m.charAt(0) == 'L')
            return 99;
        for (int i = 0; i < sn; i++) {
            if (m.equals(s[i].name)) {
                return 1;
            }
        }
        return 99;
    }

    static int comp(String m, LitTab[] l, int ln) {
        for (int i = 0; i < ln; i++) {
            if (m.equals(l[i].name)) {
                return i;
            }
        }
        return -1;
    }

    static String ic(String m) {
        switch (m) {
            case "MOVER": return "00 ";
            case "ADD": return "01 ";
            case "SUB": return "02 ";
            case "MULT": return "03 ";
            case "DIV": return "04 ";
            case "LTORG": return "05 ";
            case "DC": return "06 ";
            case "DS": return "07 ";
            case "START": return "08 ";
            case "END": return "09 ";
            default: return m + " ";
        }
    }
}




/* to run this program : 
ubuntu@Tanishka:~$ cd Desktop
ubuntu@Tanishka:~/Desktop$ javac Pass1.java
ubuntu@Tanishka:~/Desktop$ java Pass1

*/
