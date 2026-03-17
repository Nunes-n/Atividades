package fatec.poo.model;

public class Aluno extends Pessoa {
    private int regEscolar;
    private double mensalidade;
    
    public Aluno(int re, String n, String dn){
        super(n, dn); //chamada do metodo construtor da superclasse
        
        regEscolar = re;
    }
    
    public void setMensalidade(double m){
        mensalidade = m;
    }
    
    public int getRegEscolar(){
        return regEscolar;
    }
    public double getMensalidade(){
        return mensalidade;
    }
}
