class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;

    MinStack()
    {
    }

    void push(int value)
    {
        mainStack.push(value);

        if(minStack.empty())
        {
            minStack.push(value);
        }
        else
        {
            int currentMin = min(value, minStack.top());
            minStack.push(currentMin);
        }
    }

    void pop()
    {
        mainStack.pop();
        minStack.pop();
    }

    int top()
    {
        return mainStack.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};