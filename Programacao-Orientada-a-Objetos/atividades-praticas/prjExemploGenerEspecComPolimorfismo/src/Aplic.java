import fatec.poo.model.FuncionarioHorista;
import fatec.poo.model.FuncionarioMensalista;

public class Aplic {
    public static void main(String[] args) {
        FuncionarioHorista funcHor = new FuncionarioHorista(1010, "Pedro Silva", "14/08/1978",15.80);
        
        funcHor.setCargo("mecanico");
        funcHor.setQtdeHorTrab(90);
        
        System.out.println("----------------------");
        System.out.println("Funcionario Horista:");
        
        System.out.println("Registro: " + funcHor.getRegistro());
        System.out.println("Nome: " + funcHor.getNome());
        System.out.println("Data de admissao: " + funcHor.getDtAdmissao());
        System.out.println("Cargo: " + funcHor.getCargo());
        System.out.println("Salario bruto: " + funcHor.calcSalBruto());
        System.out.println("Desconto: " + funcHor.calcDesconto());
        System.out.println("Gratificacao: " + funcHor.calcGratificacao());
        System.out.println("Salario liquido: " + funcHor.calcSalLiquido());
        
        System.out.println("\n");
        
        FuncionarioMensalista funcMen = new FuncionarioMensalista(1010, "Pedro Silva", "14/08/1978", 1200);
        
        funcMen.setCargo("analista");
        funcMen.setNumSalMin(2);
        
        System.out.println("----------------------");
        System.out.println("Funcionario Mensalista:");
        
        System.out.println("Registro: " + funcMen.getRegistro());
        System.out.println("Nome: " + funcMen.getNome());
        System.out.println("Data de admissao: " + funcMen.getDtAdmissao());
        System.out.println("Cargo: " + funcMen.getCargo());
        System.out.println("Salario bruto: " + funcMen.calcSalBruto());
        System.out.println("Desconto: " + funcMen.calcDesconto());
        System.out.println("Salario liquido: " + funcMen.calcSalLiquido());
    }
    
}
