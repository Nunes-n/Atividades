import fatec.poo.model.FuncionarioHorista;
import fatec.poo.model.FuncionarioMensalista;

public class Aplic {
    public static void main(String[] args) {
        FuncionarioHorista funcHor = new FuncionarioHorista(1010, "Pedro Silva", "14/08/1978", 15.80);
        
        funcHor.setQtdeHorTrab(90);
        
        System.out.println("Salario bruto: " + funcHor.calcSalBruto());
        System.out.println("Desconto: " + funcHor.calcDesconto());
        System.out.println("Salario liquido: " + funcHor.calcSalLiquido());
        
        FuncionarioMensalista funcMen = new FuncionarioMensalista(1010, "Pedro Silva", "14/08/1978", 1200);
        
        funcMen.setNumSalMin(2);
        
        System.out.println("Salario bruto: " + funcMen.calcSalBruto());
        System.out.println("Desconto: " + funcMen.calcDesconto());
        System.out.println("Salario liquido: " + funcMen.calcSalLiquido());
    }
    
}
