/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fatec.poo.model;

/**
 *
 * @author 0030482421002
 */
public class GameShop {
    private int codigo;
    private String nome;
    private int idade;
    private boolean tipoGamer;
    private int saldo;
    
    public GameShop(int codigo, String nome, boolean tipoGamer, int saldo){
        this.codigo = codigo;
        this.nome = nome;
        this.tipoGamer = tipoGamer;
        this.saldo = saldo;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public int getCodigo() {
        return codigo;
    }
    public String getNome() {
        return nome;
    }
    public int getIdade() {
        return idade;
    }
    public boolean isTipoGamer() {
        return tipoGamer;
    }
    public int getSaldo() {
        return saldo;
    }
    
    public void jogarHoras(int h){
        saldo = saldo - h;
    }
    
    public void comprarHoras(int h){
        if (tipoGamer == true){
            saldo = saldo + h + ((int)(h / 3));
        }
    }
    
    public void brinde(){
        saldo = saldo * 2;
    }
}
