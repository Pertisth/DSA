package main;
import java.util.*;

public class array {
	
	static void Swap(int[] arr,int i,int j)
	{
		int temp;
		temp = arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
	
	static void rotate(int[] arr,int d)
	{
		int n = arr.length;
		int i=0;
		int j=d-1;
		while(i<j)
		{
			Swap(arr,i,j);
			i++;
			j--;
		}
		i=d;
		j=n-1;
		while(i<j)
		{
			Swap(arr,i,j);
			i++;
			j--;
		}
		i=0;
		j=n-1;
		while(i<j)
		{
			Swap(arr,i,j);
			i++;
			j--;
		}
	}
	static void printArr(int[] arr) {
		for(int i=0;i<arr.length;i++)
		{
			System.out.println(arr[i]);
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int [] arr = new int[] {1,2,3,4,5};
		rotate(arr,3);
		printArr(arr);
		

	}

}
