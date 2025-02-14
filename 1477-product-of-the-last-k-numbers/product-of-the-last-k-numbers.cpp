class ProductOfNumbers {
public:
    vector<int> zeroesFound;
    vector<int> prefixProducts;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (prefixProducts.size() == 0) {
            prefixProducts.push_back(num);
        } else {
            int lastElement = prefixProducts.back();
            if (lastElement == 0) {
                prefixProducts.push_back(num);
            } else {
                prefixProducts.push_back(lastElement*num);
            }

        }

        if (num == 0){
            if (zeroesFound.size() == 0){
                zeroesFound.push_back(1);
            } else {
                zeroesFound.push_back(zeroesFound.back() + 1);
            }
        } else {
            if (zeroesFound.size() == 0){
                zeroesFound.push_back(0);
            } else {
                zeroesFound.push_back(zeroesFound.back());
            }
        }

        

        return;
        
    }
    
    int getProduct(int k) {
        int len = prefixProducts.size();

        int indexSubtract = len - k - 1;
        if (indexSubtract >= 0) {
            int lastNum = prefixProducts[len - 1];
            int toDivide = prefixProducts[indexSubtract];

            int numZeroes = zeroesFound[len-1] - zeroesFound[indexSubtract];
            if (numZeroes == 0) {
                if ( toDivide != 0) {
                    return lastNum/toDivide;
                } else {
                    return lastNum;
                }
            } else {
                return 0;
            }
        } else {
            int numZeroes = zeroesFound[len-1];
            cout<<numZeroes<<" "<<k<<endl;
            if (numZeroes == 0) {
                return prefixProducts[len - 1];
            } else {
                return 0;
            }
        }


        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */