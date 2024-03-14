package CoinGame;
import java.util.ArrayList;

public class Main{
    public static void main(String[] args){
        ArrayList<Person> people = new ArrayList<Person>();

        for(int j = 0; j < 50; j++){
            Copycat p1 = new Copycat();
            Cheater p2 = new Cheater();
            people.add(p1);
            people.add(p2);
        }

        for(int i = 0; i < 20; i++){
            Integer j = 0;
            Game g1;
            while(j < people.size()){
                if(people.get(j).coins > 0 && people.get(j + 1).coins > 0)
                {
                    g1 = new Game(people.get(j), people.get(j + 1));
                    g1.round();

                    j += 2;
                }
                else
                {
                    j += 2;
                }
            }
        }

        for(int i = 0; i < people.size(); i++){
            if(people.get(i).coins == 0){
                people.remove(i);
            }
        }

        Integer count1 = 0;
        Integer count2 = 0;
        for(int i = 0; i < people.size(); i++){
            if(people.get(i) instanceof Copycat){
                count1++;
            }
            else if(people.get(i) instanceof Cheater){
                count2++;
            }
        }

        System.out.println(count1);
        System.out.println(count2);

    }
}