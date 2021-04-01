class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        double median = 0.0;
        if(len % 2)
        {
            median = findKthElement(nums1, nums2, len / 2 + 1);
        }
        else
        {
            median = (findKthElement(nums1, nums2, len / 2) + findKthElement(nums1, nums2, len / 2 + 1)) / 2.0;
        }
        return median;
    }
    
    int findKthElement(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int i = 0;
        int j = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        while(true)
        {
            if(i >= len1)
            {
                return nums2[j + k - 1];
            }
            if(j >= len2)
            {
                return nums1[i + k - 1];
            }
            if(k == 1)
            {
                return min(nums1[i], nums2[j]);
            }
            
            int index1 = min(i + k / 2 - 1, len1 - 1);
            int index2 = min(j + k / 2 - 1, len2 - 1);
            if(nums1[index1] <= nums2[index2])
            {
                k -= (index1 - i + 1);
                i = index1 + 1;
            }
            else
            {
                k -= (index2 - j + 1);
                j = index2 + 1;
            }
        }
        
    }
};
