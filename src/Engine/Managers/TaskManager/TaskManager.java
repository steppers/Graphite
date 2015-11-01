package Engine.Managers.TaskManager;

import Engine.Managers.Manager;

import java.lang.System;
import java.util.ArrayList;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

/**
 * Created by steppers on 01/11/15.
 */
public class TaskManager extends Manager {

    Thread[] threads;
    BlockingQueue<Task> tasks;

    public TaskManager()
    {
        threads = new Thread[Runtime.getRuntime().availableProcessors()];
        tasks = new LinkedBlockingQueue<>();
        for(int i = 0; i < threads.length; i++)
        {
            threads[i] = new TaskThread(i);
            threads[i].start();
        }
    }

    public void submitTasks(ArrayList<Task> tasks)
    {
        for(Task t : tasks)
        {
            this.tasks.add(t);
        }
    }

    public void submitTask(Task task)
    {
        tasks.add(task);
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

        public TaskThread(int id)
        {
            this.id = id;
        }

        public void run()
        {
            while(true)
            {
                try {
                    Task t = tasks.take();
                    if(t == null)
                        break;
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
