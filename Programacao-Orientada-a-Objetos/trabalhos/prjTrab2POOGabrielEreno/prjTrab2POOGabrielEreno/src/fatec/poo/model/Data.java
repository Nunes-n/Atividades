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
public class Data {
    private int dia;
    private int mes;
    private int ano;
    
    public Data(int dia, int mes, int ano){
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    public int getDia() {
        return dia;
    }
    public int getMes() {
        return mes;
    }
    public int getAno() {
        return ano;
    }
    
    public String obterData(){
        String d = String.valueOf(dia);
        String m = String.valueOf(mes);
        String a = String.valueOf(ano);
        if (dia < 10){
            d = "0" + d;
        }
        if (mes < 10){
            m = "0" + m;
        }
        return String.valueOf(d + "/" + m + "/" + a);
    }
    
    public int calcDiasCorridos(){
        int[] dMeses = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int somaMeses = 0;
        for (int i = 0; i < mes; i++){
            somaMeses += dMeses[i];
        }
        
        int bissexto = 0;
        if (mes > 2){
            if ((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0)){
                bissexto = 1;
            }
        }
        
        return (int)(((ano - 1) - 1900) * 365.25) + somaMeses + bissexto + dia;
    }
    
    public int subtrairDatas(Data d){
        return Math.abs(this.calcDiasCorridos() - d.calcDiasCorridos());
    }
}
