import Engine.Debug.Messages.InfoMessage;
import Engine.Engine;
import Engine.Managers.TaskManager.TaskManager;
import Engine.Systems.GraphicsSystem;
import Engine.Systems.System;

/**
 * Created by steppers on 28/10/15.
 */
public class Main
{
    public static void main(String[] args) {
        Engine eng = new Engine();

        //Add systems here
        //eng.addSystem(new TestSystem());
        eng.addSystem(new GraphicsSystem(300, 300, "S-Engine"));

        //Enable sys out logging
        eng.enableDebugMode(true);

        //Start and dispose of the engine when it quits
        eng.start();
        eng.dispose();
    }
}

//Test systems
class TestSystem extends System
{
    @Override
    public void execute(TaskManager.TaskThread thread) {
        Engine.getLogger().logMessage(new InfoMessage("Thread " + thread.getThreadId(), "Test message!"));
    }

    @Override
    public void destroy()
    {

    }
}