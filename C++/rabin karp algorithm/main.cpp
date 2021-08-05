#include <iostream>
#define d 256

using namespace std;




void rabinKarpAlgo(string txt,string pat,int q)
{
    int n = txt.length();  // length of string
    int m = pat.length();  // length of pattern
    int h = 1;
    for(int i=0;i<m-1;i++)
    {
        h = (h*d)%q;    // h^m-1
    }

    int t = 0;
    int p = 0;
    for(int i=0;i<m;i++)
    {
        p = ((p*d)+pat[i])%q;  // hash of first window
        t = ((t*d)+txt[i])%q;  // hash of pattern
    }

    for(int i=0;i<n-m+1;i++)
    {
        if(p == t)   // if both the hash values are found
        {
            int j;
            for(j=0;j<m;j++)  // comparing the char if both hash functions are matched
            {
                if(txt[i+j] != pat[j])
                {
                    break;
                }
            }
            if(j == m)  // if loop traversed completely that means no non-match text was found so we return the index
            {
                cout << "Pattern Found at << " << i <<endl;
            }
        }
        if(i<n-m) // calculating the next window hash value;
        {
            t = ((t-txt[i]*h)*d + txt[i+m])%q;

            if(t<0)   // checking if hash of txt window is negative ,if negative then we add with q
            {
                t = t+q;
            }
        }

    }

}


int main()
{
    string text = "pertisth";
    string pat = "rti";

    int primeNumber = 101;

    rabinKarpAlgo(text,pat,primeNumber);

    return 0;
}
