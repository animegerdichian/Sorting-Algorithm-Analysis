#include <vector>
#include <cmath>
#include "project1.h"


/*
* shell_sort2
* Arguments: reference to vector of ints
* Returns: void
* A function that uses shell sort algorithm
* and A083318 sequence for gaps to sort
* a vector of ints
*/
void shell_sort2(std::vector<int>& nums){
  
  // calculate the gap
  int k = log2(nums.size());
  int gap = pow(2, k) + 1;
 
  while(gap > 0 && k != -1){
    
    for(unsigned long i = gap; i < nums.size(); i++){
      int temp = nums[i];
      int j = i;
      // move element by gap indexes until it is 
      // in the correct spot
      while( j >= gap && temp < nums[j - gap]){
        nums[j] = nums[j - gap];
	j -= gap;
      }
      nums[j] = temp;
    }
    // update the gap
    if(k == 0 && gap != 1){
      gap = 1;
      
    }
    else{
      k -= 1;
      gap = pow(2, k) + 1;
    }
  
  }


}

