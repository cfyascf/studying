package CoinGame;
public class Copycat extends Person 
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