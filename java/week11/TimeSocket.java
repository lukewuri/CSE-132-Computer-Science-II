package week11;

import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;
import java.io.DataInputStream;

/**
 * This program makes a socket connection to the atomic clock in Fort Collins, Colorado, and prints the
 * time that the server sends.
 * 
 * 1. Create a socket to the server and port.
 * 2. Create an InputStream and wrap it in a DataInputStream.
 * 3. Put the program to sleep for a second or else it runs too quickly.
 * 3. Read and print the data. Note: The first line we will read is blank, we'll have to ignore that.
 * 
 * @author Joshua Gelbard
 */

public class TimeSocket
{
   public static void main(String[] args) throws InterruptedException
   {
      try
      {
    	//Servers and status: http://tf.nist.gov/tf-cgi/servers.cgi
    	//Use port 13 for date and time
    	//Socket API: https://docs.oracle.com/javase/7/docs/api/java/net/Socket.html

         Socket s = new Socket("24.56.178.140", 13);
         try
         {
        	 InputStream inStream = s.getInputStream();
        	 DataInputStream in = new DataInputStream(inStream);
        	 Thread.sleep(1000);
        	 
        	 while (in.available() > 0){
        		 int line = in.readByte();
        		 System.out.print((char)line);
        	 }
        	 
         }
         finally
         {
            s.close();
         }
      }
      catch (IOException e)
      {
         e.printStackTrace();
      }
   }
}
