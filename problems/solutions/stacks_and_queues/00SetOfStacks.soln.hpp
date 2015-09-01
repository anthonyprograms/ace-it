#include <stack>
#include <vector>
#include <iostream>

template <class T>
class SetOfStacks
{
    public:
        // default constructor for SetOfStacks
        SetOfStacks();
        // constructor with limit option
        SetOfStacks(int limit);
        // pushes the item on top of the current active stack
        void push(T item);
        // pops the top item of the current active stack
        void pop();
        // pops the top item of the specified stack
        void popAt(int i);
        // returns the top of the current active stack
        T top();
        // returns true if set of stacks is empty, false otherwise
        bool empty();
        // returns the amount of items in set of stacks
        int size();
        // returns amount of stacks in set of stacks
        int stack_count();
    private:
        // set of stacks
        std::vector< std::stack<T> > stacks;
        // count of items in set of stacks 
        int count;
        // current active stack in set of stacks
        int index;
        // limit before another stack is created
        int limit;
};

template <class T>
SetOfStacks<T>::SetOfStacks()
{
    stacks = std::vector< std::stack<T> >();
    count = 0;
    index = 0;
    limit = 10;
}

template <class T>
SetOfStacks<T>::SetOfStacks(int limit)
{
    stacks = std::vector< std::stack<T> >();
    stacks.push_back(std::stack<T>());
    count = 0;
    index = 0;
    this->limit = limit;
}

template <class T>
void SetOfStacks<T>::push(T item)
{
    if ( stacks.empty() )
        stacks.push_back(std::stack<T>());

    if ( stacks[index].size() == limit )
    {
        stacks.push(std::stack<T>());
        index++;
    }
    stacks[index].push(item);
    count++;
}

template <class T>
void SetOfStacks<T>::pop()
{
    if ( stacks.empty() )
        return;

    stacks[index].pop();
    if ( stacks[index].empty() )
    {
        stacks.pop_back();
        index--;
    }
    count--;
}

template <class T>
void SetOfStacks<T>::popAt(int i)
{
    if ( stacks.empty() || i >= index )
        return;

    stacks[i].pop();
    if ( stacks[i].empty() )
    {
        stacks.erase(i);
        index--;
    }
    count--;
}

template <class T>
T SetOfStacks<T>::top()
{
    try
    {
        if ( stacks.empty() )
            throw;
    }
    catch (int e)
    {
        std::cout << "Stack is empty!";
    }
    return stacks[index].top();
}

template <class T>
bool SetOfStacks<T>::empty()
{
    return count == 0;
}

template <class T>
int SetOfStacks<T>::size()
{
    return count;
}

template <class T>
int SetOfStacks<T>::stack_count()
{
    return stacks.size();
}
