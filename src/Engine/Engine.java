package Engine;

import Engine.Managers.TaskManager.Task;
import Engine.Managers.TaskManager.TaskManager;

import java.util.ArrayList;
import java.util.Random;

/**
 * Created by steppers on 01/11/15.
 */
public class Engine {

    TaskManager taskManager;

    public Engine()
    {
        taskManager = new TaskManager();
    }

    public void start()
    {
        ArrayList<Task> tasks = new ArrayList<>();
        tasks.add(new testTask());
        tasks.add(new testTask());
        tasks.add(new testTask());
        tasks.add(new testTask());
        tasks.add(new testTask());
        tasks.add(new testTask());
        tasks.add(new testTask());
        tasks.add(new testTask());
        tasks.add(new testTask());
        tasks.add(new testTask());
        tasks.add(new testTask());
        tasks.add(new testTask());
        taskManager.submitTasks(tasks);
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        taskManager.stop();
    }

    public class testTask implements Task
    {
        @Override
        public void execute(TaskManager.TaskThread thread) {
            Random r = new Random(System.nanoTime());
            float a = r.nextFloat();
            float b = r.nextFloat();
            float c = r.nextFloat();
            System.out.println("Hello from thread " + thread.getThreadId() + ". The answer to " + a + "^3 + " + b + "^2 + " + c + " = " + (a*a*a + b*b + c));
        }
    }

}
