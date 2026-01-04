// Last updated: 1/3/2026, 4:49:10 PM
1class Solution {
2public:
3    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
4
5        if(k > arr.size()) return 0;
6
7        int sum = 0;
8        int total = 0;
9        for(int i = 0; i < k - 1; ++i) sum += arr[i];
10
11        for(int i = k - 1; i < arr.size(); ++i) {
12            sum += arr[i];
13            if(sum >= k * threshold) ++total;
14            sum -= arr[i - k + 1];
15        }
16
17        return total;
18    }
19};