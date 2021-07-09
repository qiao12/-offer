#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
using namespace std;

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}

class Solution {
public:
    void push(int value) {
        if ( !min_stack.empty())
        {
            if (value >= min_stack.top())
            {
                stack.push(value);
                min_stack.push(min_stack.top());
            }
            else
            {
                min_stack.push(value);
                stack.push(value);
            }
        }
        else
        {
            min_stack.push(value);
            stack.push(value);
        }

    }
    void pop() {
        stack.pop();
        min_stack.pop();

    }
    int top() {
        return stack.top();
    }
    int min() {
        return min_stack.top();
    }
private:
    stack<int> min_stack;
    stack<int> stack;
};

