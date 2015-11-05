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

    public Scheduler()
    {
        tasks = new ArrayList<>();
    }

    public void submitTask(Task t)
    {
        tasks.add(t);
    }

    public void executeTasks()
    {
        tm.submitTasks(tasks);

        tasks.clear();
    }

    public void waitForCompletion()
    {
        tm.waitForTaskCompletion();
    }

    public void destroy()
    {
        tm.stop();
    }

}
