package Engine.Debug;

import Engine.Debug.Messages.Message;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Date;
import java.util.HashMap;

/**
 * Created by steppers on 02/11/15.
 */
public class Logger {

    private boolean DEBUG = false;
    public void debugEnable(boolean enabled){DEBUG = enabled;}

    private BufferedWriter writer;

    public Logger()
    {
        //open a file and keep it open
        try {
            Date date = new Date();
            writer = new BufferedWriter(new FileWriter("Logs/" + date.toString()));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private synchronized void writeMessageToFile(Message m)
    {
        HashMap<String, Object> data = m.getData();
        try {
            for (String i : data.keySet()) {
                writer.append("{" + i + ":" + data.get(i) + "} ");
            }
            writer.append("\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public synchronized void logMessage(Message m)
    {
        if(DEBUG)
            m.print();
        writeMessageToFile(m);
    }

    public void destroy()
    {
        //Close the log file
        try {
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
