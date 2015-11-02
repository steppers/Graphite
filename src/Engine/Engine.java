package Engine;

import Engine.Framework.Scheduler;
import Engine.Systems.System;

import java.util.ArrayList;

/**
 * Created by steppers on 01/11/15.
 */
public class Engine {

    private Scheduler scheduler;

    private ArrayList<System> systems;

    private boolean running = false;

    public Engine()
    {
        systems = new ArrayList<>();
        scheduler = new Scheduler();
    }

    public void start()
    {
        running = true;
        loop();
    }

    public void dispose()
    {
        scheduler.destroy();
    }

    private void loop()
    {
        while(running)
        {
            for(System s : systems)
                scheduler.submitTask(s);
            scheduler.executeTasks();
        }
    }

    public void addSystem(System system)
    {
        systems.add(system);
    }

}
