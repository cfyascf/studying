package conjuntos;

import java.util.HashSet;

public class NumberSet extends Set {
    HashSet<Double> set = new HashSet<Double>();

    public void add(Double var){
        set.add(var);
    }

    public Double get(Integer index){
        Double arr[] = new Double[set.size()];

        int i = 0;
        for(Double ele:set){
            arr[i] = ele;
            i++;
        }

        return arr[index];
    }

    public int size(){
        return set.size();
    }

    @Override
    public Boolean contains(Double var){
        int flag = 0;

        for(int i = 0; i < set.size(); i++){
            if(set.contains(var)){
                flag = 1;
            }
        }

        if(flag == 0){
            return false;
        }
        else{
            return true;
        }
    }
}
