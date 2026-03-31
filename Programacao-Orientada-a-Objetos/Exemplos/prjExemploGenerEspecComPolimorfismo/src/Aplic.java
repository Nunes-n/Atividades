import fatec.poo.model.FuncionarioComissionado;
import fatec.poo.model.FuncionarioHorista;
import fatec.poo.model.FuncionarioMensalista;
import java.text.DecimalFormat;

public class Aplic {
    public static void main(String[] args) {
        DecimalFormat df = new DecimalFormat("#,##0.00");
        FuncionarioHorista funcHor = new FuncionarioHorista(1010, "Pedro Silva", "14/08/1978",15.80);
        
        funcHor.setCargo("mecanico");
        funcHor.setQtdeHorTrab(90);
        
        System.out.println("----------------------");
        System.out.println("Funcionario Horista:");
        
        System.out.println("Registro: " + funcHor.getRegistro());
        System.out.println("Nome: " + funcHor.getNome());
        System.out.println("Data de admissao: " + funcHor.getDtAdmissao());
        System.out.println("Cargo: " + funcHor.getCargo());
        System.out.println("Salario bruto: " + df.format(funcHor.calcSalBruto()));
        System.out.println("Desconto: " + df.format(funcHor.calcDesconto()));
        System.out.println("Gratificacao: " + df.format(funcHor.calcGratificacao()));
        System.out.println("Salario liquido: " + df.format(funcHor.calcSalLiquido()));
        
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
        System.out.println("Salario bruto: " + df.format(funcMen.calcSalBruto()));
        System.out.println("Desconto: " + df.format(funcMen.calcDesconto()));
        System.out.println("Salario liquido: " + df.format(funcMen.calcSalLiquido()));
        
        FuncionarioComissionado funcCom = new FuncionarioComissionado(1020, "Luis silva", "12/04/1989", 40);
        
        funcCom.setSalBase(1500);
        funcCom.setCargo("nao sei");
        
        System.out.println("----------------------");
        System.out.println("Funcionario Comissionado:");
        
        System.out.println("Registro: " + funcCom.getRegistro());
        System.out.println("Nome: " + funcCom.getNome());
        System.out.println("Data de admissao: " + funcCom.getDtAdmissao());
        System.out.println("Cargo: " + funcCom.getCargo());
        System.out.println("Salario bruto: " + df.format(funcMen.calcSalBruto()));
        System.out.println("Desconto: " + df.format(funcMen.calcDesconto()));
        System.out.println("Salario liquido: " + df.format(funcMen.calcSalLiquido()));
    }
    
}
