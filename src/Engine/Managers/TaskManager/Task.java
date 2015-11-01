package Engine.Managers.TaskManager;

/**
 * Created by steppers on 01/11/15.
 */
public interface Task
{
    void execute(TaskManager.TaskThread thread);
}