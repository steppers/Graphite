package Core.Systems;

/**
 * Created by steppers on 28/10/15.
 */
public class System {

    private SystemListener listener;

    public void addSystemListener(SystemListener listener)
    {
        this.listener = listener;
    }

    protected void systemChange()
    {
        listener.onSystemChange(this);
    }

}
