package assignment5;

import java.io.BufferedOutputStream;
import java.io.FilterOutputStream;
import java.io.IOException;
import java.io.OutputStream;

import studio4.SerialComm;

public class SerialOutput{
	public static void main(String args[]){
	try {
		SerialComm s = new SerialComm();
		s.connect("COM7"); // Adjust this to be the right port for your machine
		OutputStream out1 = s.getOutputStream();
		FilterOutputStream fout = new FilterOutputStream(out1);
//		BufferedOutputStream out = new BufferedOutputStream(out1);
		while(true){
			try {
				int x = System.in.read();
				fout.write(x);
			}
			catch (IOException e) {
				// FIXME Auto-generated catch block
				e.printStackTrace();
				}
			}
	}
	 catch (Exception e) {
		// FIXME Auto-generated catch block
		e.printStackTrace();
	}
	}
}	