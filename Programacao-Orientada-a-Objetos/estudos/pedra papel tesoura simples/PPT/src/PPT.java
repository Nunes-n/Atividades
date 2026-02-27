import java.util.Scanner;

public class PPT {
    public static void main(String[] args) throws InterruptedException {
        Scanner scanner = new Scanner(System.in);

        int user = -1;
        int userPoints = 0;
        int machinePoints = 0;

        while (true){

        //escolha do usuario
            while (true) {
                System.out.println("0 - sair\n");
                System.out.println("1 = PEDRA");
                System.out.println("2 = PAPEL");
                System.out.println("3 = TESOURA");
                System.out.print("Faça sua escolha: ");

                user = scanner.nextInt();
                if ((user < 0) || (user > 3)) {
                    System.out.println("\n[Escolha inválida, tente novamente]");
                    System.out.println("\n\n--------------------------------------");
                }
                else {
                    break;
                }
            }

            if (user == 0){
                break;
            }
        

            //encontrar correspondente
            String userChoice = escolha(user);

            //escolha da maquina
            int machine = ((int) (Math.random() * 3)) + 1;

            //enconrar correspondente
            String machineChoice = escolha(machine);

            System.out.println("\n*maquina escolheu " + machineChoice);
            System.out.println("[" + userChoice + " x " + machineChoice + "]");

            //comparar as escolhas
            if (user == machine){
                System.out.println("\nEMPATE");
            }
            else {
                if (((user == 1) && (machine == 2)) || 
                    ((user == 2) && (machine == 3)) || 
                    ((user == 3) && (machine == 1))){
                    System.out.println("\nPERDEU");
                    machinePoints += 1;
                }
                else{
                    System.out.println("\nVENCEU");
                    userPoints += 1;
                }
            }

            System.out.println("você: " + userPoints + "\nmaquina: " + machinePoints);

            System.out.println("\nespere 5 segundos para jogar de novo");
            Thread.sleep(5000);

            System.out.println("\n\n\n\n\n--------------------------------------");

        }

        scanner.close();
    }

    public static String escolha (int choice){
        if (choice == 1){
            return "pedra";
        }
        if (choice == 2){
            return "papel";
        }
        if (choice == 3){
            return "tesoura";
        }
        return "";
    }
}
