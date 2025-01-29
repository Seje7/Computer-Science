package project2;

import java.util.Scanner;

public class AirlineSeats {
	static int count = 0; // to count the amounts of seats filled 
	// static variable so that it is accessible by all parts of the class
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// two-Dimensional array with 5 rows and 4 columns
	char [][] layout = { {'A', 'B','C','D'},
				 {'A', 'B','C','D'}, 
				 {'A', 'B','C','D'},
				 {'A', 'B','C','D'},
				 {'A', 'B','C','D'}};
		
		
		String seats = " "; //For holding the seat value 
		Scanner scanner = new Scanner(System.in); // for entering the seat number
	
		System.out.println("Welcome to the Airplane Seating Reservation System.");
		System.out.println("enter a seat you wish to reserve i.e 1A - 5D");
		System.out.println("Enter -1 to stop the program"); // airplane title
		
		System.out.print("Enter seat: ");
		seats = (scanner.nextLine());
		//seats = scanner.nextLine();
	
		if(seats.equals("-1")) { // to check if the program should stop
			System.out.println("end of program");
			System.exit(0); // to terminate the program
		}
			while (count < 20) {
		 int row = seats.charAt(0) - '1'; // to assign values to the rows
		 int col = seats.charAt(1) - 'A'; // to assign values to the columns
		
		 
		if (row < 0 || row > 5 || col  < 0 || col > 4) { // to ensure the seat number 
			// is within a range 
			System.out.println("Enter a seat number between 0 and 5");
			seats = scanner.nextLine();
			if (seats.equals("-1")) { // to check if the program should stop
                System.out.println("Program ended.");
                System.exit(0); // to terminate the program
            }
		}else {
			
		    if (layout[row][col] != 'X') {
                layout[row][col] = 'X'; // to mark the chosen seat
                count ++;
                System.out.println(" ");
                displaySeats(layout); // to print the airplane seats 
            }
		    if (count < 20) { // checking if all seats are filled 
		    	System.out.print("Enter seat that is not filled: ");
              seats = scanner.nextLine();
            if (seats.equals("-1")) { // to check if the program should stop
                System.out.println("Program ended.");
                System.exit(0); // to terminate the program
                }
		}
		    
		}
		}

	}
		public static void displaySeats(char [][] plane)
		{ // to display each row and column on the table
			for (int row = 0; row < plane.length; row++)
		    {	System.out.print("   " + (row + 1) + " "+ plane[row][0] 
		    		+ " " + plane[row][1]+ " " + plane[row][2]
		    				+ " " + plane[row][3]);
			//	add for loop to display one row
		    //     display row
		       System.out.println();
		    }
			int numberOfSeatsAvailable = (20 - count); // checks the number of 
			// seats remaining 
	        System.out.println("There are " + numberOfSeatsAvailable +
	        		" seats available.");
		}

}

