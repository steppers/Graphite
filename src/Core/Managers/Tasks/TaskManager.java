package Core.Managers.Tasks;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

/**
 * Created by steppers on 28/10/15.
 */
public class TaskManager {

    private BlockingQueue<Task> taskQueue = new LinkedBlockingQueue<>();
    private TaskThread threads[];

    public TaskManager()
    {
        threads = new TaskThread[Runtime.getRuntime().availableProcessors()];
        for(int i = 0; i < threads.length; i++)
        {
            threads[i] = new TaskThread();
            threads[i].start();
        }
    }

    public void submitTask(Task task)
    {
        try {
            taskQueue.put(task);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void dispose()
    {
        for(TaskThread thread : threads)
        {
            thread.closeThread();
        }
    }

    private class TaskThread extends Thread
    {
        public Task t = null;

        public void run()
        {
            while(true) {
                try {
                    t = taskQueue.take();
                    t.execute();
                } catch (InterruptedException e) {
                    break;
                }
            }
        }

        public synchronized void closeThread()
        {
            interrupt();
        }
    }
}
