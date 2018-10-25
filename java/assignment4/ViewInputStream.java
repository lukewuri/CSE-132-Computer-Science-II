package assignment4;

import java.io.*;

import javax.swing.JFrame;
import studio4.PrintStreamPanel;

public class ViewInputStream extends FilterInputStream {

    final private PrintStreamPanel psp;
    final private PrintStream ps;

    public ViewInputStream(InputStream in) {
        super(in);
        JFrame f = new JFrame("ViewInputStream");
		f.setBounds(100,100,225,300);
        psp = new PrintStreamPanel();
		f.getContentPane().add(psp);
		f.setVisible(true);
        ps = psp.getPrintStream(); 
    }

    public int read() throws IOException {
        // TODO
        // use super.read() to access the next byte from the InputStream
        // also, you can use ps like System.out to print to the new window
    	int incomingByte = super.read();
    	ps.println(Integer.toHexString(incomingByte));
    	return incomingByte;
  
    }
    
}
/*

Reimplement the program you made earlier (with SerialComm) so that it uses this new ViewInputStream. As described in 
lecture, wrap your InputStream in a BufferedInputStream, and wrap that BufferedInputStream in a ViewInputStream.




*/