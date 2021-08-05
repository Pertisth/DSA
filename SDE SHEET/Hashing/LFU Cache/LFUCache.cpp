#include<iostream>
#include<map>
using namespace std;


class Node {
public:
	int key;
	int value;
	int cnt;
	Node *next;
	Node *prev;

	Node(int x, int y)
	{
		key = x;
		value = y;
		cnt = 1;
	}
};

class List {

public:
	int size;
	Node *head;
	Node *tail;

	List()
	{
		head = new Node(-1, -1);
		tail = new Node(-1, -1);
		size = 0;
		head->next = tail;
		tail->prev = head;
	}
	void addFront(Node *curr)
	{
		Node *temp = head->next;
		head->next = curr;
		curr->prev = head;
		curr->next = temp;
		temp->prev = curr;
		size++;
	}
	void deleteNode(Node *curr)
	{
		Node *temp = tail->prev;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete(temp);
		size--;
	}
};


class LFUCache {
	map<int, Node*>keyNode;
	map<int, List*>freqHash;
	int capacity;
	int minFreq;
	int currSize;
public:
	LFUCache(int x)
	{
		capacity = x;
		minFreq = 0;
		currSize = 0;
	}

	void updateFreqhash(Node *curr)
	{

		keyNode.erase(curr->key);  // delete node from hashmap
		freqHash[curr->cnt]->deleteNode(curr); // delete node from list
		if (curr->cnt == minFreq && freqHash[curr->cnt]->size == 0) // if curr count is equal to minFreq and there are no items in the present list then the next freq will be the next minFreq
		{
			minFreq++;
		}

		List *newList = new List();  // create new list
		if (keyNode.find(curr->cnt + 1) != keyNode.end()) // if list already present at freq
		{
			newList = freqHash[curr->cnt + 1];
		}
		curr->cnt++;  // increment freq of node
		newList->addFront(curr); // add in front of the list
		freqHash[curr->cnt] = newList; //add newList in freqHash
		keyNode[curr->key] = curr; //add into the hash
	}

	int get(int key)
	{
		if (keyNode.find(key) != keyNode.end())
		{
			Node *curr = keyNode[key];
			int val = curr->value;
			updateFreqhash(curr);
			return val;
		}
		return -1;
	}

	void put(int key, int value)
	{
		if (capacity == 0)
		{
			return;
		}
		if (keyNode.find(key) != keyNode.end())
		{
			Node *curr = keyNode[key];
			curr->value = value;
			updateFreqhash(curr);
		}
		else  // key wasn't present before
		{
			if (currSize == capacity)
			{
				List *list = freqHash[minFreq];
				keyNode.erase(list->tail->prev->key);
				freqHash[minFreq]->deleteNode(list->tail->prev);
				currSize--;
			}
			currSize++;
			// key wasn't present before so the new freq of node will be 1 and will be added at freq 1
			minFreq = 1;
			List *newList = new List();
			if (freqHash.find(minFreq) != freqHash.end())
			{
				newList = freqHash[minFreq];
			}
			Node *newNode = new Node(key, value);
			newList->addFront(newNode);
			keyNode[key] = newNode;
			freqHash[minFreq] = newList;
		}
	}

};


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	LFUCache lfu(3);
	lfu.put(1, 10);
	lfu.put(2, 20);
	cout << lfu.get(2) << endl;
	lfu.put(3, 30);
	cout << lfu.get(3) << endl;


	return 0;
}