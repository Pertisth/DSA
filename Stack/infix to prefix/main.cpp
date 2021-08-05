#include <iostream>
#include <stack>

using namespace std;

int precedence(char ch)
{
    if(ch == '^')
        return 4;
    else if(ch == '*' || ch == '/')
        return 3;
    else if(ch == '+' || ch == '-')
        return 2;
    else if(ch == '(' || ch == ')')
        return 1;
    else
        return 0;
}

string reverseString(string str)
{
    int i=0;
    int j=str.length()-1;
    while(i<=j)
    {
        swap(str[i],str[j]);
        i++;
        j--;
    }
    return str;
}

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
bool isOperand(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch>='A' && ch<='Z'));
}


string infixToPrefix(string str)
{
    string prefix = "";
    stack<char>st;
    for(int i=str.length()-1;i>=0;i--)
    {
        if(isOperand(str[i]))
        {
            prefix = prefix + str[i];
        }
        else if(str[i] == ')')
        {
            st.push(str[i]);
        }
        else if(str[i] == '(')
        {
            while(!st.empty() && st.top()!=')')
            {
                prefix = prefix + st.top();
                st.pop();
            }
            st.pop();
        }
        else if(isOperator(str[i]))
        {
            if(st.empty())
            {
                st.push(str[i]);
            }
            else
            {
                if(precedence(str[i]) > precedence(st.top()))
                {
                    st.push(str[i]);
                }
                else if(precedence(str[i]) == precedence(st.top()))
                {
                    st.push(str[i]);
                }
                else
                {
                    while(!st.empty() && precedence(st.top()) > precedence(str[i]))
                    {
                        prefix = prefix + st.top();
                        st.pop();
                    }
                    st.push(str[i]);
                }
            }
        }
    }
    while(!st.empty())
    {
        prefix = prefix + st.top();
        st.pop();
    }
    prefix = reverseString(prefix);
    return prefix;


}

int main()
{
    string str;
    cin >> str;
    cout << infixToPrefix(str);
    return 0;
}
