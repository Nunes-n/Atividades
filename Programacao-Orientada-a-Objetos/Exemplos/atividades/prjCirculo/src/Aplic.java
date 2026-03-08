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
        
        System.out.println("\n--------------");
        System.out.println("Raio do círculo: " + objCirc.getRaio());
        System.out.println("Área do círculo: " + objCirc.calcArea());
        System.out.println("Perímetro do círculo: " + objCirc.calcPerimetro());
    }
    
}
