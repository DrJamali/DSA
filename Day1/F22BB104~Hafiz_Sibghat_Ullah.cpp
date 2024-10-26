#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char x) {
    if (x == '^') {
        return 3;
    } else if (x == '/' || x == '*' || x == '%') {
        return 2;
    } else if (x == '+' || x == '-') {
        return 1;
    } else {
        return -1;
    }
}

bool is_valid(string s) {
    stack<char> st;
    bool last_was_operator = true;
    bool last_was_operand = false;
    int square_count = 0, curly_count = 0, paren_count = 0;

    for (int i = 0; i < s.length(); i++) {
        char current_char = s[i];

        if ((current_char >= 'a' && current_char <= 'z') || (current_char >= '0' && current_char <= '9')) {
            if (last_was_operand) {
                return false;
            }
            last_was_operator = false; 
            last_was_operand = true;  
        } else if (current_char == '[') {
            if (curly_count > 0 || paren_count > 0) return false;
            st.push(current_char);
            square_count++;
            last_was_operator = false;
            last_was_operand = false;
        } else if (current_char == '{') {
            if (square_count == 0 || paren_count > 0) return false;
            st.push(current_char);
            curly_count++;
            last_was_operator = false;
            last_was_operand = false;
        } else if (current_char == '(') {
            if (square_count == 0 || curly_count == 0) return false;
            st.push(current_char);
            paren_count++;
            last_was_operator = false;
            last_was_operand = false;
        } else if (current_char == ']') {
            if (st.empty() || st.top() != '[') return false;
            st.pop();
            square_count--;
            last_was_operator = false;
            last_was_operand = false;
        } else if (current_char == '}') {
            if (st.empty() || st.top() != '{') return false;
            st.pop();
            curly_count--;
            last_was_operator = false;
            last_was_operand = false;
        } else if (current_char == ')') {
            if (st.empty() || st.top() != '(') return false;
            st.pop();
            paren_count--;
            last_was_operator = false;
            last_was_operand = false;
        } else if (current_char == '+' || current_char == '-' || current_char == '/' || 
                   current_char == '*' || current_char == '^' || current_char == '%') {
            if (last_was_operator) {
                return false;
            }
            last_was_operator = true;  
            last_was_operand = false;
        } else if (current_char == ' ') {
            continue;
        } else {
            return false;
        }
    }

    if (square_count != 0 || curly_count != 0 || paren_count != 0) {
        return false;
    }

    return !last_was_operator;
}



string convert_to_postfix(string s) {
    stack<char> st;
    string res;
    for (int i = 0; i < s.length(); i++) {
        char curr_char = s[i];
        if(curr_char == ' '){
            continue;
        }
        if ((curr_char >= 'a' && curr_char <= 'z') || (curr_char >= '0' && curr_char <= '9')) {
            res.push_back(curr_char);
        } else if (curr_char == '[' || curr_char == '{' || curr_char == '(') {
            st.push(curr_char);
        } else if (!st.empty()) {
            if (curr_char == ']' || curr_char == '}' || curr_char == ')') {
                while (!st.empty() && st.top() != '[' && st.top() != '{' && st.top() != '(') {
                    res.push_back(st.top());
                    st.pop();
                }
                st.pop(); 
            } else if (precedence(curr_char) > precedence(st.top())) {
                st.push(curr_char);
            } else if (precedence(curr_char) <= precedence(st.top())) {
                while (!st.empty() && precedence(curr_char) <= precedence(st.top()) && st.top() != '[' && st.top() != '{' && st.top() != '(') {
                    res.push_back(st.top());
                    st.pop();
                }
                st.push(curr_char);
            }
        } else {
            st.push(curr_char);
        }
        cout << "Now the Postfix is : " << res << endl;
    }
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    
    return res;
}



int main() {
    string s = "a+[b*{c^d%(4/f*g)-h}]";
    if (is_valid(s)) {
        cout << "Valid Expression" << endl;
    } else {
        cout << "Invalid Expression" << endl;
    }
    convert_to_postfix(s);
    
}
