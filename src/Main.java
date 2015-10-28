import UI.Window;

import static org.lwjgl.opengl.GL11.*;

/**
 * Created by steppers on 28/10/15.
 */
public class Main {

    public Window window;

    public Main()
    {
        window = new Window(300, 300, "Window #1", false, false);
        window.getContext();

        glClearColor(1, 0, 0, 1);

        while(!window.isCloseRequested())
        {
            window.update();
        }

        window.dispose();
    }

    public static void main(String[] args) {
        new Main();
    }

}
