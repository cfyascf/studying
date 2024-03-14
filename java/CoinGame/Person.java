package CoinGame;
public abstract class Person
{
    public Integer coins;
    public Boolean last_win;

    public Person(){
        coins = 10;
        last_win = true;
    }

    public abstract Boolean play();

    public void win(Integer qty){
        coins += qty;
        last_win = true;
    }
    
    public Integer get_coins(){
        return coins;
    }
}