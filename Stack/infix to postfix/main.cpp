#include <bits/stdc++.h>

using namespace std;



//infiix to postfix
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

bool isOperand(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

bool isOperator(char ch)
{
    if (ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch == '-')
        return true;
    else
        return false;
}

string infixToPostfix(string str)
{
    stack<char>st;
    string postfix = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (isOperand(str[i]))
        {
            postfix = postfix + str[i];
        }
        else if (str[i] == '(')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix = postfix + st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(str[i]))
        {
            if (st.empty())
            {
                st.push(str[i]);
            }
            else
            {
                if ((precedence(str[i])) > precedence(st.top()))
                {
                    st.push(str[i]);
                }
                else
                {
                    while (!st.empty() && precedence(str[i]) <= precedence(st.top()))
                    {
                        postfix = postfix + st.top();
                        st.pop();
                    }
                    st.push(str[i]);
                }
            }
        }

    }
    while (!st.empty())
    {
        postfix = postfix + st.top();
        st.pop();
    }
    return postfix;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string str;
    cin >> str;
    cout << infixToPostfix(str);
    return 0;
}
