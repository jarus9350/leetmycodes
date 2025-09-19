class Spreadsheet {
public:
    vector<vector<int>> sheet;
    Spreadsheet(int rows) {
        sheet.resize(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        auto column = cell[0] - 'A';
        auto row = stoi(cell.substr(1));
        sheet[row-1][column] = value;
        
    }
    
    void resetCell(string cell) {
        setCell(cell,0);
    }
    
    int getValue(string formula) {
        // cout<<"/////"<<endl;
        // for (auto a : sheet) {
        //     for (auto b: a){
        //         cout<<b<<" ";
        //     }
        //     cout<<endl;
        // }

        int result = 0;
        int num = 0;
        int col = -1; int row = -1;
        for (int i = 1; i < formula.size() ; i++){
            if (formula[i] == '+') {
                result += (col != -1) ? sheet[num-1][col] : num;
                num = 0;
                col = -1;
            } else if (formula[i] <= 'Z' && formula[i] >= 'A'){
                num = 0;
                col = formula[i] - 'A';
            } else {
                auto c = formula[i];
                num = num*10 + (formula[i] - '0');
                int n = num;
            }
        }

        result += (col != -1) ? sheet[num-1][col] : num;
        return result;

    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */