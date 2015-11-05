package Engine.Systems;

import Engine.Debug.Messages.InfoMessage;
import Engine.Managers.EnvironmentManager;
import Engine.Managers.TaskManager.TaskManager;
import UI.Window;
import Engine.Engine;

import static org.lwjgl.opengl.GL11.*;

/**
 * Created by steppers on 03/11/15.
 */
public class GraphicsSystem extends System {

    private Window window;

    public GraphicsSystem(int width, int height, String title)
    {
        window = new Window(width, height, title, false, false);
    }

    @Override
    public void execute(TaskManager.TaskThread thread) {
        //window.getContext();
        //glClearColor(1, 0, 0, 1);
        window.update();

        if(window.isCloseRequested())
        {
            Engine.getLogger().logMessage(new InfoMessage("SYS_Graphics Thread " + thread.getThreadId(), "Close requested. Quitting..."));
            EnvironmentManager.getInstance().stopExecution();
        }
    }

    @Override
    public void destroy()
    {
        window.destroy();
    }

}
