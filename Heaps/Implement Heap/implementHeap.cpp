#include<iostream>
#include<vector>
using namespace std;

class minHeap {
	int size;
	int cap;
	int *arr;
public:
	minHeap(int x)
	{
		this->cap = x;
		this->size = 0;
		arr = new int[cap];
	}
	int left(int i)
	{
		return arr[2 * i + 1];
	}
	int right(int i)
	{
		return 2 * i + 2;
	}
	int parent(int i)
	{
		return ((i - 1) >> 1);
	}


	void insert(int x)
	{
		if (size == cap)
		{
			return;
		}
		size++;
		arr[size - 1] = x;
		for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i];)
		{
			swap(arr[parent(i)], arr[i]);
			i = parent(i);
		}
	}

	void swapItem(int x, int y)
	{
		swap(arr[x], arr[y]);
	}

	void heapify(int i)
	{
		int lt = left(i);
		int rt = right(i);
		int smaller = i;
		if (lt < size && arr[lt] < arr[i])
		{
			smaller = lt;
		}
		if (rt < size && arr[rt] < arr[smaller])
		{
			smaller = rt;
		}
		if (smaller != i)
		{
			swap(arr[smaller], arr[i]);
			heapify(smaller);
		}
	}

	int extractMin()
	{
		if (size == 0)
		{
			return INT_MAX;
		}
		if (size == 1)
		{
			size--;
			return arr[0];
		}
		swap(arr[0], arr[size - 1]);
		size--;
		heapify(0);
		return arr[size];

	}

	void printArr()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
	}

	void decreaseKey(int i, int x)  // replace number with x at index i
	{
		arr[i] = x;
		while (i != 0 && arr[parent(i)] > arr[i])
		{
			swap(arr[parent(i)], arr[i]);
			i = parent(i);
		}
	}

	void deleteNode(int i)
	{
		int res = arr[i];
		arr[i] = INT_MIN;
		while (i != 0 && arr[parent(i)] > arr[i])
		{
			swap(arr[parent(i)], arr[i]);
			i = parent(i);
		}

		extractMin();
		cout << "DeleteNode is : " << res << endl;
	}
};





int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	minHeap heap(5);
	heap.insert(3);
	heap.insert(2);
	heap.insert(1);
	heap.insert(5);
	// cout << heap.extractMin();
	heap.insert(4);
	// cout << "\n" <<  heap.extractMin();
	// heap.decreaseKey(3, -1);
	heap.deleteNode(3);
	heap.printArr();


	return 0;
}