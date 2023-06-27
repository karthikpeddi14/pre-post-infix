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
    string postToInfix(string pre_exp) 
    {
        stack<string> ans;
        for(int i=0 ; i<pre_exp.size() ; i++)
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
                // string op =;
                ans.push("(" +B + pre_exp[i] + A + ")");
            }
        }
        
        return ans.top();
    }
    
};
