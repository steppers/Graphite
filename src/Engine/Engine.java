package Engine;

import Engine.Debug.Logger;
import Engine.Framework.Scheduler;
import Engine.Systems.System;

import java.util.ArrayList;

/**
 * Created by steppers on 01/11/15.
 */
public class Engine {

    private static Logger logger;

    private Scheduler scheduler;

    private ArrayList<System> systems;

    private boolean running = false;

    public Engine()
    {
        systems = new ArrayList<>();
        scheduler = new Scheduler();
        logger = new Logger();
    }

    public void start()
    {
        running = true;
        loop();
    }

    public void dispose()
    {
        scheduler.destroy();
        logger.destroy();
    }

    private void loop()
    {
        long delta;
        long currentTime, lastTime;

        while(running)
        {
            for(System s : systems)
                scheduler.submitTask(s);
            scheduler.executeTasks();
            scheduler.waitForCompletion();

            running = false;
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
