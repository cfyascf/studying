package conjuntos;

import java.util.ArrayList;

public class IntersectionSet extends Set {
    ArrayList<Double> intersection = new ArrayList<Double>();

    public void add(Double var, Set set1, Set set2){
        if(set1.contains(var) && set2.contains(var)){
            intersection.add(var);
        }
        else{
            return;
        }
    }

    @Override
    public Boolean contains(Double var){
        if(intersection.contains(var)){
            return true;
        }
        else{
            return false;
        }
    }
}
