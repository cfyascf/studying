package pi;


import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;
import java.lang.Math;;

public class Main {
    public static void main(String[] args){
        Double x = 0.0;
        Double y = 0.0;
        Double value = 0.0;
        Integer flag = 0;
        Integer pontos = 0;

        Random seed = new Random();

        Scanner scan = new Scanner(System.in);

        try{
            System.out.println("Insira a quantidade de pontos desejada: ");
            pontos = scan.nextInt();
        }
        catch(Exception e){
            throw new InputMismatchException();
        }
        finally{
            scan.close();
        }


        for(int i = 0; i < pontos; i++){
            value = seed.nextDouble();
            x = value;
            value = seed.nextDouble();
            y = value;

            if(Math.sqrt((x * x) + (y * y)) < 1){
                flag++;
            }
        }

        System.out.println(flag * 4);
    }
}
