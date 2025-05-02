
// 020525
/*
    POTD_CN_e :  Insert An Element At Bottom of the Given Stack.
    Given a stack 'myStack' and an integer 'X'.
    Task is to insert 'X' at the bottom of 'myStack' and return the updated version.

    Try to do this without using any other data structure.

*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to recursively pop and push the element to the bottom of the stack.
void recursiveStacking(stack<int>& stk, int x)
{
    if(stk.empty()) {
        stk.push(x);
        return;
    }

    int top = stk.top();
    stk.pop();
    recursiveStacking(stk, x);
    stk.push(top);
}

// Calling function which will initiate the recursion.
stack<int> pushAtBottom(stack<int> myStack, int x)
{
    recursiveStacking(myStack, x);
    return myStack;
}

int main(void)
{
    int n;
    // cout << "Enter stack size : ";
    cin >> n;

    // cout << "Enter the " << n << " stack elements : ";
    stack<int> myStack;
    int temp;
    for(int i=0; i<n; i++) {
        cin >> temp;
        myStack.push(temp);
    }

    int x;
    // cout << "Enter the integer to insert : ";
    cin >> x;
    myStack = pushAtBottom(myStack, x);
    
    
    int stkSize = myStack.size();
    vector<int> displayVector (stkSize);

    cout << "Final Stack = \n";
    while(stkSize>0) {
        // cout << myStack.top() << " ";
        displayVector[stkSize-1] = myStack.top();
        myStack.pop();
        stkSize--;
    }

    for(int ele : displayVector) {
        cout << ele << " ";
    }
    cout << "\n";
    return 0;
}
