package CoinGame;
public class Cheater extends Person
{
    @Override
    public Boolean play() 
    {
        coins--;
        return false;
    }
}