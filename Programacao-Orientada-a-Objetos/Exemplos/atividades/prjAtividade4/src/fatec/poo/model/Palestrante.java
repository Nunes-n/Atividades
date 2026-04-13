package fatec.poo.model;

public class Palestrante extends Pessoa{
    private String empresa;
    private double taxaCobranca;
    private Palestra palestra[];
    private int numPalestra;
    
    public Palestrante(String empresa, String cpf, String nome){
        super(cpf, nome);
        
        this.empresa = empresa;
        
        palestra = new Palestra[2];
    }

    public void setTaxaCobranca(double taxaCobranca) {
        this.taxaCobranca = taxaCobranca;
    }
    public void addPalestra(Palestra palestra) {
        this.palestra[numPalestra] = palestra;
        numPalestra++;
    }
    
    public String getEmpresa() {
        return empresa;
    }
    public double getTaxaCobranca() {
        return taxaCobranca;
    }
    
    public double calcTotalReceberPalestras(){
        return 0; //por enquanto
    }
}
