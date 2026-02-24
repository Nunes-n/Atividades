/**
 *
 * @author 0030482421002
 */
public class Exemplo6 {
    public static void main(String[] args) {
        int cont, num;
        
        num = (int) (Math.random() * 100);
        System.out.println("\t\t\tTABUADA DO " + num);
        cont = 1;
        do {
            System.out.println(num + " x " + cont + " = " + cont * num);
            cont++;
        } while (cont <= 10);
    }
}
