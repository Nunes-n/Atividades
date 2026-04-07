package fatec.poo.model;

public class Departamento {
    private String sigla;
    private String nome;
    private Funcionario[] funcionarios; //definição de uma matriz de objetos
                                        //que representa uma matriz de ponteiros
                                        //indicando a multiplicidade 1..*
    private int numFunc; //indice da matriz de objetos
                        //valor inicial 0

    public Departamento(String sigla, String nome) {
        this.sigla = sigla;
        this.nome = nome;
        funcionarios = new Funcionario[5];
    }

    public String getSigla() {
        return sigla;
    }
    public String getNome() {
        return nome;
    }
    
    //tem como parametro de entrada o endereço de um objeto da classe FuncionarioHorista,
    //FuncionarioMensalita e FuncionarioComissionado
    public void addFuncionario(Funcionario f){
        funcionarios[numFunc] = f;
        numFunc++;
    }
    
    public void listarFuncionarios(){
        System.out.println("sigla: " + sigla);
        System.out.println("nome: " + nome);
        System.out.println("quantidade de funcionarios: " + numFunc);
        
        System.out.println("\nregistro\t\tnome\t\tcargo");
        for(int x = 0; x < numFunc; x++){
            System.out.println(funcionarios[x].getRegistro() + "\t\t"
                                + funcionarios[x].getNome() + "\t\t"
                                + funcionarios[x].getCargo());
        }
    }
}
