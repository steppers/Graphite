package UI;

import Maths.Vector2i;
import org.lwjgl.opengl.GL;
import org.lwjgl.opengl.GL11;

import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;
import static org.lwjgl.system.MemoryUtil.*;

/**
 * Created by steppers on 28/10/15.
 */
public class Window {

    private Vector2i resolution;
    private boolean fullscreen, vsync;
    private String title;

    private Input input;
    private long window;

    public Window(int width, int height, String title, boolean fullscreen, boolean vsync)
    {
        resolution = new Vector2i(width, height);
        this.fullscreen = fullscreen;
        this.vsync = vsync;
        this.title = title;
        init();
    }

    private void init()
    {
        if ( glfwInit() != GL11.GL_TRUE )
            throw new IllegalStateException("Unable to initialize GLFW");

        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

        window = glfwCreateWindow(resolution.x, resolution.y, title, NULL, NULL);
        input = new Input(window);

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);
        glfwShowWindow(window);
    }

    public void update()
    {
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //glfwSwapBuffers(window);
        glfwPollEvents();
    }

    public boolean isCloseRequested()
    {
        return glfwWindowShouldClose(window) == GL_TRUE;
    }

    public void destroy()
    {
        input.release();
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    public void getContext()
    {
        glfwMakeContextCurrent(window);
        GL.createCapabilities();
    }

    public void setResolution(int width, int height)
    {

    }

    public void setFullscreen(boolean fullscreen)
    {

    }

    public void setVsync(boolean vsync)
    {

    }

    public void setTitle(String title)
    {

    }

    public Input getInput()
    {
        return input;
    }

    public Vector2i getResolution()
    {
        return resolution;
    }

    public boolean isFullscreen()
    {
        return fullscreen;
    }

    public boolean vsyncEnabled()
    {
        return vsync;
    }

}
