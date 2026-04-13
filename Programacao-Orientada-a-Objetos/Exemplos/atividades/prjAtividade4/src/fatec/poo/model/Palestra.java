package fatec.poo.model;

public class Palestra {
    private String data;
    private String tema;
    private double valor;
    private Palestrante palestrante;
    
    public Palestra(String tema, double valor){
        this.tema = tema;
        this.valor = valor;
    }
    
    public void setData(String data){
        this.data = data;
    }
    public void setPalestrante(Palestrante palestrante) {
        this.palestrante = palestrante;
    }
    
    public String getData() {
        return data;
    }
    public String getTema() {
        return tema;
    }
    public double getValor() {
        return valor;
    }
    public Palestrante getPalestrante() {
        return palestrante;
    }
    
    
    public double calcTotalFaturado(){
        return 0;
    }
}
