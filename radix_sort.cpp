/**
use radix sort algorithm to sort non negative integer
time complexity: O(k*3n) = O(k*n); memory complexity O(n+k)
*/
#include <vector>
#include <algorithm>

void radix_10_sort(std::vector<int>& nums){
    if(nums.empty()){
        return;
    }
    int radix = 10;
    int max_val = *std::max_element(nums.begin(), nums.end());
    int exp = 1; //base 1, 10, 100, ... ...
    std::vector<int> temp(nums.size());//temp space needed
    while(exp <= max_val){
        std::vector<int> counts(radix, 0);
        for(size_t i = 0; i < nums.size(); i++){
            counts[(nums[i] / exp) % 10]++;
        }
        for(size_t i = 1; i < counts.size(); i++){
            counts[i] += counts[i-1];
        }
        //sort into temp; loop from the rear to have stable sort
        size_t i = nums.size() -1;
        for(; i != 0; i--){
            size_t i_count = (nums[i]/exp) % radix;
            counts[i_count] -= 1;
            size_t index = counts[i_count];
            temp[index] = nums[i];
        }
        size_t i_count = (nums[0]/exp) % radix;
        counts[i_count] -= 1;
        size_t index = counts[i_count];
        temp[index] = nums[0];
        //copy from temp to nums
        nums.assign(temp.begin(), temp.end());

        exp *= radix;
    }
}
