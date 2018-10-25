package studio4;


import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Enumeration;

import gnu.io.CommPortIdentifier;
import gnu.io.NoSuchPortException;
import studio4.SerialComm;


public class SerialTestInput {
public static void main(String[] args){
	
	SerialComm variableA = new SerialComm();
	
	 try
     {        	
         
         variableA.connect("COM4"); // Adjust this to be the right port for your machine
         InputStream in = variableA.getInputStream();
         OutputStream out = variableA.getOutputStream();
         // InputStream and OutputStream are now available for use
         // insert code below to use them
         
        	  variableA.getInputStream();
        	  while (1==1){
        	  int bytesAvai = in.available();
        	  	if (bytesAvai > 0){
        	  		byte x = (byte)in.read();
        	  		char y = (char)x;
        	  		System.out.print(y + " ");
        	  	}
        	  }
     }
     catch ( Exception e )
     {
         // TODO Auto-generated catch block
         e.printStackTrace();
     }
	

	
	
}
}
