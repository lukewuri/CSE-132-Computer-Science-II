package studio9;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class CountSteps {

	public static void main(String[] args) {
		// FIXME Auto-generated method stub
		ArrayList<String> a = new ArrayList<String>();
		String fileLocation = "data/studio9/data.csv";
		readCSV(fileLocation, a);
	}
	void readCSV(String myFile, ArrayList<String> list1){
		File file = new File(myFile);
		BufferedReader br = null;
		
		try{
			br = new BufferedReader(new FileReader(file));
			String text = null;
			
			while((text = br.readLine())!= null){
				String[] s = text.split(",");
				list1.add((s[0]));
			}
		}catch(FileNotFoundException e){
			e.printStackTrace();
		}catch(IOException e){
			e.printStackTrace();
		}
		try {
			if (br != null){
				br.close();
			}
		} catch(IOException e){
			e.printStackTrace();
		}
	for (int i=0; i < list1.size()-1; i++){
		System.out.print(list1.get(i) + ".....");
	}
}
}
