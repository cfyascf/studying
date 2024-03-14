package CoinGame;
public class Game
{
    public Person p1;
    public Person p2;
    public Integer rounds;

    public Game(Person pA, Person pB)
    {
        p1 = pA;
        p2 = pB;
    }

    public void round()
    {
        Boolean move_p1 = p1.play();
        Boolean move_p2 = p2.play();

        if(move_p1 && move_p2)
        {
            p1.win(2);
            p2.win(2);
        }

        else if(move_p1 && move_p2 == false)
        {
            p2.win(4);
            p1.last_win = false;
        }

        else if(move_p1 == false && move_p2)
        {
            p1.win(4);
            p2.last_win = false;
        }

        else if(move_p1 == false && move_p2 == false)
        {
            p1.last_win = false;
            p2.last_win = false;
        }
    }
}