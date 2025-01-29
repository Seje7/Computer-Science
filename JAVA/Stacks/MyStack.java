package project2;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

import project2.exceptions.EmptyCollectionException;

public class MyStack {
 
	private int  top, front;
	private String[] nums;
	
	public MyStack(int initialSize) {
				this.top = -1;
		this.nums = new String[initialSize];
	}
	
	public void enQueue(String data) {
		if(isFull()) {
			//top = (top + 1) % nums.length;
			
			 nums[(top+1) % nums.length] = null; // set the value of the front element to 0
			 
			 
		       while(nums[nums.length - 1] != null) {
			
				 String temp = nums[(top+1) % nums.length];
				 nums[(top+1) % nums.length] = nums[(top+2) % nums.length] ; 
				 nums[(top+2) % nums.length] = temp; 
				 
			  top++; 
			}
		        
		
		}
		top++; 
		 
		//top = (top+1) % nums.length;
		if(isEmpty()){
			
		top = (top) % nums.length;
			
			 nums[top] = data; 
			 System.out.println(Arrays.toString(nums));
		}
		
		if(!isEmpty()){
			front = (front) % nums.length;
		top = (top) % nums.length;
			
			 nums[top] = data; 
			 System.out.println(Arrays.toString(nums));
		}
	//	System.out.println(Arrays.toString(nums));
		
	}
	
	public void deQueue() {
		String temp; 
		if(isEmpty()) {
			 System.out.println("Stack is Empty");
		}
			 temp = nums[top];
			
			if(top == top) {
				temp = nums[top];
		System.out.println("Popped element: " + temp);
		nums[top]  = null ;
		System.out.println(Arrays.toString(nums));
			
			top--;
			}
		}
		
	
	public void peek () {
		if (isEmpty()) {
			 System.out.println("Stack is Empty");
		}
		String peeked = nums[top];
		if (peeked != null) {
            System.out.println("Peeked element: " + peeked);
            System.out.println(Arrays.toString(nums));
        } 
	}
	
	public void stop() {
		System.out.print("Last Elements in the stack: ");
		System.out.println(Arrays.toString(nums));
		 System.out.println("First program ended \n\n");
	}
	
	public boolean isEmpty() {
		return top == -1; 
	}
	
	public boolean isFull() { 
		return (top + 1) == nums.length; 
	}
}

