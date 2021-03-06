class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //combine both arrays
        vector<int> combined;
        if (nums1.size() == 0)
        {
            combined.insert(combined.end(), nums2.begin(), nums2.end());
        } else if (nums2.size() == 0) {
            combined.insert(combined.end(), nums1.begin(), nums1.end());
        } else {
            auto it1 = nums1.begin();
            auto it2 = nums2.begin();
            for (int i = 0; i < nums1.size() + nums2.size(); i++)
            {
                combined.push_back(min(*it1, *it2));
                if (*it1 > *it2)
                {
                    if (it2 == nums2.end() - 1)
                    {
                        combined.insert(combined.end(), it1, nums1.end());
                        break;
                    }
                    it2 = next(it2);
                } else {
                    if (it1 == nums1.end() - 1)
                    {
                        combined.insert(combined.end(), it2, nums2.end());
                        break;
                    }
                    it1 = next(it1);
                }
            }
        }
        //find median of combined array
        if (combined.size() % 2 == 1)
        {
            return combined[combined.size() / 2];
        } else {
            return (double) (combined[(combined.size() / 2) - 1] + combined[combined.size() / 2]) / 2;
        }
    }
};
