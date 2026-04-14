package fatec.poo.model;

public class Palestra {
    private String data;
    private String tema;
    private double valor;
    private Palestrante palestrante;
    private Participante participantes[];
    private int numParticipantes;
    
    public Palestra(String tema, double valor){
        this.tema = tema;
        this.valor = valor;
        
        participantes = new Participante[5];
    }
    
    public void setData(String data){
        this.data = data;
    }
    public void setPalestrante(Palestrante palestrante) {
        this.palestrante = palestrante;
    }
    public void addParticipante(Participante participantes){
        this.participantes[numParticipantes] = participantes;
        numParticipantes++;
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
    public Participante getParticipante(){
        return participantes[numParticipantes];
    }
    
    public double calcTotalFaturado(){
        return 0;
    }
}
