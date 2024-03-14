package Robot;

public enum Rotate {
    LEFT15(-15), LEFT30(-30), RIGHT15(15), RIGHT30(30);

    double angle;
    Rotate(double value){
        angle = value;
    }

    double getAngle() {
        return angle;
    }
}
