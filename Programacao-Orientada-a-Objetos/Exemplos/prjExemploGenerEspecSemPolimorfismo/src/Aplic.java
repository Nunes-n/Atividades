import fatec.poo.model.Aluno;
import fatec.poo.model.Professor;

public class Aplic {

    public static void main(String[] args) {
        Aluno objAln = new Aluno(1010, "nunes", "11/11/1111");
        
        objAln.setMensalidade(1500);
        
        System.out.println("registro escolar: " + objAln.getRegEscolar());
        System.out.println("nome: " + objAln.getNome());
        System.out.println("data de nascimento: " + objAln.getDataNascimento());
        System.out.println("mensalidade: " + objAln.getMensalidade());
        
        Professor objPro = new Professor(2020, "m", "01/01/0101");
        
        objPro.setSalario(2500);
        
        System.out.println("\nregistro funcional: " + objPro.getRegFuncional());
        System.out.println("nome: " + objPro.getNome());
        System.out.println("data de nascimento: " + objPro.getDataNascimento());
        System.out.println("salario: " + objPro.getSalario());
    }
    
}
