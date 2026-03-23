package fatec.poo.model;

public class FuncionarioMensalista extends Funcionario{
    private double valSalMin;
    private double numSalMin;
    
    public FuncionarioMensalista(int r, String n, String da, double vsm){
        super(r, n, da);
        
        valSalMin = vsm;
    }
    
    public void setNumSalMin(double nsm){
        numSalMin = nsm;
    }
    
    public double calcSalBruto(){
        return valSalMin * numSalMin;
    }
}
