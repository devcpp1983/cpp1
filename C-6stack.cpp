#include <iostream>
using namespace std;

struct Stack {
    char arr[50];
    int top;
    
public:
    Stack() {
        top = -1;
    }
    
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == 49;
    }
    void push(char c) {
        if(!isFull()) {
            arr[++top] = c;
        }   
    }
    
    char pop() {
        if(!isEmpty()) 
            return arr[top--];
        return '\0';  
    }
    
    char getTop() {
        if(!isEmpty())
            return arr[top];
        return '\0';  
    }
};

bool isMatchingPair(char open, char close) {
    if(open == '(' && close == ')') return true;
    if(open == '{' && close == '}') return true;
    if(open == '[' && close == ']') return true;
    return false;
}

int main() {
    char exp[50];
    cout << "enter expression : ";
    cin >> exp;
    
    Stack st;
    bool flag = true;
    
    for(int i = 0; exp[i] != '\0'; i++) {  // ? FIXED
        char ch = exp[i];
        
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        
        else if(ch == ')' || ch == '}' || ch == ']') {
            
            if(st.isEmpty()) {   // ? FIXED
                flag = false;
                break;
            }
            
            char top = st.pop();
            
            if(!isMatchingPair(top, ch)) {
                flag = false;
                break;
            }
        }
        
        
    }
    
    if(flag && st.isEmpty())
        cout << "well balanced";
    else
        cout << "not balanced";
        
    return 0;
}
