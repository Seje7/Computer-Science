package project2;

import java.util.Scanner;

public class Tester {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int length;
		
		Scanner scanner = new Scanner(System.in);
		
		
		
		System.out.println("Enter size of Array: ");
		length = scanner.nextInt();
	//	MyStack myStack = new MyStack(length);
		MyStack circularArray = new MyStack(length);
		
		 while(true) {
			 //System.out.print("Enter values for stack: ");
			//String  = scanner.next();
			
			System.out.println("1. Push"); 
            System.out.println("2. Pop");
            System.out.println("3. Peek");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter the element to push: ");
                   String values = scanner.next();
                    circularArray.enQueue(values);
                    continue; 
                case 2:
                   circularArray.deQueue();
                    continue;
                case 3:
                    circularArray.peek();;
                    continue; 
                case 4:
                	circularArray.stop();
                    break;
                default:
                    System.out.println("Invalid choice!");
                    continue; 
            }
			break; 
		 }
		 while (true) {
			 Scanner input = new Scanner(System.in);
		        System.out.print("Enter an infix expression: ");
		        String infix = input.nextLine();

		        InfixToPostfix infixToPostfix = new InfixToPostfix(infix);
		        String postfix = infixToPostfix.convert();
		        System.out.println("Postfix expression: " + postfix);

		        PostFixEvaluator postFixEvaluator = new PostFixEvaluator(postfix);
		        int result = postFixEvaluator.evaluate();
		        System.out.println("Result: " + result);
		        
		        System.out.print("Do you want to continue, Enter 'yes' if so. 'No' to stop: ");
		         String letter = scanner.next();
		         if (letter.equals("Yes") || letter.equals("yes")) {
		        	 continue; 
		         } else if(letter.equals("No") || letter.equals("no")){
		        	 break; 
		         }
		 }
	     
	       
	}
}