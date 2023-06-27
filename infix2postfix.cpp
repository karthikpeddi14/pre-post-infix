class Solution {
  public:
    void precedence(map<char,int> &order)
    {
        order['+'] = 1;
        order['-'] = 1;
        order['*'] = 2;
        order['/'] = 2;
        order['^'] = 3;
        order['('] = 0;
        order[')'] = 5;
    }
    
    string infixToPostfix(string s) {
        string ans;
        stack<pair<char,int>> operations;
        map<char,int> order;
        precedence(order);
        
        for(int i=0; i<s.size() ; i++)
        {
            if(order.find(s[i]) == order.end()) ans = ans + s[i];
            else 
            {
                if(s[i] == '(') operations.push({'(' , 0});
                else if(s[i]==')')
                {
                    while(operations.top().first!='(')
                    {
                        ans = ans + operations.top().first;
                        operations.pop();
                    }
                    operations.pop();
                }
                else
                {
                    if(operations.empty() || operations.top().second < order[s[i]]) operations.push({s[i],order[s[i]]});
                    else{
                        while(operations.size()!=0 && operations.top().first!='(')
                        {
                            ans = ans + operations.top().first;
                            operations.pop();
                        }
                        operations.push({s[i],order[s[i]]});
                    }
                }
            }
        }
        
        while(!operations.empty()) 
        {
            ans = ans + operations.top().first;
            operations.pop();
        }
        
        return ans;
    }    
};
/* `1. make a stack of operations with their precedence using stack pair
    2. there are 5 cases when we loop through the string
    a. ith element is an operant , hence easily push in the ans string
    b. ith element is open bracket , push it with precedence '0' without checking for previous precedence
    c. ith element is closed bracket, add total operations string to ans string till the closest open
        bracket and pop the open bracket.
    d. ith element is an operation and its precedence is greater than its previous ones, directly push in 
        operations stack
    e. ith element is an operation and its precedence is <= prev ones, then push all operations into ans strinf
        till the closest open bracket or till stack is empty and now push the current one into the stack.
    
    3. after completion of for loop add remaining operations which are left in stack to the ans string.
/*
