package Merge;

import java.util.*;

public class MergeThreeSortedArrays {
	
	 static void merge3SortedArrays(int[] a,int[] b, int[] c)
	{
		int m = a.length;
		int n = b.length;
		int o = c.length;
		int i=0,j=0,k=0;
		ArrayList<Integer> List = new ArrayList<Integer>();
		while(i<m && j<n && k<o)
		{
			int newEle = Math.min(Math.min(a[i], b[j]),c[k]);
			List.add(newEle);
			
			if(newEle == a[i])
			{
				i++;
			}
			else if(newEle == b[j])
			{
				j++;
			}
			else
			{
				k++;
			}
		}
		
		while(i<m && j<n)
		{
			if(a[i]<=b[j])
			{
				List.add(a[i++]);
			}
			else
			{
				List.add(b[j++]);
			}
		}
		while(j<n && k<o)
		{
			if(b[j]<=c[k])
			{
				List.add(b[j++]);
			}
			else
			{
				List.add(c[k++]);
			}
		}
		while(k<o && i<m)
		{
			if(c[k]<=a[i])
			{
				List.add(c[k++]);
			}
			else
			{
				List.add(a[i++]);
			}
		}
		
		while(i<m)
		{
			List.add(a[i++]);
		}
		while(j<n)
		{
			List.add(b[j++]);
		}
		while(k<o)
		{
			List.add(c[k++]);
		}
		
		for(Integer x:List)
		{
			System.out.print(x+" ");
		}
	}

	public static void main(String[] args) {
		
		int[] a = {1, 2, 41, 52, 84};
		int[] b = {1, 2, 41, 52, 67};
		int[] c = {1, 2, 41, 52, 67, 85};
		merge3SortedArrays(a,b,c);
		

	}

}
