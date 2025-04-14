package Begineers;


import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class CaesarAlghorithm {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
	int key = 6;
	String editing = "", options = "";
	String filePath = "";
	// C:\\\\Users\\\\oseje\\\\OneDrive\\\\Documents\\\\Final Project.txt
	
	Scanner scanner = new Scanner(System.in);
	
	System.out.println("DO YOU WANT TO ENCRYPT OR DECRYPT");
	System.out.println("ENTER E FOR ENCRYPT OR D FOR DECRYPT");
	options =  scanner.nextLine();
	
	options = options.toLowerCase();
	
	if (options.equals("e")) {
		
		System.out.println("ENTER THE FILE PATH OF THE FILE");
		System.out.println("FOR EXAMPLE : C:\\\\Users\\\\oseje\\\\OneDrive\\\\Documents"
			+ "\\\\Name of file.txt");
		filePath = scanner.nextLine();
		
		
	
		File file = new File(filePath);
		System.out.println(file); 

		Scanner scan = new Scanner(file);
		//StringBuilder editing = new StringBuilder();
		
		while(scan.hasNextLine()) {
			//System.out.println(scan.nextLine());
			
		 String theLetters = scan.nextLine();
		 
		 editing = editing.concat(EncryptAFile(theLetters, key));
		 editing = editing.concat("\n");
		 

		}
		System.out.println(editing);
		
	} else if (options.equals("d")) {
		
		System.out.println("ENTER THE FILE PATH OF THE FILE");
		System.out.println("FOR EXAMPLE : C:\\\\Users\\\\oseje\\\\OneDrive\\\\Documents"
			+ "\\\\Name of file.txt");
		filePath = scanner.nextLine();
		
		File file = new File(filePath);

		Scanner scan = new Scanner(file);
		
		while(scan.hasNextLine()) {
			//System.out.println(scan.nextLine());
			
		 String theLetters = scan.nextLine();
		 
		 editing = editing.concat(DecryptAFile(theLetters, key));
		 editing = editing.concat("\n");
		 

		}
		System.out.println(editing);
		
	}
		
	System.out.println("DO YOU WANT TO WRITE TO A FILE: Y/N");
	options =  scanner.nextLine();
	options = options.toLowerCase();
	
	
	if (options.equals("y")) {
		
		System.out.println("ENTER THE FILE PATH TO WRITE TO");
		System.out.println("FOR EXAMPLE : C:\\Users\\oseje\\OneDrive\\Documents"
				+ "\\Name of file.txt");
		filePath = scanner.nextLine();
		FileWriter writer = new FileWriter(filePath);
		writer.write(editing);
		writer.close();
		
	} else if (options.equals("n")) {
		System.exit(0);
	}
		
	
	
	
	// Decryption 
	 
	}
	
	public static String EncryptAFile(String letters, int key) {
		
	StringBuilder editing = new StringBuilder();
		
	letters = letters.toLowerCase();
	 
	 
	for (int i = 0; i < letters.length(); i++)  {
		char c = letters.charAt(i);
		
	if (Character.isLetter(c)) {
		c = (char)((c - 'a' + key + 26) % 26 + 'a');
	}
			
	editing.append(c);
		
}
		
		
		
		return editing.toString();
	}
	
	public static String DecryptAFile(String letters, int key) {
		
	StringBuilder editing = new StringBuilder();
		
	letters = letters.toLowerCase();
	 
	 
	for (int i = 0; i < letters.length(); i++)  {
		char c = letters.charAt(i);
		
	if (Character.isLetter(c)) {
		c = (char)((c - 'a' - key + 26) % 26 + 'a');
	}
			
	editing.append(c);
		
}
		
		
		
		return editing.toString();
	}
	
	// c = (char)((c - 'a' + key + 26) % 26 + 'a');
	}


	






