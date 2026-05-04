package fatec.poo.model;

public class PessoaFisica extends Pessoa{
    private String cpf;
    private double base;
    
    public PessoaFisica(String n, String c, int ai){
        super(n, ai);
        
        cpf = c;
    }
    
    public double calcBonus(int a){
        if (getTotalCompras() > 12000){
            return (a - getAnoInscricao()) * base;
        }
        
        return 0;
    }

    public void setBase(double base) {
        this.base = base;
    }

    public String getCpf() {
        return cpf;
    }
    public double getBase() {
        return base;
    }
}