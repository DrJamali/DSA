#include <iostream>
#include <stack>
#include <string>
using namespace std;
int precedence(char x)
{
    if (x == '^')
    {
        return 3;
    }
    else if (x == '/' || x == '*')
    {
        return 2;
    }
    else if (x == '+' || x == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
void solve_paranthesis(string s)
{
    stack<char> st;
    string res;
    for (int i = 0; i < s.size(); i++)
    {
        char current = s[i];

        if (current >= 'a' && current <= 'z')
        {
            res.push_back(current);
        }
        else if (current == '(')
        {
            st.push(current);
        }
        else if (current == ')')
        {
            while (st.top() != '(')
            {
                res.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else if (!st.empty())
        {
            if (precedence(current) > precedence(st.top()))
            {
                st.push(current);
            }
            else if (precedence(current) <= precedence(st.top()))
            {
                while (!st.empty() && precedence(current) <= precedence(st.top()) && st.top() != '(')
                {
                    res.push_back(st.top());
                    st.pop();
                }
                st.push(current);
            }
        }
        else
        {
            st.push(current);
        }
    }
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    cout << "Result: " << res << endl;
}
int main()
{
    string s = "(a+b)*(c-d)/e^f";
    solve_paranthesis(s);
}