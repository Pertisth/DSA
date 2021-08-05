#include<bits/stdc++.h>
using namespace std;

void firstCircularTour(vector<int>&petrol, vector<int>&dist)
{
	deque<int>dq;
	int curr_petrol = 0;
	int curr_idx = 0;
	int counter = 0;
	bool flag = true;
	while (dq.size() != petrol.size() && counter<=petrol.size())
	{
	    counter++;
		curr_idx = (curr_idx + 1) % petrol.size();
		dq.push_back(curr_idx);
		curr_petrol = curr_petrol + (petrol[curr_idx] - dist[curr_idx]);
		while (curr_petrol < 0)
		{
		    if(counter == petrol.size())
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


int main()
{

	vector<int>petrol {50,10,60,100};
	vector<int>dist{30,20,100,10};
	firstCircularTour(petrol, dist);
	return 0;
}
