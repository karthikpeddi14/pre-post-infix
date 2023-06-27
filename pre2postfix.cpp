class Solution {
  public:
    bool condition(char x)
    {
        string con = "*/-+";
        for(auto it:con)
        {
            if(it == x) return false;
        }
        return true;
    }
    string preToPost(string pre_exp) 
    {
        stack<string> ans;
        for(int i=pre_exp.size()-1 ; i>=0 ; i--)
        {
            if(condition(pre_exp[i]))
            {
                string pusher;
                pusher = pusher + pre_exp[i];
                ans.push(pusher);
            }
            else{
                string A = ans.top();
                ans.pop();
                string B = ans.top();
                ans.pop();
                ans.push(A+B+pre_exp[i]);
            }
        }
        return ans.top();
    }
};
// same as the previous one but put the operation to the right of both the top 2 elements.
