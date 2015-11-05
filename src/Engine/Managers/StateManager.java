package Engine.Managers;

/**
 * Created by steppers on 01/11/15.
 */
public class StateManager extends Manager {

    private static StateManager instance = new StateManager();
    public static StateManager getInstance(){return instance;}

    private double delta;

    public void init()
    {

    }

    public void setDelta(double delta)
    {
        this.delta = delta;
    }

    public double getDelta()
    {
        return delta;
    }

}
