package CoinGame;
public class Kind extends Person 
{    
    @Override
    public Boolean play() 
    {
        coins -= 2;
        return true;
    } 
}