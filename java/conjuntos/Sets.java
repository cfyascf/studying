package conjuntos;

public class Sets {
    public static IntersectionSet intersect(NumberSet a, NumberSet b){
        IntersectionSet set = new IntersectionSet();

        for(int i = 0; i < a.size(); i++){
            set.add(a.get(i), a, b);
        }

        return set;
    }
}
