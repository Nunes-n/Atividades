package fatec.poo.model;

public class Participante extends Pessoa{
    private char tipo;
    
    public Participante(char tipo, String cpf, String nome){
        super(cpf, nome);
        
        this.tipo = tipo;
    }

    public char getTipo() {
        return tipo;
    }
}
