class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
        
    }

    int binarySearch(vector<int>& nums, int left, int right, int target) {
        if(left > right) return -1;
        int mid = (left + right) / 2;

        if(nums[mid] == target) return mid;

        else if(nums[mid] < target) return binarySearch(nums, mid + 1, right, target);

        else return binarySearch(nums, left, mid - 1, target);
    }
};