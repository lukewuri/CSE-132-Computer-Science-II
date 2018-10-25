package assignment4;

import studio4.SerialComm;
import java.io.*;

public class MsgReceiver {

	final private ViewInputStream vis;
	public final static int magicNumber = 0x21;
	
	public MsgReceiver(InputStream in) {
		vis = new ViewInputStream(in);
	}
	
	public void run(){
		// insert code here
		// read from vis and write to console
		try {
			while(true){
				if (vis.available() > 0){
					if(vis.read() == magicNumber){
						int key = vis.read();
						switch(key){
						case 0x30://debug
							int strLength = vis.read();
							System.out.print("Debug string: ");
							for(int i = 0; i < strLength; ++i){
								System.out.print((char)vis.read());
							}
							System.out.print("  ");
							break;
						case 0x31: //error for temperature
							int strLength2 = vis.read();
							for(int i = 0; i < strLength2; ++i){
								System.out.print((char)vis.read());
							}
							System.out.println();
							break;
						case 0x32://time
							long timeValue = (vis.read() << 24) + (vis.read() << 16) + (vis.read() << 8) + (vis.read());
							System.out.print(" Time elapsed in ms: ");
							System.out.print(timeValue);
							break;
						case 0x33: //potentiometer
							System.out.print("   potentiometer reading is: ");
							System.out.print((vis.read() << 8) + (vis.read()));
							break;
						case 0x34://unfiltered temperature AD
							System.out.print("   A/D reading is: ");
							System.out.print((vis.read() << 8) + (vis.read()));
							break;
						case 0x35://unfiltered temperature C
							System.out.print("   C reading is: ");
							System.out.print((vis.read() << 24)+ (vis.read() << 16)+(vis.read() << 8)+(vis.read()));
							break;
						case 0x36://filtered temperature C
							System.out.print("   Filtered reading is: ");
							System.out.println((vis.read() << 24)+ (vis.read() << 16)+(vis.read() << 8)+(vis.read()));
							break;
						default:
							break;
							}
						}
					}
				}
			}
		catch(Exception e) {
			e.printStackTrace();
		}
		}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
        try
        {        	
            SerialComm s = new SerialComm();
            s.connect("COM5"); // Adjust this to be the right port for your machine
            InputStream in = s.getInputStream();
            MsgReceiver msgr = new MsgReceiver(in);
            msgr.run();
        }
        catch ( Exception e )
        {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

	}

}
