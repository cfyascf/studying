package Exceptions;

public class Main {
    public static void main(String[] args){
        QuadraticSoluction solucao = new QuadraticSoluction();
        solucao = Equation.system(1.0, 2.0, 3.0, 4.0, 5.0, 4.0);
        System.out.println(solucao.getSolution1());
        System.out.println(solucao.getSolution2());
    }
}
