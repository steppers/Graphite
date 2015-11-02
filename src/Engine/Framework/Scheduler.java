package Engine.Framework;

import Engine.Managers.StateManager;
import Engine.Managers.TaskManager.Task;
import Engine.Managers.TaskManager.TaskManager;

import java.util.ArrayList;

/**
 * Created by steppers on 01/11/15.
 */
public class Scheduler {

    private ArrayList<Task> tasks;
    private TaskManager tm = TaskManager.getInstance();

    private int frameLimit = 0;
    private long frameTime = 0;
    private long currentTime, lastTime;
    private double delta;

    public Scheduler()
    {
        tasks = new ArrayList<>();
    }

    public void setFrameLimit(int frameLimit)
    {
        this.frameLimit = frameLimit;
        if(frameLimit > 0)
            this.frameTime = 1000/frameLimit;
        else
            this.frameTime = 0;
    }

    public void submitTask(Task t)
    {
        tasks.add(t);
    }

    public void executeTasks()
    {
        currentTime = System.currentTimeMillis();

        try {
            if(delta < frameTime)
                Thread.sleep((long)(frameTime - delta));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        lastTime = System.currentTimeMillis();

        delta = (currentTime - lastTime)/1000L;
        StateManager.getInstance().setDelta(delta);

        tm.submitTasks(tasks);

        tasks.clear();
    }

    public void destroy()
    {
        tm.stop();
    }

}
