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
    }
    
}
