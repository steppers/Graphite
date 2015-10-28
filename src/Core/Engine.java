package Core;

import UI.Window;

import static org.lwjgl.opengl.GL11.glClearColor;

/**
 * Created by steppers on 28/10/15.
 */
public class Engine {

    private Window window;

    private boolean isRunning;

    public Engine()
    {
        window = new Window(300, 300, "Engine V1", false, true);
    }

    public void start()
    {
        isRunning = true;
        loop();
    }

    private void loop()
    {
        window.getContext();

        glClearColor(1, 0, 0, 1);
        while(isRunning)
        {
            //Game logic here

            window.update();

            if(window.isCloseRequested())
                isRunning = false;
        }
        window.dispose();
    }

}
