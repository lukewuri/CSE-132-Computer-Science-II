package assignment10;

import studio4.SerialComm;
import studio4.ViewInputStream;

import java.io.*;


public class Health {

	final private ViewInputStream vis;
	final private DataInputStream data;
	
	public Health(InputStream in) {
		vis = new ViewInputStream(in);
		data = new DataInputStream(in);
		
	}
	
	public enum State{waitingForMagicNumber, waitingForInputType, readingSteps, readingPulse} 
	
	public void run() throws IOException {
					State state = State.waitingForMagicNumber;
					while(true) {
						if(vis.available() > 0) {

							
							State nextState = null;
							
							switch(state) {
								case waitingForMagicNumber:
									// read a byte
									if(vis.read() == 0x21) {
										nextState = State.waitingForInputType;
										
									} else {
										nextState = State.waitingForMagicNumber;
									}
									break;
								case waitingForInputType:
									int input = vis.read();

									if (input == 0x30){
	
										nextState = State.readingSteps;
									}
									
									if (input == 0x31){
										
										nextState = State.readingPulse;
									}

									break;
								case readingSteps:
//									
									int stepsByte1 = vis.read()*256;
									int stepsByte2 = vis.read();
									int steps = stepsByte1 +stepsByte2;
									System.out.println("Steps: " + steps);
									nextState = State.waitingForMagicNumber;
									break;
//									
								case readingPulse:
									
									int pulseByte1 = vis.read()*256;
									int pulseByte2 = vis.read();
									int pulse = pulseByte1 + pulseByte2;
									System.out.println("Pulse: " + pulse);
									nextState = State.waitingForMagicNumber;
									break;
			
								default:
									nextState = State.waitingForMagicNumber;
									System.out.println("ERROR");
									break;
							}
							state = nextState;
						}
					}
			}
		//}
	//}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
        try
        {        	
            SerialComm s = new SerialComm();
            s.connect("COM7"); // Adjust this to be the right port for your machine
            InputStream in = s.getInputStream();
            Health msgr = new Health(in);
            msgr.run();
        }
        catch ( Exception e )
        {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

	}

}
