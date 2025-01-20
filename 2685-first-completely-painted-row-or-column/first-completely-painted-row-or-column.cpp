class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int all = m*n + 1;

        vector<int> rows(all,0);
        vector<int> columns(all,0);

        vector<int> r(m,0);
        vector<int> c(n,0);

        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                int num = mat[i][j];
                rows[num] = i;
                columns[num] = j;
            }
        }

        
        for (auto r: rows){
            cout<<r<<" ";
        }
        cout<<endl;

        for (auto r: columns){
            cout<<r<<" ";
        }
        cout<<endl;



        for (int i = 0 ; i < arr.size() ; i++){
            int num = arr[i];
            int row = rows[num];
            int col = columns[num];

            r[row]++;
            c[col]++;

            if (r[row] == n) return i;
            if (c[col] == m) return i;
        }


        return all-1;


    }
};