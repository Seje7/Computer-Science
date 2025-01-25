package sortA_Program;

import java.util.Arrays;
import java.util.Random;

public class Sort {
 	
	/* 
	 * Bogo Sort is a highly inefficient sorting algorithm that works by shuffling the
	 *  elements of the list repeatedly until the list is sorted. It has an 
	 * average-case time complexity of O(n*n!), where n is the length of the list.
	 */
	public void BogoSort(int[] array){ 
		  long startTime = System.nanoTime();
		// Java Program to implement BogoSort
			// Sorts array a[0..n-1] using Bogo sort
				// if array is not sorted then shuffle the
				// array again
				while (isSorted(array) == false) {
					shuffle(array);
				}
				long endTime = System.nanoTime();
			    double elapsedTime = (endTime - startTime) / 1_000_000.0;
			    System.out.printf("Bogo Sort took"
			   + " %.6f milliseconds to sort the "
			   + "array of size %d\n", elapsedTime, array.length);
			}

	// these are all separate methods. 
			// To generate permutation of the array
			void shuffle(int[] array)
			{
				// Math.random() returns a double positive
				// value, greater than or equal to 0.0 and
				// less than 1.0.
				for (int i = 1; i < array.length; i++)
					// Swapping 2 elements
			LetUsSwap(array, i, (int)(Math.random() * i));
			}
	
			// To check if array is sorted or not
			boolean isSorted(int[] array)
			{
				for (int i = 1; i < array.length; i++) {
					if (array[i] < array[i - 1]) {
						return false;
				}
				}
				return true;
				 // https://www.geeksforgeeks.org/bogosort-permutation-sort/#
			}

	/*
	 * Selection Sort is a simple sorting algorithm that works by repeatedly finding 
	 * the minimum element from the unsorted part of the array and moving it
	 *  to it's sorted position. It has a time complexity of O(n^2), 
	 *  where n is the length of the array.
	 */
	public void SelectionSort(int[] array){
		  long startTime = System.nanoTime();
	for(int min = 0; min < array.length ; min++) {
		int min_value = min; 
			for (int target = min + 1; target < array.length; target++) {
				if (array[min_value] > array[target] ) {
					min_value = target; 
				}
			}
			int temp = array[min_value];
			array[min_value] = array[min];
			array[min] = temp; 
			// https://www.youtube.com/watch?v=qI3I7skEVdU
		}
	long endTime = System.nanoTime();
    double elapsedTime = (endTime - startTime) / 1_000_000.0;
    System.out.printf("Selection Sort took"
   + " %.6f milliseconds to sort the "
   + "array of size %d\n", elapsedTime, array.length);
	}	
	
	/*
	 * Insertion Sort is a simple sorting algorithm that works
	 *  by repeatedly inserting each element of the array into its correct position
	 *   in the sorted part of the array.
	 *   It has a time complexity of O(n^2).
	 */
	public void InsertionSort(int[] array){
		  long startTime = System.nanoTime();
		for (int max = 1; max < array.length; max++) {
			int target = array[max];
		int min = max - 1; 
		while (min >= 0 && array[min] > target ) {
			array[min + 1] = array[min]; 
			min--; 
		}
			array[min + 1] = target;  
			// https://www.youtube.com/watch?v=nKzEJWbkPbQ&t=6s
		}
		long endTime = System.nanoTime();
	    double elapsedTime = (endTime - startTime) / 1_000_000.0;
	    System.out.printf("Insretion Sort took"
	   + " %.6f milliseconds to sort the "
	   + "array of size %d\n", elapsedTime, array.length);	
	}
	/*
	 * Bubble Sort is a simple sorting algorithm that works by repeatedly swapping
	 *  adjacent elements if they are in the wrong order.
	 *   It has a time complexity of O(n^2).
	 */
	public void BubbleSort(int[] array){
		  long startTime = System.nanoTime();
		boolean isSorted; 
		for (int min = 0; min < array.length; min++) {
			isSorted = true; 
		for (int max = 1; max < array.length - min; max++) {
		if (array[max] < array[max - 1]) {
			LetUsSwap(array, max, max - 1); 
		isSorted = false; 
		}
		}
		if (isSorted) {
			return;
		}
		//https://www.youtube.com/watch?v=uJLwnsLn0_Q&list=RDCMUCWv7vMbMWH4-V0ZXdmDpPBA&index=3
		}
		long endTime = System.nanoTime();
	    double elapsedTime = (endTime - startTime) / 1_000_000.0;
	    System.out.printf("Bubble Sort took"
	   + " %.6f milliseconds to sort the "
	   + "array of size %d\n", elapsedTime, array.length);
	}
	
	/*
	 * Quicksort is a sorting algorithm,
	 *  which is leveraging the divide-and-conquer principle. 
	 *  It has an average O(n log n) complexity 
	 *  and it's one of the most used sorting algorithms
	 *  especially for big data volumes
	 */
	public void QuickSort(int[] array, int min, int max){
		int pivot;  
		if (min >= max) {
			return; 
		}
		
		int pivotIndex = new Random().nextInt(max - min) + min; 
		pivot = array[pivotIndex]; 
		LetUsSwap(array, pivotIndex, max);
		
		int leftPointer = Partition(array, min, max, pivot);
		// https://www.youtube.com/watch?v=h8eyY7dIiN4. 
		
		QuickSort(array, min, leftPointer - 1);
		QuickSort(array, leftPointer + 1 , max);
		
	}
	
	/*
	 * Shell Sort is a variation of insertion sort that works by sorting subarrays of 
	 * the original array with decreasing gap sizes. 
	 * It has a time complexity that depends on the gap sequence used,
	 *  but it can be as low as O(n log n).
	 */
	public void ShellSort(int[] array){
		  long startTime = System.nanoTime();
	    /* function to sort arr using shellSort */
	   
	        int n = array.length;
	  
	        // Start with a big gap, then reduce the gap
	        for (int gap = n/2; gap > 0; gap /= 2)
	        {
	            // Do a gapped insertion sort for this gap size.
	            // The first gap elements a[0..gap-1] are already
	            // in gapped order keep adding one more element
	            // until the entire array is gap sorted
	            for (int i = gap; i < n; i += 1)
	            {
	                // add a[i] to the elements that have been gap
	                // sorted save a[i] in temp and make a hole at
	                // position i
	                int temp = array[i];
	  
	                // shift earlier gap-sorted elements up until
	                // the correct location for a[i] is found
	                int j;
	                for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
	                    array[j] = array[j - gap];
	  
	                // put temp (the original a[i]) in its correct
	                // location
	                array[j] = temp;
	            }
	        }
	       // https://www.geeksforgeeks.org/shellsort/
	        
	        long endTime = System.nanoTime();
		    double elapsedTime = (endTime - startTime) / 1_000_000.0;
		    System.out.printf("Shell Sort took"
		   + " %.6f milliseconds to sort the "
		   + "array of size %d\n", elapsedTime, array.length);
	}
		
	/*
	 * Merge Sort is a divide-and-conquer sorting algorithm that works by dividing the array into two halves,
	 *  recursively sorting each half,
	 *   and then merging the sorted halves into a single sorted array.
	 *    It has a time complexity of O(n log n).
	 */
	public void MergeSort(int[] array){
		int lengthOfArray = array.length;
		if (lengthOfArray < 2) {
			return;
		}
		int midIndex = lengthOfArray / 2;
		int[] leftHalf = new int[midIndex]; 
		int[] rightHalf = new int[lengthOfArray - midIndex];
		
		for (int min = 0; min < midIndex; min++) {
			leftHalf[min] = array[min];
		}
		for (int min = midIndex; min < lengthOfArray; min++) {
			rightHalf[min - midIndex] = array[min];
		}
		MergeSort(leftHalf);
		MergeSort(rightHalf);
		
		Merge(array, leftHalf, rightHalf);
		// https://www.youtube.com/watch?v=bOk35XmHPKs
	}
	
	/*
	 * Gnome Sort is a sorting algorithm that works by repeatedly comparing adjacent elements
	 *  and swapping them if they are in the wrong order, 
	 *  and then moving back one element in the array to check if the previous elements 
	 *  are in the correct order. It has a time complexity of O(n^2),
	 *  where n is the length of the array.
	 */
	public void GnomeSort(int[] array){
		  long startTime = System.nanoTime();
		int min = 0;
		while (min < array.length) {
			if (min == 0 || array[min] >= array[min-1]) {
				min++; 
			}else {
			LetUsSwap (array, min, min - 1);
			min --;
			}
		}
		
		long endTime = System.nanoTime();
	    double elapsedTime = (endTime - startTime) / 1_000_000.0;
	    System.out.printf("Gnome Sort took"
	   + " %.6f milliseconds to sort the "
	   + "array of size %d\n", elapsedTime, array.length);
	    // https://www.geeksforgeeks.org/gnome-sort-a-stupid-one/. 
	}
	
	/* Cocktail Sort is a variation of bubble sort that works by repeatedly sorting
	 *  the array in both forward and backward directions.
	 *It has a time complexity of O(n^2).
	 */
	public void CocktailSort(int[] array){
		  long startTime = System.nanoTime();
		boolean swapped = true;
        int start = 0;
        int end = array.length;
 
        while (swapped == true)
        {
            // reset the swapped flag on entering the
            // loop, because it might be true from a
            // previous iteration.
            swapped = false;
 
            // loop from bottom to top same as
            // the bubble sort
            for (int min = start; min < end - 1; min++)
            {
                if (array[min] > array[min + 1]) {
                	LetUsSwap(array, min, min + 1);
                    swapped = true;
                }
            }
 
            // if nothing moved, then array is sorted.
            if (swapped == false)
                break;
 
            // otherwise, reset the swapped flag so that it
            // can be used in the next stage
            swapped = false;
 
            // move the end point back by one, because
            // item at the end is in its rightful spot
            end = end - 1;
 
            // from top to bottom, doing the
            // same comparison as in the previous stage
            for (int i = end - 1; i >= start; i--)
            {
                if (array[i] > array[i + 1])
                {
                	LetUsSwap(array, i, i + 1);
                    swapped = true;
                }
            }
 
            // increase the starting point, because
            // the last stage would have moved the next
            // smallest number to its rightful spot.
            start = start + 1;
        }
         // https://www.geeksforgeeks.org/cocktail-sort/#
        
        long endTime = System.nanoTime();
	    double elapsedTime = (endTime - startTime) / 1_000_000.0;
	    System.out.printf("Cocktail Sort took"
	   + " %.6f milliseconds to sort the "
	   + "array of size %d\n", elapsedTime, array.length);
    }
 
	
	/*
	 * Radix Sort is a non-comparative sorting algorithm that sorts the array by grouping elements
	 *  by the digits in their individual place values (e.g. ones, tens, hundreds, etc.),
	 *   and then sorting the groups from least significant digit to most significant digit.
	 *    It has a time complexity of O(nk), where n is the length of the array
	 *  and k is the maximum number of digits in the largest element.
	 */
	public void RadixSort(int[] array){
		    long startTime = System.nanoTime();
		    int maxElement = Arrays.stream(array).max().getAsInt();
		    int place = 1;
		    while (maxElement / place > 0) {
		        int[] count = new int[10];
		        for (int i = 0; i < array.length; i++) {
		            int index = array[i] / place;
		            count[index % 10]++;
		        }
		        for (int i = 1; i < 10; i++) {
		            count[i] += count[i - 1];
		        }
		        int[] output = new int[array.length];
		        for (int i = array.length - 1; i >= 0; i--) {
		            int index = array[i] / place;
		            output[count[index % 10] - 1] = array[i];
		            count[index % 10]--;
		        }
		        for (int i = 0; i < array.length; i++) {
		            array[i] = output[i];
		        }
		        place *= 10;
		    }
		    long endTime = System.nanoTime();
		    double elapsedTime = (endTime - startTime) / 1_000_000.0;
		    System.out.printf("Radix Sort took"
		   + " %.6f milliseconds to sort the "
		   + "array of size %d\n", elapsedTime, array.length);
		    // https://www.geeksforgeeks.org/radix-sort/
		}

	
	// other method used for sorting 
	private static void LetUsSwap(int[] array, int index_1, int index_2) {
		int temp = array[index_1];
		array[index_1] = array[index_2];
		array[index_2] = temp; 
		// https://www.youtube.com/watch?v=h8eyY7dIiN4.
	}
	private int Partition(int[] array, int min, int max, int pivot) {
		
		int rightPointer = max; 
		int leftPointer = min; 
		// https://www.youtube.com/watch?v=h8eyY7dIiN4.
		
		while (leftPointer < rightPointer) {
			
			while (array[leftPointer] <= pivot && leftPointer < rightPointer) {
			leftPointer++; 
		}
			while (array[rightPointer] >= pivot && leftPointer < rightPointer) {
			rightPointer--; 
			}	
			
			LetUsSwap(array, leftPointer, rightPointer);
		}
		LetUsSwap(array, leftPointer, max);
		return leftPointer;
	}
	private static void Merge(int[] array, int[] leftHalf, int[] rightHalf) {
		int left = leftHalf.length;
		int right = rightHalf.length;
		
		int i = 0, j = 0, k = 0; 
		
		while (i < left && j < right) {
			if (leftHalf[i] <= rightHalf[j]) {
		array[k] = leftHalf[i];		
		i++; 
			}else {
				array[k] = rightHalf[j];
				j++;  
		// https://www.youtube.com/watch?v=bOk35XmHPKs
			}
			k++;
		}// if there are still remaining values when merging
		while (i < left) {
			array[k] = leftHalf[i];
			i++;
			k++;
		}
		while (j < right) {
			array[k] = rightHalf[j];
			j++;
			k++;
		}
	}
}
