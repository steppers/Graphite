package Engine.Debug.Messages;

/**
 * Created by steppers on 02/11/15.
 */
public class WarningMessage extends Message
{
    public WarningMessage(String source, String message)
    {
        addData("SRC", source);
        addData("WRN", message);
    }
}