class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int indexForFirst = 0;
        int indexForSecond = 0;
        vector<int> merged;
        
        if (nums1.size() == 0) {
            merged = nums2;
        }
        else if (nums2.size() == 0) {
            merged = nums1;
        }
        else {
            while (indexForFirst < nums1.size() && indexForSecond < nums2.size()) {
                std::cout << nums1[indexForFirst] << " " << nums2[indexForSecond] << "\n";
                if (nums1.at(indexForFirst) < nums2.at(indexForSecond)) {
                    merged.push_back(nums1[indexForFirst]);
                    indexForFirst++;
                }
                else {
                    merged.push_back(nums2[indexForSecond]);
                    if (nums1.at(indexForFirst) == nums2.at(indexForSecond)) {
                        merged.push_back(nums2[indexForSecond]);
                        indexForFirst++;
                    }
                    indexForSecond++;
                }
            }
            while (indexForFirst < nums1.size()) {
                merged.push_back(nums1[indexForFirst]);
                indexForFirst++;
            }
            while (indexForSecond < nums2.size()) {
                merged.push_back(nums2[indexForSecond]);
                indexForSecond++;
            }
        }
        
        int middleIndex = (merged.size() % 2 == 0) ? merged.size() / 2 - 1 : (int) (merged.size() / 2);
        
        if (merged.size() % 2 == 0) {
            return (double) (merged[middleIndex] + merged[middleIndex + 1]) / 2;
        }
        return merged[middleIndex];
    }
};
