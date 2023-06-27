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
    string postToPre(string post_exp) {
        stack<string> ans;
        
        for(int i=0 ; i<post_exp.size() ; i++)
        {
            if(condition(post_exp[i]) )
            {
                string pusher;
                pusher = pusher + post_exp[i];
                ans.push(pusher);
            }
            else{
                string A = ans.top();
                ans.pop();
                string B = ans.top();
                ans.pop();
                ans.push(post_exp[i]+ B + A);
            }
        }
        return ans.top();
    }
};
