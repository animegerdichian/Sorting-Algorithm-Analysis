#include <vector>
#include "project1.h"

/*
* shell_sort1
* Arguments: reference to vector of ints
* Returns: void
* A function that uses shell sort algorithm
* and the original Shell sequence for gaps to sort
* a vector of ints
*/ 
void shell_sort1(std::vector<int>& nums){
  for(unsigned long gap = nums.size()/2; gap > 0; gap /=2){
    
    for(unsigned long i = gap; i < nums.size(); i++){
      int temp = nums[i];
      unsigned long j = i;
      // move element by gap indexes until it is 
      // in the correct spot
      while( j >= gap && temp < nums[j - gap]){
        nums[j] = nums[j - gap];
	j -= gap;
      }
      nums[j] = temp;
    
    }
  }


}
