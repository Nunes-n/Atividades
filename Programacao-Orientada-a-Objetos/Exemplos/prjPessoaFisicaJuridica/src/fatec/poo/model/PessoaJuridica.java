package fatec.poo.model;

public class PessoaJuridica extends Pessoa{
    private String cgc;
    private double taxaIncentivo;
    
    public PessoaJuridica(String n, String c, int ai){
        super(n, ai);
        
        cgc = c;
    }
    
    public double calcBonus(int a){
        return (taxaIncentivo * getTotalCompras()) * (a - getAnoInscricao());
    }

    public void setTaxaIncentivo(double taxaIncentivo) {
        this.taxaIncentivo = taxaIncentivo;
    }

    public String getCgc() {
        return cgc;
    }
    public double getTaxaIncentivo() {
        return taxaIncentivo;
    }
}
