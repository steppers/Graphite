import Core.Managers.Tasks.Task;
import Core.Managers.Tasks.TaskManager;

/**
 * Created by steppers on 28/10/15.
 */
public class Tester implements Task
{
    String output = "Complete!";

    public void execute()
    {
        System.out.println(output);
    }

    public static void main(String[] args) {
        TaskManager m = new TaskManager();

        Tester t = new Tester();
        m.submitTask(t);
        m.submitTask(t);
        m.submitTask(t);
        m.submitTask(t);
        m.submitTask(t);
        m.submitTask(t);
        m.submitTask(t);
        m.submitTask(t);
        m.submitTask(t);
        m.submitTask(t);
        m.submitTask(t);
        m.submitTask(t);
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        m.dispose();
    }

}
