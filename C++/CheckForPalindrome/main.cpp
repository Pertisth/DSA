#include <iostream>

using namespace std;

bool checkForPalindrome(string str , int i,int j)
{
    if(i>=j)
    {
        return true;
    }
    if(str[i]!=str[j])
        return false;
    checkForPalindrome(str,i+1,j-1);
}

int main()
{
    string name;
    cout << "Enter a String : ";
    cin >> name;
    if(checkForPalindrome(name,0,name.length()-1))
        cout << "True";
    else
        cout << "False";
    return 0;
}
