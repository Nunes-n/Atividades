package fatec.poo.model;
/**
 *
 * @author nunes
 */
public class Instrutor extends Pessoa{
    private int identificacao;
    private String areaAtuacao;
    
    public Instrutor(int id, String n, String t){
        super(n, t);
        
        identificacao = id;
    }
    
    public void setAreaAtuacao(String a){
        areaAtuacao = a;
    }
    
    public int getIdentificacao(){
        return identificacao;
    }
    public String getAreaAtuacao(){
        return areaAtuacao;
    }
}
