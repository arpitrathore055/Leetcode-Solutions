class Solution {
public:

    int binarySearch(vector<int>& arr,int& target){

        int start=0;
        int end=arr.size()-1;

        int foundAtIndex=-1;
        while(start<=end){

            int middle=start+(end-start)/2;
            if(arr[middle] == target){
                return middle;
            }
            else if(arr[middle] < target){
                start=middle+1;
            }
            else{
                end=middle-1;
            }

        }
        return foundAtIndex;

    }

    int findKthPositive(vector<int>& arr, int k) {

        int ans=-1;
        for(int i=1;k>0;i++){
            
            int foundAtIndex=binarySearch(arr,i);
            if(foundAtIndex == -1){
                ans=i;
                --k;
            }
            else{
                continue;
            }

        }

        return ans;
    }
};