package fatec.poo.model;

public class FuncionarioComissionado extends Funcionario{
    private double salBase;
    private double taxaComissao;
    private double totalVendas;
    
    public FuncionarioComissionado(int r, String n, String da, double t){
        super(r, n, da);
        
        taxaComissao = t;
    }
    
    public void setSalBase(double s){
        salBase = s;
    }
    
    public double getSalBase(){
        return salBase;
    }
    public double getTotalVendas(){
        return totalVendas;
    }
    public double getTaxaComissao(){
        return taxaComissao;
    }
    
    public void addVendas(double v){
        totalVendas += v;
    }
    
    public double calcSalBruto(){ //forma total
        return salBase + taxaComissao * totalVendas;
    }
    public double calcSalLiquido(){ //forma parcial
        return calcSalBruto() - calcDesconto() + calcGratificacao();
    }
    public double calcGratificacao(){
        if (totalVendas <= 5000){
            return 0;
        }
        else{
            if(totalVendas <= 10000){
                return calcSalBruto() * 0.03;
            }
            else{
                return calcSalBruto() * 0.05;
            }
        }
    }
}
