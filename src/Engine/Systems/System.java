package Engine.Systems;

import Engine.Managers.TaskManager.Task;
import Engine.Managers.TaskManager.TaskManager;

/**
 * Created by steppers on 01/11/15.
 */
public abstract class System implements Task {

    public abstract void execute(TaskManager.TaskThread thread);

    public abstract void destroy();

}
