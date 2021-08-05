#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache {

	class Node {
	public:
		Node *next;
		Node *prev;
		int key;
		int value;
		Node(int _key, int _val)
		{
			key = _key;
			value = _val;
		}
	};

	Node *head = new Node(-1, -1);
	Node *tail = new Node(-1, -1);

	int cap;
	unordered_map<int, Node*>map;
public:
	LRUCache(int x)
	{
		cap = x;
		head->next = tail;
		tail->prev = head;
	}

	void addNode(Node *newNode)
	{
		newNode->next = head->next;
		newNode->prev = head;
		newNode->next->prev = newNode;
		head->next = newNode;
	}
	void deleteNode(Node *node)
	{
		Node *delPrev = node->prev;
		Node *delNext = node->next;
		delPrev->next = delNext;
		delNext->prev = delPrev;
	}


	int get(int key)
	{
		if (map.find(key) != map.end())
		{
			Node *curr = map[key];
			int res = curr->value;
			map.erase(key);
			deleteNode(curr);
			addNode(curr);
			map[key] = head->next;
			return res;
		}
		return -1;
	}

	void put(int key, int value)
	{
		if (map.find(key) != map.end())
		{
			Node *curr = map[key];
			map.erase(key);
			deleteNode(curr);
		}
		if (map.size() == cap)
		{
			map.erase(tail->prev->key);
			deleteNode(tail->prev);
		}
		Node *newNode = new Node(key, value);
		addNode(newNode);
		map[key] = head->next;
	}

	// not necessary, just created to check the order of nodes;
	int checkTail()
	{
		return tail->prev->value;
	}
	int checkHead()
	{
		return head->next->value;
	}

};


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	LRUCache lru(3);
	lru.put(1, 3);
	lru.put(2, 10);
	lru.put(3, 20);
	lru.put(4, 50);
	cout << lru.get(3) << endl;
	// cout << lru.checkHead();
	return 0;
}