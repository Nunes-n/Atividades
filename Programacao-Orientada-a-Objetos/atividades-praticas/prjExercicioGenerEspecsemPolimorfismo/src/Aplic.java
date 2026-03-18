/**
 *
 * @author nunes
 */

import fatec.poo.model.Cliente;
import fatec.poo.model.Instrutor;
import java.util.Scanner;

public class Aplic {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        
        //entrada cliente
        System.out.println("--CLIENTE--\n");
        System.out.print("nome: ");
        String nome = entrada.next();
        
        System.out.print("telefone: ");
        String tel = entrada.next();
        
        System.out.print("cpf: ");
        String cpf = entrada.next();
        
        Cliente objCli = new Cliente(cpf, nome, tel);
        
        System.out.print("peso: ");
        double peso = entrada.nextDouble();
        objCli.setPeso(peso);
        
        System.out.print("altura: ");
        double altura = entrada.nextDouble();
        objCli.setAltura(altura);
        
        //entrada instrutor
        System.out.println("--INSTRUTOR--\n");
        System.out.print("nome: ");
        nome = entrada.next();
        
        System.out.print("telefone: ");
        tel = entrada.next();
        
        System.out.print("identificacao: ");
        int id = entrada.nextInt();
        
        Instrutor objIns = new Instrutor(id, nome, tel);
        
        System.out.print("area de atuaçao: ");
        String areaAtuacao = entrada.next();
        objIns.setAreaAtuacao(areaAtuacao);
        
        //saida
        System.out.println("\n\n----------------------");
        System.out.println("nome do cliente: " + objCli.getNome());
        System.out.println("telefone do cliente: " + objCli.getTelefone());
        System.out.println("cpf do cliente: " + objCli.getCpf());
        System.out.println("peso do cliente: " + objCli.getPeso());
        System.out.println("altura do cliente: " + objCli.getAltura());
        System.out.println("\n");
        System.out.println("nome do instrutor: " + objIns.getNome());
        System.out.println("telefone do instrutor: " + objIns.getTelefone());
        System.out.println("identificaçao do instrutor: " + objIns.getIdentificacao());
        System.out.println("area de atuaçao do instrutor: " + objIns.getAreaAtuacao());
    }
    
}
