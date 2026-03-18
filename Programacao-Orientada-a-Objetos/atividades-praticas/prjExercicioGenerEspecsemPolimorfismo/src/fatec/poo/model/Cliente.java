package fatec.poo.model;
/**
 *
 * @author nunes
 */
public class Cliente extends Pessoa{
    private String cpf;
    private double peso;
    private double altura;
    
    public Cliente(String c, String n, String t){
        super(n, t);
        
        cpf = c;
    }
    
    public void setPeso(double p){
        peso = p;
    }
    public void setAltura(double a){
        altura = a;
    }
    
    public String getCpf(){
        return cpf;
    }
    public double getPeso(){
        return peso;
    }
    public double getAltura(){
        return altura;
    }
}
