import fatec.poo.model.Departamento;
import fatec.poo.model.FuncionarioComissionado;
import fatec.poo.model.FuncionarioHorista;
import fatec.poo.model.FuncionarioMensalista;

public class Aplic {
    public static void main(String[] args) {
        FuncionarioHorista funcHor = new FuncionarioHorista(1010, "Pedro Silva", "14/08/1978",15.80);
        funcHor.setCargo("programador");
        funcHor.setQtdeHorTrab(90);
        
        FuncionarioMensalista funcMen = new FuncionarioMensalista(1010, "Pedro Silva", "14/08/1978", 1200);
        funcMen.setCargo("analista");
        funcMen.setNumSalMin(2);
        
        FuncionarioComissionado funcCom = new FuncionarioComissionado(1020, "Luis silva", "12/04/1989", 40);
        funcCom.setSalBase(1500);
        funcCom.setCargo("nao sei");
        
        Departamento dep1 = new Departamento("C","Compra");
        
        //estabelecendo a ligação (apontamento) entre um objeto
        //da classe Funcionario Horista (funcHor) com um objeto da classe Departamento
        funcHor.setDepartamento(dep1);
        
        System.out.println("O funcionario horista " + funcHor.getNome() + " trabalha no departamento de "
                             + funcHor.getDepartamento().getNome());
        
        funcMen.setDepartamento(dep1);
        System.out.println("O funcionario mensalista " + funcMen.getNome() + " trabalha no departamento de "
                             + funcMen.getDepartamento().getNome());
        
    }
    
}
