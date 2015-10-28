package UI;

import org.lwjgl.glfw.GLFWKeyCallback;

import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;

/**
 * Created by steppers on 28/10/15.
 */
public class Input {

    private GLFWKeyCallback keyCallback = new GLFWKeyCallback() {
        @Override
        public void invoke(long window, int key, int scancode, int action, int mods) {
            if ( key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE )
                glfwSetWindowShouldClose(window, GL_TRUE);
        }
    };

    public Input(long window)
    {
        glfwSetKeyCallback(window, keyCallback);
    }

    public void release()
    {
        keyCallback.release();
    }

}
