package CoinGame;
public class Resent extends Person
{
    @Override
    public Boolean play() 
    {
        coins--;
        if(last_win){
            return true;
        }
        else{
            return false;
        }
    }
}