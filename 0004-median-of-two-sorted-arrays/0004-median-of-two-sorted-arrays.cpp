class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp;
        int a=0,b=0;
        while(a<nums1.size() && b<nums2.size()){
            if(nums1[a]<=nums2[b]){
                temp.push_back(nums1[a]);
                a++;
            }
            else{
                temp.push_back(nums2[b]);
                b++;
            }
        }
        while(a<nums1.size()){
            temp.push_back(nums1[a]);
            a++;
        }
        while(b<nums2.size()){
            temp.push_back(nums2[b]);
            b++;
        }
        if((temp.size()%2)==0){
            return (double)(temp[temp.size()/2]+temp[(temp.size()/2)-1])/2;
        }
        else{
            return (double)temp[temp.size()/2];
        }
    }
};