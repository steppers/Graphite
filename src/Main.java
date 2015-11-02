import Engine.Debug.Messages.InfoMessage;
import Engine.Engine;
import Engine.Managers.TaskManager.TaskManager;
import Engine.Systems.System;

/**
 * Created by steppers on 28/10/15.
 */
public class Main {

    public static void main(String[] args) {
        Engine eng = new Engine();

        //Add systems here
        eng.addSystem(new TestSystem());
        eng.addSystem(new TestSystem2());

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
        Engine.getLogger().logMessage(new InfoMessage("Test system", "Test message!"));
    }
}

class TestSystem2 extends System
{
    @Override
    public void execute(TaskManager.TaskThread thread) {
        Engine.getLogger().logMessage(new InfoMessage("Test system2", "Test message 2!"));
    }
}