package Exceptions;

import java.lang.Math;

public class Equation {
    public static QuadraticSoluction quadratic(Double a, Double b, Double c){
        if(a == 0){
            throw new ArithmeticException();
        }

        Double delt = (b * b) - (4 * a * c);

        if(delt < 0){
            throw new ArithmeticException(); 
        }

        Double x1 = ((-b) + Math.sqrt(delt)) / (2 * a);
        Double x2 = ((-b) - Math.sqrt(delt)) / (2 * a);
        
        QuadraticSoluction solution = new QuadraticSoluction();
        solution.setSolution1(x1);
        solution.setSolution2(x2);

        return solution;
    }

    public static Double linear(Double a, Double b){
        if(a == 0){
            throw new ArithmeticException();
        }

        Double x = -b / a;

        return x;
    }

    public static QuadraticSoluction system(Double a, Double b, Double c, Double d, Double e, Double f){
        Double y = ((a * f) - (d * c)) / ((-d * b) + (a * e));
        Double x = (c - (b * y)) / a;

        QuadraticSoluction solution = new QuadraticSoluction();
        solution.setSolution1(x);
        solution.setSolution2(y);

        return solution;
    }
}
