class Solution {
public:
    string ans = "";

    void dfs(string inter,int i,int& n,int& k,int& current){
        if (current == k && inter.size() == n) {
            ans = inter;
            return;
        }


        if (i == n ) {
            return;
        } 

    
        string alphas = "abc";

        for (auto c: alphas){
            if (inter.empty() || inter.back() != c){
                inter.push_back(c);

                if (inter.size() == n) {
                    current++;

                    // cout<<inter<<" "<<current<<endl;
                }

                
                dfs(inter,i+1,n,k,current);

                inter.pop_back();
            }
        }

        return;
    }


    string getHappyString(int n, int k) {
        string inter = "";
        int total = 0;
        dfs(inter,0,n,k,total);
        
        return ans;
    }
};