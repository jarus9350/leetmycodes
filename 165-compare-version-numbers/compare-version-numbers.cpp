class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1;
        vector<string> v2;

        string s = "";
        for (int i = 0 ; i < version1.size() ;){
            if (version1[i] == '.') {
                if (s!= "") v1.push_back(s);
                s = "";
                int k = i;
                while ( i+1 < version1.size() && version1[i+1] == '0') {
                    i++;
                }
                if (i+1 < version1.size() && version1[i+1] == '.' && i +1  != k) {
                    v1.push_back("0");
                    s = "";
                }
                i++;
            } else {
                s.push_back(version1[i]);
                i++;
            }
        }

        if (s!= "") v1.push_back(s);


        s = "";
        for (int i = 0 ; i < version2.size() ;){
            if (version2[i] == '.') {
                if (s!= "") v2.push_back(s);
                s = "";

                int k = i;
                while ( i+1 < version2.size() && version2[i+1] == '0') {
                    i++;
                }
                if (i+1 < version2.size() && version2[i+1] == '.' && i +1  != k) {
                    v2.push_back("0");
                    s = "";
                }
                i++;
            } else {
                s.push_back(version2[i]);
                i++;
            }
        }

        if (s!= "") v2.push_back(s);

        // for (auto c: v1) {
        //     cout<<c<<" ";
        // }
        // cout<<endl;

        // for (auto c: v2) {
        //     cout<<c<<" ";
        // }
        // cout<<endl;

        int i = 0;
        for (; i < v1.size() && i < v2.size(); i++){
            if (stoi(v1[i]) < stoi(v2[i])) {
                return -1;
            } else if (stoi(v1[i]) > stoi(v2[i])) {
                return 1;
            } 
        }

        if (v1.size() > v2.size()) {
            while ( i < v1.size()) {
                if (v1[i++] != "0") return 1;
            }
        } else if (v1.size() < v2.size()) {
            while ( i < v2.size()) {
                if (v2[i++] != "0") return -1;
            }
        }



        return 0;
        
    }
};