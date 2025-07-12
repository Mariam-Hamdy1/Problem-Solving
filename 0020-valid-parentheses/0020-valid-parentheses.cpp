#include <stack>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        // A stack to keep track of open brackets.
        std::stack<char> st;
        
        // A map to quickly check if a character is a closing bracket and find its corresponding open bracket.
        std::unordered_map<char, char> matching_brackets = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        for (char c : s) {
            // Check if the current character is a closing bracket.
            if (matching_brackets.count(c)) {
                // If it is a closing bracket, check if the stack is empty or if the top element 
                // of the stack is the correct matching open bracket.
                
                // Rule 3: Every close bracket must have a corresponding open bracket.
                // Rule 2: Open brackets must be closed in the correct order (top of stack must match).
                if (st.empty() || st.top() != matching_brackets[c]) {
                    return false;
                }
                
                // If it matches, pop the open bracket from the stack.
                st.pop();
            } else {
                // If it's an opening bracket, push it onto the stack.
                st.push(c);
            }
        }
        
        // After iterating through the entire string, the stack must be empty for the string to be valid.
        // If the stack is not empty, it means there are open brackets that were never closed (violates Rule 3).
        return st.empty();
    }
};