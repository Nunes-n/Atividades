package fatec.poo.model;

import java.util.ArrayList;

public abstract class Pessoa {
    private String nome;
    private int anoInscricao;
    private double totalCompras;
    private ArrayList<PedidoCompra>pedidos;
    
    public Pessoa(String n, int a){
        nome = n;
        anoInscricao = a;
        
        pedidos = new ArrayList<PedidoCompra>();
    }
    
    public abstract double calcBonus(int a); //polimorfismo total
    
    public void addCompras(double v){
        totalCompras += v;
    }

    public String getNome() {
        return nome;
    }
    public int getAnoInscricao() {
        return anoInscricao;
    }
    public double getTotalCompras() {
        return totalCompras;
    }
    
    public void addPedido(PedidoCompra pedido){
        pedidos.add(pedido);
        totalCompras += pedido.getValor();
        pedido.setPessoa(this);
    }

    public ArrayList<PedidoCompra> getPedidos() {
        return pedidos;
    }
    
}
