package fatec.poo.model;

public class PedidoCompra {
    private int numero;
    private String dataPedido;
    private double valor;
    private Pessoa pessoa;
    
    public PedidoCompra(int n){
        numero = n;
    }
    
    public void setDataPedido(String dataPedido){
        this.dataPedido = dataPedido;
    }
    public void setValor(double valor) {
        this.valor = valor;
    }
    public void setPessoa(Pessoa peassoa){
        this.pessoa = pessoa;
    }

    public String getDataPedido() {
        return dataPedido;
    }
    public double getValor() {
        return valor;
    }
    public int getNumero() {
        return numero;
    }
    public Pessoa getPessoa() {
        return pessoa;
    }
}
