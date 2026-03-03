

public class Aaplic {
    public static void main(String[] args) {
        Retangulo objRet; //ponteiro que pode acessar Retangulo
        objRet = new Retangulo(); //instanciação (alocação) do objeto na memória
        
        objRet.setAltura(5.0);
        objRet.setBase(8.0);
        
        System.out.println("medida da altura do retangulo: " + objRet.getAltura());
        System.out.println("medida da base do retangulo: " + objRet.getBase());
        
        System.out.println("medida da area do retangulo: " + objRet.calcArea());
        System.out.println("medida do perimetro do retangulo: " + objRet.calcPerimetro());
        
        System.out.println("medida da diagonal do retangulo: " + objRet.calcDiagonal());
        
        
        Retangulo objRet1 = new Retangulo();
        
        objRet1.setAltura(3.0);
        objRet1.setBase(4.0);
        
        System.out.println("\n\nmedida da altura do retangulo: " + objRet1.getAltura());
        System.out.println("medida da base do retangulo: " + objRet1.getBase());
        
        System.out.println("medida da area do retangulo: " + objRet1.calcArea());
        System.out.println("medida do perimetro do retangulo: " + objRet1.calcPerimetro());
        
        System.out.println("medida da diagonal do retangulo: " + objRet1.calcDiagonal());
        
        
    }
    
}
