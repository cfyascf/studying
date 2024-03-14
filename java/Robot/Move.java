package Robot;

public enum Move {
    FOWARD1(1.0), FOWARD2(2.0), BACKWARDS1(-1.0), BACKWARDS2(-2.0);

    Double speed;
    Move(Double value){
        speed = value;
    }

    public Double getMove(){
        return speed;
    }
}
