#include <vector>
#include "project1.h"


/*
* shell_sort3
* Arguments: reference to vector of ints
* Returns: void
* A function that uses shell sort algorithm
* and A003586 sequence for gaps to sort
* a vector of ints
*/
void shell_sort3(std::vector<int>& nums){

  // a vector of the gap values
  std::vector<unsigned long> gaps = {1,2,3,4,6,8,9,12,16,18,24,27,32,36,48,54,64,72,
 				81,96,108,128,144,162,192,216,243,256,288,324,384,
 				432,486,512,576,648,729,768,864,972,1024,1152,
 				1296,1458,1536,1728,1944,2048,2187,2304,2592,2916,
 				3072,3456,3888};
  
  // choose the starting gap value based on nums size
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
