
public class LongestOddEvenSubArray {
	
	
	static int maxEvenOddNaive(int[] arr) {
		int curr;
		int res = 0;
		for(int i=0;i<arr.length;i++)
		{
			curr=1;
			for(int j=i+1;j<arr.length;j++)
			{
				if((arr[j]%2==0 && arr[j-1]%2!=0) || (arr[j]%2!=0 && arr[j-1]%2==0)) {
					curr++;
				}
				else {
					break;
				}
			}
			res = Math.max(curr, res);
		}
		return res;
	}
	
	
	static int maxEvenOddEfficient(int[] arr)
	{
		int res = 0;
		int curr = 0;
		for(int i=1;i<arr.length;i++)
		{
			if((arr[i]%2==0 && arr[i-1]%2!=0) ||(arr[i]%2!=0 && arr[i-1]%2==0) ) {
				curr++;
				res = Math.max(curr, res);
			}
			else {
				curr = 1;
			}
		}
		return res;
		
	}

	
	public static void main(String[] args) {
		
		int[] arr = {5,10,20,6,3,8};
		int res = maxEvenOddNaive(arr);
		System.out.println(res);

	}

}
