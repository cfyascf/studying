package conjuntos;

public class Main {

    public static void main(String[] args){
        NumberSet set1 = new NumberSet();
        NumberSet set2 = new NumberSet();

        set1.add(3.0);
        set1.add(15.0);
        set1.add(45.0);
        set1.add(1.0);

        set2.add(3.0);
        set2.add(22.0);
        set2.add(78.0);
        set2.add(1.0);

        IntersectionSet newset = new IntersectionSet();
        newset = Sets.intersect(set1, set2);

        System.out.println(newset);
    }
}
