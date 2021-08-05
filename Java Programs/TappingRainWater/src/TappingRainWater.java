
public class TappingRainWater {
	
	static int max(int a,int b)
	{
		if(a>b)
			return a;
		else
			return b;
	}
	static int min(int a,int b)
	{
		if(a<b)
			return a;
		else
			return b;
	}
	
	static int maxRainWaterNaive(int[] arr)
	{
		int n = arr.length;
		int res = 0;
		for(int i=1;i<n-1;i++)
		{
			int lmax = arr[i];
			for(int j=0;j<i;j++)
			{
				lmax = max(lmax,arr[j]);
			}
			int rmax = arr[i];
			for(int j=i+1;j<n;j++)
			{
				rmax = max(rmax,arr[j]);
			}
			res = res + min(lmax,rmax)-arr[i];
		}
		return res;
	}
	
	static int maxRainWaterEfficient(int[] arr)
	{
		int n = arr.length;
		int[] lmax = new int[n];
		int[] rmax = new int[n];
		int res = 0;
		lmax[0]=arr[0];
		for(int i=1;i<n;i++)
		{
			lmax[i]=max(arr[i],lmax[i-1]);
		}
		rmax[n-1]=arr[n-1];
		for(int i=n-2;i>=0;i--)
		{
			rmax[i]=max(arr[i],rmax[i+1]);
		}
		for(int i=0;i<n;i++)
		{
			res = res + min(lmax[i],rmax[i])-arr[i];
		}
		return res;
	}

	public static void main(String[] args) {
		
		int[] arr = {5,0,6,2,3};
		int a = maxRainWaterEfficient(arr);
		System.out.println(a);
		

	}

}
