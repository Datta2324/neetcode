class Solution {
public:
    void merge(vector<int>&nums, int l, int mid, int r)
    { 
        int i = l;
        int j = mid + 1;
        vector<int> temp;
        while((i <= mid) && (j <= r))
        {
            if(nums[i] < nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
                
        }
        while(i <= mid)
        {
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= r)
        {
            temp.push_back(nums[j]);
            j++;
        }

        for(int i = l; i<= r;i++ )
        {
            nums[i] = temp[i - l];
        }

        
    }
    void mergeSort(vector<int>& nums, int l , int r)
    {
        // Base condition
        if (l >= r)
            return;

        int mid = (l + r)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid + 1, r);
        merge(nums,l,mid,r);

    }
    vector<int> sortArray(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        mergeSort(nums,l,r);  
        return nums;
    }
};