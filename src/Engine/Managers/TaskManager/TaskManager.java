package Engine.Managers.TaskManager;

import Engine.Managers.Manager;

import java.util.ArrayList;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

/**
 * Created by steppers on 01/11/15.
 */
public class TaskManager extends Manager {

    private static TaskManager instance = new TaskManager();
    public static TaskManager getInstance(){return instance;}

    private TaskThread[] threads;
    private BlockingQueue<Task> tasks;

    public void init()
    {
        threads = new TaskThread[Runtime.getRuntime().availableProcessors()];
        tasks = new LinkedBlockingQueue<>();
        for(int i = 0; i < threads.length; i++)
        {
            threads[i] = new TaskThread(i);
            threads[i].start();
        }
    }

    public void waitForTaskCompletion()
    {
        while(!tasks.isEmpty()){}
        for(TaskThread thread : threads)
        {
            while(true)
            {
                synchronized (thread.hasTask)
                {
                    if(!thread.hasTask)
                        break;
                }
            }
        }
    }

    public void submitTasks(ArrayList<Task> tasks)
    {
        for(Task t : tasks)
        {
            this.tasks.add(t);
        }
    }

    public void stop()
    {
        while(!tasks.isEmpty()){}
        for(Thread t : threads)
        {
            t.interrupt();
        }
    }

    public class TaskThread extends Thread
    {
        private int id;
        private Task t;
        public Boolean hasTask = false;

        public TaskThread(int id)
        {
            this.id = id;
        }

        public void run()
        {
            while(true)
            {
                try {
                    synchronized (hasTask){hasTask = false;}
                    t = tasks.take();
                    synchronized (hasTask){hasTask = true;}
                    t.execute(this);
                } catch (InterruptedException e) {
                    break;
                }
            }
        }

        public int getThreadId()
        {
            return id;
        }
    }
}