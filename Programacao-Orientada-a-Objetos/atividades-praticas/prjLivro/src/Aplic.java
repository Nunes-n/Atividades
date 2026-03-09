/**
 *
 * @author ereno
 */

import java.util.Scanner;

public class Aplic {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        
        System.out.print("Insira o id do livro: ");
        int id = entrada.nextInt();
        System.out.print("Insira o título do livro: ");
        String titulo = entrada.next();
        Livro objLvr = new Livro(id, titulo);
        
        System.out.print("Insira o valor da multa diaria: ");
        double valMulta = entrada.nextDouble();
        objLvr.setValMultaDiaria(valMulta);
        
        int opcao;
        do{
            System.out.println("\n\n---------------");
            System.out.println("1 - Consultar livro");
            System.out.println("2 - Emprestar livro");
            System.out.println("3 - Devolver livro");
            System.out.println("4 - Sair\n");
            System.out.print("\tDigite a opção: ");
            opcao = entrada.nextInt();
            
            System.out.println("\n");
            
            if (opcao == 1){
                System.out.println("Identificação do livro: " + objLvr.getIdentificacao());
                System.out.println("Título do livro: " + objLvr.getTitulo());
                if (objLvr.getSituacao() == false){
                    System.out.println("Situação: Disponível");
                }
                else{
                    System.out.println("Situação: Emprestado");
                }
            }
            else {
                if (opcao == 2){
                    if (objLvr.getSituacao() == false){
                        objLvr.emprestar();
                        System.out.println("Operação de empréstimo realizada com sucesso");
                    }
                    else{
                        System.out.println("O livro já está emprestado");
                    }
                }
                else{
                    if (opcao == 3){
                        if (objLvr.getSituacao() == true){
                            System.out.print("Insira a quantidade de dias em atraso (caso haja): ");
                            int dias = entrada.nextInt();
                            System.out.println("Multa: R$" + objLvr.devolver(dias));
                            System.out.println("Operação de devolução realizada com sucesso");
                        }
                        else{
                            System.out.println("O livro já está disponível");
                        }
                    }
                    else{
                        if (opcao != 4){
                            System.out.println("Opção inválida");
                        }
                    }
                }
            }
            
        }while(opcao != 4);
    }
    
}
