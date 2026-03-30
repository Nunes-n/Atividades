package fatec.poo.model;

public class FuncionarioHorista extends Funcionario {
    private double valHorTrab;
    private int qtdeHorTrab;
    
    public FuncionarioHorista(int r, String n, String da, double v){
        super(r, n, da);
        
        valHorTrab = v;
    }
    
    public void setQtdeHorTrab(int qht){
        qtdeHorTrab = qht;
    }
    
    public double calcSalBruto(){
        return qtdeHorTrab * valHorTrab;
    }
    public double calcGratificacao(){
        return calcSalBruto() * 0.075;
    }
    public double calcSalLiquido(){ //forma parcial
        return calcSalBruto() + calcGratificacao() - calcDesconto();
    }
}
