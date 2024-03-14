package CoinGame;
public class Agressive extends Person
{
    Integer count = 0;

    @Override
    public Boolean play() 
    {
        coins--;
        if(last_win && count == 0){
            return true;
        }
        else{
            count = 3;
            return false;
        }
    }
}