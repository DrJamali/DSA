#include <iostream>
#include <stack>
#include <string>
using namespace std;
// {}
// []
// ()
// ^
// / *
// +
// -
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

bool is_valid(string s) {
    stack<char> st;
    bool last_was_operator = false;  // To track if the last character was an operator
    
    for (int i = 0; i < s.length(); i++) {
        char current_char = s[i];
        
        // Handle operands (a-z)
        if (current_char >= 'a' && current_char <= 'z') {
            // Ensure no two consecutive operands exist
            if (!st.empty() && st.top() >= 'a' && st.top() <= 'z') {
                return false;  // Two operands are adjacent
            }
            st.push(current_char);
            last_was_operator = false;  // Set operator flag to false as we just saw an operand
        }
        // Handle opening brackets
        else if (current_char == '{' || current_char == '[' || current_char == '(') {
            st.push(current_char);
            last_was_operator = false;  // Opening bracket is not an operator
        }
        // Handle closing brackets
        else if (current_char == '}' || current_char == ']' || current_char == ')') {
            if (st.empty()) return false;  // No matching opening bracket

            // Check if top of the stack matches the current closing bracket
            if ((current_char == '}' && st.top() != '{') ||
                (current_char == ']' && st.top() != '[') ||
                (current_char == ')' && st.top() != '(')) {
                return false;  // Mismatched brackets
            }
            st.pop();  // Pop the matching opening bracket
            last_was_operator = false;  // A closing bracket isn't an operator
        }
        // Handle operators
        else if (current_char == '+' || current_char == '-' || current_char == '/' || current_char == '*' || current_char == '^' || current_char == '%') {
            if (last_was_operator) {
                return false;  // Two operators cannot be consecutive
            }
            if (st.empty() || !(st.top() >= 'a' && st.top() <= 'z')) {
                return false;  // Operator cannot be at the start or follow another operator
            }
            last_was_operator = true;  // Mark that we just saw an operator
        }
        // Ignore spaces or other non-relevant characters (if needed)
    }

    // Check for any unmatched opening brackets remaining in the stack
    while (!st.empty()) {
        char top = st.top();
        if (top == '{' || top == '[' || top == '(') {
            return false;  // Unmatched opening bracket
        }
        st.pop();
    }

    return true;
}

void convert_to_postfix(string x)
{
    stack<char> stack;
    string res;
    
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] >= 'a' && x[i] <= 'z')
        {
            res.push_back(x[i]) ;
            
        }
        else
        {
            if (!stack.empty())
            {
                if (precedence(x[i]) > precedence(stack.top()))
                {
                    stack.push(x[i]);
                    cout<<"Stack top"<<stack.top()<<endl;
                }
                else if (precedence(x[i]) <= precedence(stack.top()))
                {

                        
                    while (!stack.empty() && (precedence(stack.top()) >= precedence(x[i])))
                    {
                        cout<<"Mein aaya idher"<<endl;
                        res.push_back(stack.top());
                        stack.pop();
                    }
                    stack.push(x[i]);
                }
            }
            else
            {
                stack.push(x[i]);
                cout<<"Stack top if empty"<<stack.top()<<endl;
            }
        }
    }
    while (!stack.empty())
    {
        res.push_back(stack.top());
        stack.pop();
    }
    
    
    cout<<"Postfix  :"<<res<<endl;

}
int main()
{

    string s = "a*b*(c-q)/y^z";
    convert_to_postfix(s);
    
    
}
