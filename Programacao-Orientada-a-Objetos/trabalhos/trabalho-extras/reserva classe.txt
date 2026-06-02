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
public class Reserva {
    private int codigo;
    private String nomeHosp; //nome do hospede
    private Data dataEntrada;
    private Data dataSaida;
    private double valorHosped;
    private Hotel hotel;
    
    public Reserva(int codigo, String nomeHosp){
        this.codigo = codigo;
        this.nomeHosp = nomeHosp;
    }

    public void setHotel(Hotel hotel) {
        this.hotel = hotel;
        hotel.addReserva(this);
    }
    public void setDataEntrada(Data dataEntrada) {
        this.dataEntrada = dataEntrada;
    }
    
    public int getCodigo() {
        return codigo;
    }
    public String getNomeHosp() {
        return nomeHosp;
    }
    public Data getDataEntrada() {
        return dataEntrada;
    }
    public Data getDataSaida() {
        return dataSaida;
    }
    public double getValorHosped() {
        return valorHosped;
    }
    public Hotel getHotel() {
        return hotel;
    }
    
    public double encerrarReserva(Data dataSaida){
        this.dataSaida = dataSaida;
        int dias = dataSaida.subtrairDatas(dataEntrada);
        if (dias == 0){
            dias = 1;
        }
        
        return (dias * hotel.getValorDiaria());
    }
}
