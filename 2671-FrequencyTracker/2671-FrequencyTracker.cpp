// Last updated: 5/29/2026, 2:09:27 PM
1class FrequencyTracker {
2private:
3    unordered_map<int, int> nums;
4    unordered_map<int, int> freq;
5public:
6    FrequencyTracker() {
7    }
8    
9    void add(int number) {
10        int newFreq = ++nums[number];
11        freq[newFreq]++;
12        if(newFreq - 1 != 0) freq[newFreq - 1]--;
13    }
14    
15    void deleteOne(int number) {
16        if(nums.count(number) == 0 || nums[number] == 0) return;
17        int newFreq = --nums[number];
18        if(newFreq > 0) freq[newFreq]++;
19        freq[newFreq + 1]--;
20    }
21    
22    bool hasFrequency(int frequency) {
23        if(freq[frequency] != 0) return true;
24        return false;
25    }
26};
27
28/**
29 * Your FrequencyTracker object will be instantiated and called as such:
30 * FrequencyTracker* obj = new FrequencyTracker();
31 * obj->add(number);
32 * obj->deleteOne(number);
33 * bool param_3 = obj->hasFrequency(frequency);
34 */