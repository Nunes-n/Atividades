/**
 *
 * @author ereno
 */
public class Livro {
    private int identificacao;
    private String titulo;
    private boolean situacao;
    private double valMultaDiaria;
    
    public Livro(int id, String titulo){
        identificacao = id;
        this.titulo = titulo;
    }
    public void setValMultaDiaria(double val){
        valMultaDiaria = val;
    }
    
    public int getIdentificacao(){
        return identificacao;
    }
    public String getTitulo(){
        return titulo;
    }
    public boolean getSituacao(){
        return situacao;
    }
    
    public void emprestar(){
        situacao = true;
    }
    
    public double devolver(int diasAtraso){
        situacao = false;
        
        return diasAtraso * valMultaDiaria;
    }
}
