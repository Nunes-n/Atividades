import java.util.Scanner;

public class Aplic {
    public static void main(String[] args) {
        
        Scanner entrada = new Scanner(System.in);
        
        double medAlt, medBase;
        int opcao;
        
        System.out.print("Digite a medida da altura: ");
        medAlt = entrada.nextDouble();
        
        System.out.print("Digite a medida da base: ");
        medBase = entrada.nextDouble();
        
        Retangulo objRet = new Retangulo(); //ponteiro que aponta para o objeto tipo Retangulo instanciado
        
        objRet.setAltura(medAlt);
        objRet.setBase(medBase);
        
        do{
            System.out.println("\n\n1 - Consultar area");
            System.out.println("2 - Consultar perimetro");
            System.out.println("3 - Consultar diagonal");
            System.out.println("4 - Sair");
            System.out.print("\n\tDigite a opcao: ");
            
            opcao = entrada.nextInt();
            
            if (opcao == 1){
                System.out.println("\nMedida da area do retangulo: " + objRet.calcArea());
            } else {
                if (opcao == 2){
                    System.out.println("\nMedida do perimetro do retangulo: " + objRet.calcPerimetro());
                } else {
                    if (opcao == 3){
                        System.out.println("\nMedida da diagonal do retangulo: " + objRet.calcDiagonal());
                    }
                }
            }
        } while(opcao < 4);
        
    }
    
}
