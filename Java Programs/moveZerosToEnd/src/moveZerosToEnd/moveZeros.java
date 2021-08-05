package moveZerosToEnd;



public class moveZeros {
	
	static void swap(int[] arr,int a,int b)
	{
		int temp;
		temp = arr[a];
		arr[a]=arr[b];
		arr[b]=temp;
	}
	
	static void printArr(int[] arr)
	{
		for(int i=0;i<arr.length;i++)
		{
			System.out.println(arr[i]);
		}
	}
	
	
	public static void main(String[] args) {
		int[] arr = new int[] {0,0,0,10,0};
		int count = 0;
		for(int i=0;i<arr.length;i++)
		{
			if(arr[i]!=0)
			{
				swap(arr,i,count);
				count++;
			}
		}
		printArr(arr);
		
		
		 

	}

}
