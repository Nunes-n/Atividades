/**
 *
 * @author nunes
 */

import java.util.Scanner;

public class Aplic {

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        
        Aluno objAl = new Aluno();
        
        int RA;
        double ntPrv1, ntPrv2, ntTrab1, ntTrab2;
        
        System.out.print("Insira o RA: ");
        RA = entrada.nextInt();
        objAl.setRA(RA);
        
        System.out.print("Insira a nota da prova 1: ");
        ntPrv1 = entrada.nextDouble();
        objAl.setNtPrv1(ntPrv1);
        
        System.out.print("Insira a nota da prova 2: ");
        ntPrv2 = entrada.nextDouble();
        objAl.setNtPrv2(ntPrv2);
        
        System.out.print("Insira a nota do trabalho 1: ");
        ntTrab1 = entrada.nextDouble();
        objAl.setNtTrab1(ntTrab1);
        
        System.out.print("Insira a nota do trabalho 2: ");
        ntTrab2 = entrada.nextDouble();
        objAl.setNtTrab2(ntTrab2);
        
        System.out.println("\n----------------");
        
        System.out.println("RA: " + objAl.getRA());
        System.out.println("Nota da prova 1: " + objAl.getNtPrv1());
        System.out.println("Nota da prova 2: " + objAl.getNtPrv2());
        System.out.println("Nota do trabalho 1: " + objAl.getNtTrab1());
        System.out.println("Nota do trabalho 2: " + objAl.getNtTrab2() + "\n");
        
        System.out.println("Média da nota das provas: " + objAl.calcMediaProva());
        System.out.println("Média da nota dos trabalhos: " + objAl.calcMediaTrab());
        System.out.println("Média final: " + objAl.calcMediaFInal());
    }
    
}
