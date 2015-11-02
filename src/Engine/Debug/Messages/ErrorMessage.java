package Engine.Debug.Messages;

/**
 * Created by steppers on 02/11/15.
 */
public class ErrorMessage extends Message
{
    public ErrorMessage(String source, String message)
    {
        addData("SRC", source);
        addData("ERR", message);
    }
}
