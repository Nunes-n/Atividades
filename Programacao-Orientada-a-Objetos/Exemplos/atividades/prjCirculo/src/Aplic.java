/**
 *
 * @author nunes
 */

import java.util.Scanner;

public class Aplic {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        
        Circulo objCirc = new Circulo();
        
        System.out.print("Insira o raio: ");
        double raio = entrada.nextDouble();
        objCirc.setRaio(raio);
        
        int escolha;
        
        do{
            System.out.println("\n\n----------------");
            
            System.out.println("1 - Calcular a área do círculo");
            System.out.println("2 - Calcular o perímetro do círculo");
            System.out.println("3 - Calcular o diâmetro do círculo");
            System.out.println("4 - Sair");
            
            escolha = entrada.nextInt();
            
            if (escolha == 1){
                System.out.println("Área do círculo: " + objCirc.calcArea());
            }
            if (escolha == 2){
                System.out.println("Perímetro do círculo: " + objCirc.calcPerimetro());
            }
            if (escolha == 3){
                System.out.println("Diâmetro do círculo: " + objCirc.calcDiametro());
            }
            if (escolha > 4 || escolha < 1){
                System.out.println("escolha inválida");
            }
            
        }while(escolha != 4);
        
        System.out.println("\n--------------");
        System.out.println("Raio do círculo: " + objCirc.getRaio());
        System.out.println("Área do círculo: " + objCirc.calcArea());
        System.out.println("Perímetro do círculo: " + objCirc.calcPerimetro());
    }
    
}
