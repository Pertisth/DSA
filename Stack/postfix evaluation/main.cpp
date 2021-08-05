#include <iostream>
#include<stack>
#include <math.h>

using namespace std;

bool isOperand(char ch)
{
    return (ch >= '0' && ch <= '9');
}

int postfixEvaluation(string str)
{
    stack<int>st;
    for(int i=0;i<str.length();i++)
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
                    st.push(num1 + num2);
                    break;
                case '-':
                    st.push(num2 - num1);
                    break;
                case '*':
                    st.push(num1 * num2);
                    break;
                case '/':
                    st.push(num2 / num1);
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
    cin >> str;
    cout << postfixEvaluation(str);
    return 0;
}
