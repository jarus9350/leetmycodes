class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()){
            swap(nums1,nums2);
        }

        int size = nums1.size() + nums2.size();
        int half = size/2;

        int l = 0;
        int r = nums1.size() - 1;

        while (true){
            int i = floor((double)(l + r)/2); //partition index for smaller array
            cout<<i<<endl;
            int j =  half - i - 2;

            int Aleft =  i >= 0 ? nums1[i] : INT_MIN;
            int Aright =  i + 1 < nums1.size() ? nums1[i+1] : INT_MAX;
            int Bleft =  j >= 0 ? nums2[j] : INT_MIN;
            int Bright =  j + 1 < nums2.size() ? nums2[j+1] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                if (size % 2) {
                    cout<<"here"<<endl;
                    // cout<<(double)(max(Aright,Bright))<<endl;
                    return (double)(min(Aright,Bright));
                } else {
                    cout<<"there"<<endl;
                    // cout<<(double)(max(Aleft,Bleft) + min(Aright,Bright))<<endl;
                    return (double)(max(Aleft,Bleft) + min(Aright,Bright))/(double)2;
                }
            } else if ( Aleft > Bright) {
                cout<<"first"<<endl;
                r = i - 1;
            } else if (Bleft > Aright) {
                cout<<"second"<<endl;
                l = i + 1;
            }
        }

        return 0;
        
    }
};