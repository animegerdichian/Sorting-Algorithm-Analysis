#include <vector>
#include <iostream>
#include "project1.h"


/*
* shell_sort4
* Arguments: reference to vector of ints
* Returns: void
* A function that uses shell sort algorithm
* and A00365562 sequence for gaps to sort
* a vector of ints
*/
void shell_sort4(std::vector<int>& nums){

  // vector with gap values
  std::vector<unsigned long> gaps = {8929,3905,2161,929,505,209,109,41,19,5,1};
  
  // find the correct gap value less than nums size
  unsigned long k = 0;
  while(gaps[k] >= nums.size()){
  	k++;
  }
  int gap = gaps[k];
  while(gap > 0){
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
    k++;
    if(k < gaps.size()){
      gap = gaps[k];
    }
    else{
      gap = -1;
    }
  }


}

