package sortA_Program;

import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class TestTheClass {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in); 
		
		
        
		Sort sorting = new Sort(); 
		
		System.out.println("\t\t\t\t\t\t\t SORTING PROGRAM");
		while (true) {
 // creates new sets of random numbers. 
			// size can be altered in the code.
			Random random = new Random();
	        int[] arr = new int[10];
	        for (int i = 0; i < arr.length; i++) {
	            arr[i] = random.nextInt(10000);
	        }
			
	        System.out.println();
				
		System.out.println("Unsorted Array: " + Arrays.toString(arr));
		
		System.out.println("Choose your Sorting Algorithms:");
		System.out.println("1. Bogo Sort");
		System.out.println("2. Selection Sort");
		System.out.println("3. Insertion Sort");
	    System.out.println("4. Bubble Sort");
	    System.out.println("5. Quick Sort");
	    System.out.println("6. Shell Sort");
	    System.out.println("7. Merge Sort");
	    System.out.println("8. Gnome Sort");
	    System.out.println("9. Cocktail Sort");
	    System.out.println("10. Radix Sort");
	    System.out.println("0. Exit");
	    
	    int choice = scanner.nextInt(); 
	    
	    if (choice == 0) {
	    	System.out.println("PROGRAM ENDED");
	    	System.exit(0);
	    }
	    if (arr.length == 0) {
	    	System.out.println("Array is empty. Put in values");
	    	continue; 
	    }
	    
	    switch (choice) {
	    case 1: 
	    		sorting.BogoSort(arr);
		    	System.out.println(Arrays.toString(arr));
		    	System.out.println();
		    	continue; 
	    	
	    	
	    case 2:
	    	sorting.SelectionSort(arr);
	    	System.out.println(Arrays.toString(arr));
	    	System.out.println();
	    	continue; 
	    case 3:
	    	sorting.InsertionSort(arr);
	    	System.out.println(Arrays.toString(arr));
	    	System.out.println();
	    	continue; 
	    case 4:
	    	sorting.BubbleSort(arr);
	    	System.out.println(Arrays.toString(arr));
	    	System.out.println();
	    	continue; 
	    case 5:
	    	long startTime = System.nanoTime();
	    	sorting.QuickSort(arr, 0, arr.length - 1);
	    	 long endTime = System.nanoTime();
	 	    double elapsedTime = (endTime - startTime) / 1_000_000.0;
	 	    System.out.printf("Quick Sort took"
	 	   + " %.6f milliseconds to sort the "
	 	   + "array of size %d\n", elapsedTime, arr.length); // this is here due to quick sort being a recursive sort method
	    	System.out.println(Arrays.toString(arr));
	    	System.out.println();
	    	continue; 
	    case 6:
	    	sorting.ShellSort(arr);
	    	System.out.println(Arrays.toString(arr));
	    	System.out.println();
	    	continue; 
	    case 7:
	    	sorting.MergeSort(arr);
	    	long startTime1 = System.nanoTime();
	    	long endTime1 = System.nanoTime();
		    double elapsedTime1 = (endTime1 - startTime1) / 1_000_000.0;
		    System.out.printf("Merge Sort took"
		   + " %.6f milliseconds to sort the "
		   + "array of size %d\n", elapsedTime1, arr.length);
	    	System.out.println(Arrays.toString(arr));
	    	System.out.println();
	    	continue; 
	    case 8:
	    	sorting.GnomeSort(arr);
	    	System.out.println(Arrays.toString(arr));
	    	System.out.println();
	    	continue; 
	    case 9:
	    	sorting.CocktailSort(arr);
	    	System.out.println(Arrays.toString(arr));
	    	System.out.println();
	    	continue; 
	    case 10:
	    	sorting.RadixSort(arr);
	    	System.out.println(Arrays.toString(arr));
	    	System.out.println();
	    	continue; 
	    case 0:
	    	System.out.println("PROGRAM ENDED");
	    	break; 
	    default:
	    	System.out.println("Invalid choice");
	    	System.out.println();
	    	continue; 
	    }
	   break; 
	    }
	    
	}

	}

