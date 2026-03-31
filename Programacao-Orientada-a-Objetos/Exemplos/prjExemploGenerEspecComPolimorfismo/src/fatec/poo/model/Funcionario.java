package fatec.poo.model;

public abstract class Funcionario { //apresenta um ou mais metodos abstratos
    private int registro;
    private String nome;
    private String dtAdmissao;
    private String cargo;
    
    public Funcionario(int r, String n, String da){
        registro = r;
        nome = n;
        dtAdmissao = da;
    }
    
    //metodo abstrato
    abstract public double calcSalBruto();
    
    public void setCargo(String c){
        cargo = c;
    }
    
    public int getRegistro(){
        return registro;
    }
    public String getNome(){
        return nome;
    }
    public String getDtAdmissao(){
        return dtAdmissao;
    }
    public String getCargo(){
        return cargo;
    }
    
    public double calcDesconto(){
        return 0.1 * calcSalBruto();
    }
    public double calcSalLiquido(){
        return calcSalBruto() - calcDesconto();
    }
}
