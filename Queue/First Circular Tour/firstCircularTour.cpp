#include<bits/stdc++.h>
using namespace std;

void firstCircularTour(vector<int>&petrol, vector<int>&dist)  // T.C - O(N) &&  S.C - O(N)
{
	deque<int>dq;
	int curr_petrol = 0;
	int curr_idx = 0;
	int counter = 0;
	bool flag = true;
	while (dq.size() != petrol.size() && counter <= petrol.size())
	{
		counter++;
		curr_idx = (curr_idx + 1) % petrol.size();
		dq.push_back(curr_idx);
		curr_petrol = curr_petrol + (petrol[curr_idx] - dist[curr_idx]);
		while (curr_petrol < 0)
		{
			if (counter == petrol.size() || dq.front() == petrol.size() - 1)
			{
				flag = false;
				break;
			}
			int idx = dq.front();
			dq.pop_front();
			curr_petrol = curr_petrol - (petrol[idx] - dist[idx]);
			counter--;
		}

	}
	if (flag)
	{
		cout << "Start at Position: " << dq.front() + 1 << endl;
	}
	else
	{
		cout << "-1" << endl;
	}

}


void firstCircularTourEfficient(vector<int>&petrol, vector<int>&dist)
{
	int prev_petrol = 0;
	int curr_petrol = 0;
	int start = 0;
	for (int i = 0; i < petrol.size(); i++)
	{
		curr_petrol = curr_petrol + (petrol[i] - dist[i]);
		if (curr_petrol < 0)
		{
			start = i + 1;
			prev_petrol = curr_petrol;
			curr_petrol = 0;
		}
	}
	if (curr_petrol + prev_petrol >= 0)
	{
		cout << start + 1 << endl;
	}
	else
	{
		cout << "-1" << endl;
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>petrol {4, 8, 7, 4};
	vector<int>dist{6, 5, 3, 5};
	firstCircularTourEfficient(petrol, dist);
	return 0;
}
