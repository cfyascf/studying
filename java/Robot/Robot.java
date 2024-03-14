package Robot;

import java.lang.Math;
import java.util.ArrayList;

public class Robot {
    private Double x = 0.0;
    private Double y = 0.0;
    private Double angle = 0.0;
    private Double move = 0.0;
    private static ArrayList<Robot> robots = new ArrayList<Robot>();

    public Robot(){
        robots.add(this);
    }

    public void move(){
        Double cos = Math.cos(angle);
        Double sin = Math.sin(angle);
        x += move * Math.toRadians(cos);
        y += move * Math.toRadians(sin);
    }

    public void setRotation(Rotate dir) {
        angle += dir.getAngle();
    }

    public void setSpeed(Move dir) {
        move = dir.getMove();
    }

    public static void moveAll(){
        for(Robot robot : robots){
            robot.move();
        }
    }

    public String toString(){
        return "X:" + x + " | Y:" + y;
    }
}
