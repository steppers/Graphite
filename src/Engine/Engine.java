package Engine;

import Engine.Debug.Logger;
import Engine.Framework.Scheduler;
import Engine.Managers.EnvironmentManager;
import Engine.Managers.StateManager;
import Engine.Managers.TaskManager.TaskManager;
import Engine.Systems.System;

import java.util.ArrayList;

/**
 * Created by steppers on 01/11/15.
 */
public class Engine {

    //Global Engine Objects
    private static Logger logger;

    //Framework objects
    private Scheduler scheduler;

    //Loaded Systems
    private ArrayList<System> systems;

    //Engine status variables
    private Boolean running = false;

    public Engine()
    {
        systems = new ArrayList<>();
        scheduler = new Scheduler();
        logger = new Logger();
        initManagers();
    }

    private void initManagers()
    {
        TaskManager.getInstance().init();
        EnvironmentManager.getInstance().init(this);
        StateManager.getInstance().init();
    }

    public void start()
    {
        running = true;
        loop();
    }

    public void stop()
    {
        synchronized (running)
        {
            running = false;
        }
    }

    public void dispose()
    {
        scheduler.destroy();
        logger.destroy();
        for(System s : systems) //Destroy systems
        {
            s.destroy();
        }
    }

    private void loop()
    {
        long delta;
        long currentTime, lastTime;

        while(true)
        {
            synchronized (running){
                if(!running)
                    break;
            }

            for(System s : systems)
                scheduler.submitTask(s);
            scheduler.executeTasks();
            scheduler.waitForCompletion();
        }
    }

    public void addSystem(System system)
    {
        systems.add(system);
    }

    public static Logger getLogger()
    {
        return logger;
    }

    public void enableDebugMode(boolean enabled)
    {
        logger.debugEnable(enabled);
    }

}
