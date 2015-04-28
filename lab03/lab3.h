///
//  Eric Aguirre
//  861174273
//  4/28/15
//  Make each function and test it one at a time.
//  Fixed and FLex are interchangable with only difference being the stop point.
//  For towers think of problems you can do easily then recursively call until
//  you can do the problem
///
#ifndef LAB3_H
#define LAB3_H

#include <iostream>
#include <cassert>
#include <stack>

using namespace std;

template <typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{
    //save addresses of originals
    const static stack<T> *start = &A;
    const static stack<T> *aux = &B;
    const static stack<T> *dest = &C;
    if (n <= 0)
    {
        return;
    }
    else if (n == 1)
    {
        C.push(A.top());
        cout << "Moved " << A.top() << " from peg A to C" << endl;
        A.pop();
        return;
    }
    else if (n == 2)
    {
        B.push(A.top());
        cout << "Moved " << A.top() << " from peg A to B" << endl;
        A.pop();
        C.push(A.top());
        cout << "Moved " << A.top() << " from peg A to C" << endl;
        A.pop();
        C.push(B.top());
        cout << "Moved " << B.top() << " from peg B to C" << endl;
        B.pop();
        return;
    }
    else if (n == 3) // algorithm for 3 used for n > 3
    {
        C.push(A.top());
        cout << "Moved " << A.top() << " from peg ";
        if (&A == start) cout << "A"; //check to original address
        else if (&A == aux) cout << "B";
        else if (&A == dest) cout << "C";
        cout << " to ";
        if (&C == start) cout << "A";
        else if (&C == aux) cout << "B";
        else if (&C == dest) cout << "C";
        cout << endl;
        A.pop();
        B.push(A.top());
        cout << "Moved " << A.top() << " from peg ";
        if (&A == start) cout << "A";
        else if (&A == aux) cout << "B";
        else if (&A == dest) cout << "C";
        cout << " to ";
        if (&B == start) cout << "A";
        else if (&B == aux) cout << "B";
        else if (&B == dest) cout << "C";
        cout << endl;
        A.pop();
        B.push(C.top());
        cout << "Moved " << C.top() << " from peg ";
        if (&C == start) cout << "A";
        else if (&C == aux) cout << "B";
        else if (&C == dest) cout << "C";
        cout << " to ";
        if (&B == start) cout << "A";
        else if (&B == aux) cout << "B";
        else if (&B == dest) cout << "C";
        cout << endl;
        C.pop();
        C.push(A.top());
        cout << "Moved " << A.top() << " from peg ";
        if (&A == start) cout << "A";
        else if (&A == aux) cout << "B";
        else if (&A == dest) cout << "C";
        cout << " to ";
        if (&C == start) cout << "A";
        else if (&C == aux) cout << "B";
        else if (&C == dest) cout << "C";
        cout << endl;
        A.pop();
        A.push(B.top());
        cout << "Moved " << B.top() << " from peg ";
        if (&B == start) cout << "A";
        else if (&B == aux) cout << "B";
        else if (&B == dest) cout << "C";
        cout << " to ";
        if (&A == start) cout << "A";
        else if (&A == aux) cout << "B";
        else if (&A == dest) cout << "C";
        cout << endl;
        B.pop();
        C.push(B.top());
        cout << "Moved " << B.top() << " from peg ";
        if (&B == start) cout << "A";
        else if (&B == aux) cout << "B";
        else if (&B == dest) cout << "C";
        cout << " to ";
        if (&C == start) cout << "A";
        else if (&C == aux) cout << "B";
        else if (&C == dest) cout << "C";
        cout << endl;
        B.pop();
        C.push(A.top());
        cout << "Moved " << A.top() << " from peg ";
        if (&A == start) cout << "A";
        else if (&A == aux) cout << "B";
        else if (&A == dest) cout << "C";
        cout << " to ";
        if (&C == start) cout << "A";
        else if (&C == aux) cout << "B";
        else if (&C == dest) cout << "C";
        cout << endl;
        A.pop();
        return;
    }
    else
    {
        //look at one less than n if possible to do
        //Solve for them with aux being destination
        //Move last in A to final destination
        //move everything on aux to final destination
        showTowerStates(n - 1, A, C, B);
        C.push(A.top());
        cout << "Moved " << A.top() << " from peg ";
        if (&A == start) cout << "A";
        else if (&A == aux) cout << "B";
        else if (&A == dest) cout << "C";
        cout << " to ";
        if (&C == start) cout << "A";
        else if (&C == aux) cout << "B";
        else if (&C == dest) cout << "C";
        cout << endl;
        A.pop();
        --n;
        showTowerStates(n, B, A, C);
    }
    return;
}

//helper function for tower
template <typename T>
void TowerDisplay(stack<T> A, stack<T> B, stack<T> C)
{
    if (A.empty()) cout << "Empty" << endl;
    else
    {
        while (!A.empty())
        {
            cout << A.top() << " ";
            A.pop();
        }
    }
    if (B.empty()) cout << "Empty" << endl;
    else
    {
        while (!B.empty())
        {
            cout << B.top() << " ";
            B.pop();
        }
    }
    if (C.empty()) cout << "Empty" << endl;
    else
    {
        while (!C.empty())
        {
            cout << C.top() << " ";
            C.pop();
        }
    }
    cout << endl;
    return;
}

template <class T>
class TwoStackFixed
{
    private:
        T *arr;
        int sz;
        int mxtop;
        int top1; //pos of top of stack1
        int top2; //pos of top of stack2
    public:
        TwoStackFixed(int size, int maxtop)
        {
            // constructor that constructs array of ‘size’ length
            // and constructs empty stacks with maxtop specifying the partition of array for stacks.
            assert(maxtop < size);
            sz = size;
            mxtop = maxtop;
            arr = new T[size];
            for (int i = 0; i < size; ++i)
            {
                arr[i] = '\0'; //initialize to empty set
            }
            top1 = -1;
            top2 = size;
        }
        void pushStack1(T value)
        {
            // to push element into first stack. Display the contents of stack
            // after each push.
            if (!isFullStack1())
            {
                ++top1;
                arr[top1] = value;
                display();
            }
            else
            {
                cout << "Error: End of stack reached" << endl;
                exit(1);
            }
            return;
        }
        void pushStack2(T value)
        {
            // to push element into second stack. Display the contents of
            // stack after each push.
            if (!isFullStack2())
            {
                --top2;
                arr[top2] = value;
                display();
            }
            else
            {
                cout << "Error: End of stack reached" << endl;
                exit(1);
            }
            return;
        }
        T popStack1()
        {
            // to pop element from first stack. Return the popped element and print.
            if (!isEmptyStack1())
            {
                T removed = arr[top1];
                arr[top1] = '\0'; //set back to null to remove value
                --top1;
                return removed;
            }
            else
            {
                cout << "Error: Stack empty" << endl;
                exit(1);
            }
        }
        T popStack2()
        {
            // to pop element from second stack. Return the popped element and
            // print.
            if (!isEmptyStack2())
            {
                T removed = arr[top2];
                arr[top2] = '\0'; //set back to null to remove value
                ++top2;
                return removed;
            }
            else
            {
                cout << "Error: Stack empty" << endl;
                exit(1);
            }
        }
        bool isFullStack1()
        {
            // helper function to check whether first stack is full.
            return (top1 == mxtop - 1) ? true : false; //stack 2 takes mxtop
        }
        bool isFullStack2()
        {
            // helper function to check whether second stack is full.
            return (top2 == mxtop) ? true : false;
        }
        bool isEmptyStack1()
        {
            // helper function to check whether first stack is empty.
            return (top1 == -1) ? true : false;
        }
        bool isEmptyStack2()
        {
            // helper function to check whether second stack is empty.
            return (top2 == sz) ? true : false;
        }
        void display()
        {
            if (sz == 0)
            {
                cout << "Nothing to display." << endl;
                return;
            }
            // to display contents of array.
            for (int i = 0; i < sz; ++i)
            {
                if (arr[i] != '\0') // empty set is a space
                {
                    cout << arr[i] << " ";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
            return;
        }
};

// Only going to be difference in check if full
template <class T>
class TwoStackOptimal
{
    private:
        T *arr;
        int sz;
        int top1;
        int top2;
    public:
        TwoStackOptimal(int size)
        {
            // constructor that constructs array of size and constructs empty
            // stacks.
            sz = size;
            arr = new T[size];
            for (int i = 0; i < size; ++i)
            {
                arr[i] = '\0';
            }
            top1 = -1;
            top2 = size;
        }
        void pushFlexStack1(T value)
        {
            // to push element into first stack. Display the contents of stack
            // after each push.
            if (!isFullStack1())
            {
                ++top1;
                arr[top1] = value;
                display();
            }
            else
            {
                cout << "Error: End of stack reached" << endl;
                exit(1);
            }
            return;
        }
        void pushFlexStack2(T value)
        {
            // to push element into second stack. Display the contents of
            // stack after each push.
            if (!isFullStack2())
            {
                --top2;
                arr[top2] = value;
                display();
            }
            else
            {
                cout << "Error: End of stack reached" << endl;
                exit(1);
            }
            return;
        }
        T popFlexStack1()
        {
            // to pop element into first stack. Return the popped element and print.
            if (!isEmptyStack1())
            {
                T removed = arr[top1];
                arr[top1] = '\0';
                --top1;
                return removed;
            }
            else
            {
                cout << "Error: Stack empty" << endl;
                exit(1);
            }
        }
        T popFlexStack2()
        {
            // to pop element from second stack. Return the popped element and
            // print.
            if (!isEmptyStack2())
            {
                T removed = arr[top2];
                arr[top2] = '\0';
                ++top2;
                return removed;
            }
            else
            {
                cout << "Error: Stack empty" << endl;
                exit(1);
            }
        }
        bool isFullStack1()
        {
            // helper function to check whether first stack is full.
            return (top1 == top2 - 1) ? true : false; //only difference
        }
        bool isFullStack2()
        {
            // helper function to check whether second stack is full.
            return (top2 == top1 + 1) ? true : false; //only difference
        }
        bool isEmptyStack1()
        {
            // helper function to check whether first stack is empty.
            return (top1 == -1) ? true : false;
        }
        bool isEmptyStack2()
        {
            // helper function to check whether second stack is empty.
            return (top2 == sz) ? true : false;
        }
        void display()
        {
            // to display contents of array.
            if (sz == 0)
            {
                cout << "Nothing to display." << endl;
                return;
            }
            // to display contents of array.
            for (int i = 0; i < sz; ++i)
            {
                if (arr[i] != '\0')
                {
                    cout << arr[i] << " ";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
            return;
        }
        
};
#endif