#include<iostream>
using namespace std;


class buildHeap {
	int *arr;
	int size;
	int capacity;
public:
	buildHeap(int x)
	{
		capacity = x;
		size = x;
		arr = new int[x];
	}
	int parent(int i)
	{
		return (i - 1) / 2;
	}
	int left(int i)
	{
		return 2 * i + 1;
	}
	int right(int i)
	{
		return 2 * i + 2;
	}

	void inputArr(int x)
	{
		for (int i = 0; i < x; i++)
		{
			cin >> arr[i];
		}
	}

	void minHeapify(int i)
	{
		int smallest = i;
		int lt = left(i);
		int rt = right(i);
		if (lt < size && arr[lt] < arr[i])
		{
			smallest = lt;
		}
		if (rt < size && arr[rt] < arr[smallest])
		{
			smallest = rt;
		}
		if (smallest != i)
		{
			swap(arr[smallest], arr[i]);
			minHeapify(smallest);
		}

	}

	void constructHeap()
	{
		for (int i = size - 2 / 2; i >= 0; i--)
		{
			minHeapify(i);
		}
	}

	void printArr()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
	}

};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	buildHeap heap(5);
	heap.inputArr(5);
	heap.constructHeap();
	heap.printArr();
	return 0;
}