#include <iostream>

using namespace std;


string buildLPS(string str)
{
    int n=str.length();
    int arr[n];
    arr[0]=0;
    string prefixL[n];
    prefixL[0]="";
    string suffix[n];
    suffix[n-1]=str[n-1];
    for(int i=1;i<n;i++)
    {
        prefixL[i] = prefixL[i-1] + str[i-1];
    }
    for(int i=1;i<n;i++)
    {
        cout << prefixL[i] << " ";
    }
    int j=1;
    for(int i=n-2;i>=0;i--)
    {
        suffix[j]=suffix[j-1]+str[i];
        j++;
    }
    for(int i=0;i<n;i++)
    {
        cout << suffix[i] << " ";
    }
    return "Pertisth";
}

int main()
{
    string str;
    cin >> str;

    string result = buildLPS(str);

    return 0;
}
