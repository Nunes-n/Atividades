package fatec.poo.model;

public class Professor extends Pessoa{
    private int regFuncional;
    private double salario;
    
    public Professor(int rf, String n, String dn){
        super(n, dn);
        
        regFuncional = rf;
    }
    
    public void setSalario(double s){
        salario = s;
    }
    
    public int getRegFuncional(){
        return regFuncional;
    }
    public double getSalario(){
        return salario;
    }
}
