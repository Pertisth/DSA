import java.util.ArrayList;

public class LeadersinArray {
	
	static void printArr(ArrayList<Integer>arr) {
		int n = arr.size();
		for(int i=n-1;i>=0;i--)
		{
			System.out.println(arr.get(i));
		}
		
	}
	
	static ArrayList<Integer> LeaderInArray(int[] arr)
	{
		int n = arr.length;
		int curr_leader = arr[n-1];
		
		ArrayList<Integer>arrList = new ArrayList<Integer>();
		arrList.add(curr_leader);
		
		for(int i=n-2;i>=0;i--)
		{
			if(arr[i] > curr_leader) {
				curr_leader = arr[i];
				arrList.add(curr_leader);
			}
		}
		return arrList;
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[] arr = new int [] {7,10,4,10,6,5,2}; 
		ArrayList<Integer>arr2 = new ArrayList<Integer>();
		arr2 = LeaderInArray(arr);
		printArr(arr2);

	}

}
