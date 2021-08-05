#include <iostream>
#include<stack>
#include<math.h>
#include <string>
#include<algorithm>
using namespace std;

bool isOperand(char ch)
{
    return (ch>='0' && ch<='9');
}

string reverseStr(string str)
{
    int i=0;
    int j=str.length()-1;
    while(i<j)
    {
        swap(str[i],str[j]);
        i++;
        j--;
    }
    return str;
}

int prefixEvaluation(string str) // single digit
{
    stack<int>st;
    for(int i=str.length()-1;i>=0;i--)
    {
        if(isOperand(str[i]))
        {
            st.push(str[i]-'0');
        }
        else
        {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            char ch = str[i];
            switch(ch)
            {
                case '+':
                    st.push(num1+num2);
                    break;
                case '-':
                    st.push(num1-num2);
                    break;
                case '*':
                    st.push(num1*num2);
                    break;
                case '/':
                    st.push(num1/num2);
                    break;
                case '^':
                    st.push(pow(num1,num2));
                    break;

            }
        }
    }
    return st.top();
}

int prefixEvaluationMulti(string str)
{
    stack<int>st;
    for(int i=str.length()-1;i>=0;i--)
    {
        if(str[i] == ' ')
        {
            continue;
        }
        else if(isOperand(str[i]))
        {
            stack<char>number;
            string num = "";
            while(i>=0 && str[i-1]!=' ')
            {
                num = num + str[i];
                i--;
            }
            num = num + str[i];
            num = reverseStr(num);
            int strToNum = stoi(num);
            st.push(strToNum);
        }
        else
        {
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            char ch = str[i];
            switch(ch)
            {
                case '+':
                    st.push(num1+num2);
                    break;
                case '-':
                    st.push(num1-num2);
                    break;
                case '*':
                    st.push(num1*num2);
                    break;
                case '/':
                    st.push(num1/num2);
                    break;
                case '^':
                    st.push(pow(num1,num2));
                    break;

            }
        }
    }
    return st.top();
}

int main()
{
    string str;
    str = "+ 9 * 120 6"; // multi digits
    cout << prefixEvaluationMulti(str);
    return 0;
}
