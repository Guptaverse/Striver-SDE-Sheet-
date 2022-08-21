// sort stack using recursion (IMP Concept**)

// TC : O(N*N) , SC : O(N)


void helper(stack<int> &stack , int x){
    if(stack.empty() || x>stack.top()){
        stack.push(x);
        return;
    }
    
    // if stack.top() is greater , remove the top item 
    int temp = stack.top();
    stack.pop();
    helper(stack,x);
    // put back the top item that was removed earlier
    stack.push(temp);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
    if(!stack.empty()){
        int temp = stack.top();
        stack.pop();
        sortStack(stack);
        helper(stack,temp);
    }
    
}