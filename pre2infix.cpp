class Solution {
  public:
    bool condition(char x)
    {
        string con = "*/+-";
        for(auto it:con)
        {
            if(it == x) return false;
        }
        return true;
    }
    string preToInfix(string pre_exp) 
    {
        stack<string> ans;
        for(int i=pre_exp.size()-1 ; i>=0 ; i--)
        {
            if(condition(pre_exp[i])) 
            {
                string pushing ;
                pushing = pushing + pre_exp[i];
                ans.push(pushing);
            }
            else
            {
                string A = ans.top();
                ans.pop();
                string B = ans.top();
                ans.pop();
                string op ="(" +A + pre_exp[i] + B + ")";
                ans.push(op);
            }
        }
        
        return ans.top();
    }
};
/*  1. loop from last element and add elements to ans stack if the ith element is an operant
    2. is element is as operant , take stack top as A and next as B and do A operation B and push it
        into the ans stack.
    3. return ans.top when for loop ends.

/*
