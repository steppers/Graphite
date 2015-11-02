package Engine.Debug.Messages;

/**
 * Created by steppers on 02/11/15.
 */
public class InfoMessage extends Message
{
    public InfoMessage(String source, String message)
    {
        addData("SRC", source);
        addData("MSG", message);
    }
}