import fatec.poo.model.PedidoCompra;
import java.util.Scanner;
import java.text.DecimalFormat;

import fatec.poo.model.PessoaFisica;
import fatec.poo.model.PessoaJuridica;

public class Aplic {

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("#,##0.00");
        
        PedidoCompra[] cadPedidos = new PedidoCompra[10];
        
        System.out.println("------Pessoa Fisica-------");
        System.out.print("nome: ");
        String nome = entrada.next();
        
        System.out.print("ano de inscrição: ");
        int ai = entrada.nextInt();
        System.out.print("ano atual: ");
        int a = entrada.nextInt();
        
        System.out.print("cpf: ");
        String cpf = entrada.next();
        
        PessoaFisica objPF = new PessoaFisica(nome, cpf, ai); //instanciacao do objeto class PessoaFisica
        
        System.out.print("compras: ");
        objPF.addCompras(entrada.nextDouble());
        
        System.out.print("base: ");
        objPF.setBase(entrada.nextDouble());
        
        //saida
        
        System.out.println("\n\nnome: " + objPF.getNome());
        System.out.println("data de inscrição: " + objPF.getAnoInscricao());
        System.out.println("compras: " + df.format(objPF.getTotalCompras()));
        System.out.println("cpf: " + objPF.getCpf());
        System.out.println("base: " + df.format(objPF.getBase()));
        System.out.println("bonus: " + df.format(objPF.calcBonus(a)));
        
        
        
        System.out.println("------Pessoa Juridica-------");
        System.out.print("nome: ");
        nome = entrada.next();
        
        System.out.print("ano de inscrição: ");
        ai = entrada.nextInt();
        System.out.print("ano atual: ");
        a = entrada.nextInt();
        
        System.out.print("cgc: ");
        String cgc = entrada.next();
        
        PessoaJuridica objPJ = new PessoaJuridica(nome, cgc, ai); //instanciacao do objeto class PessoaJuridica
        
        System.out.print("compras: ");
        objPJ.addCompras(entrada.nextDouble());
        
        System.out.print("taxa de incentivo: ");
        objPJ.setTaxaIncentivo(entrada.nextDouble());
        
        //saida
        
        System.out.println("\n\nnome: " + objPJ.getNome());
        System.out.println("data de inscrição: " + objPJ.getAnoInscricao());
        System.out.println("compras: " + df.format(objPJ.getTotalCompras()));
        System.out.println("cgc: " + objPJ.getCgc());
        System.out.println("taxa de incentivo: " + df.format(objPJ.getTaxaIncentivo()));
        System.out.println("bonus: " + df.format(objPJ.calcBonus(a)));
    }
}
