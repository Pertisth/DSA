
public class MaxSumSubArray {
	
	static int MaxSumSubArrayNaive(int[] arr)
	{
		int n = arr.length;
		int res = arr[0];
		for(int i=0;i<n;i++)
		{
			int curr = 0;
			for(int j=i;j<n;j++)
			{
				curr+=arr[j];
				res = Math.max(res, curr);
			}
		}
		return res;
	}
	
	static int MaxSumSubArrayEfficient(int[] arr) /// Time Complexity - O(n) and Space Complexity - O(n)
	{
		int n = arr.length;
		int[] maxEnding = new int[n];
		maxEnding[0]=arr[0];
		for(int i=1;i<n;i++)
		{
			maxEnding[i] = Math.max(maxEnding[i-1]+arr[i], arr[i]);
		}
		int res = Integer.MIN_VALUE;
		for(int i=0;i<n;i++)
		{
			if(maxEnding[i]>res)
			{
				res = maxEnding[i];
			}
		}
		return res;
	}
	
	static int MaxSumSubArrayEfficient1(int[] arr)  /// Time Complexity - O(n) and Space Complexity - O(1)
	{
		int n = arr.length;
		int res=0;
		int maxEnding = arr[0];
		for(int i=1;i<n;i++)
		{
			maxEnding = Math.max(maxEnding+arr[i], arr[i]);
			res = Math.max(res, maxEnding);
		}
		return res;
	}

	public static void main(String[] args) {
		
		int[] arr = {1,-2, 3, -1, 2};
		int sum = MaxSumSubArrayEfficient1(arr);
		System.out.println(sum);

	}

}
