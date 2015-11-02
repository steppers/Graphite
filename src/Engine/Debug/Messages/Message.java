package Engine.Debug.Messages;

import java.util.HashMap;

/**
 * Created by steppers on 02/11/15.
 */
public class Message
{
    protected HashMap<String, Object> data;

    public Message()
    {
        data = new HashMap<>();
    }

    protected void addData(String key, Object data)
    {
        this.data.put(key, data);
    }

    public HashMap<String, Object> getData()
    {
        return data;
    }

    public void print()
    {
        for(String o : data.keySet())
            System.out.println(o + ": " + data.get(o));
    }

}