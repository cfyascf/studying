package Exceptions;

import java.lang.Exception;

public class NegativeDelt extends Exception {
    public NegativeDelt(){
        super("Valor do delta negativo");
    }
}
