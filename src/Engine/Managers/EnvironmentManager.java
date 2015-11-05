package Engine.Managers;

import Engine.Engine;

/**
 * Created by steppers on 03/11/15.
 */
public class EnvironmentManager extends Manager {

    private static EnvironmentManager instance = new EnvironmentManager();
    public static EnvironmentManager getInstance(){return instance;}

    private Engine engine;

    public void init(Engine engine)
    {
        this.engine = engine;
    }

    public void stopExecution()
    {
        engine.stop();
    }

}
