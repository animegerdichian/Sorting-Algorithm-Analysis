#include <vector>
#include "project1.h"


/*
 *insertion_sort
 *Arguments: reference to vector of ints
 *Returns: void
 *
 *A function that sorts a vector of ints
 *in place using insertion sort algorithm
 */
void insertion_sort(std::vector<int>& nums){

  /*iterate through elements starting at index 1
  element at index 0 is already sorted since it
  is the only element in the sorted partition*/	
  for(unsigned long i = 1; i < nums.size(); i++){
    int temp = nums[i];
    
    
    unsigned long j = i;
    /*shift elements of sorted array partition
     if they are larger than temp*/
    while(j > 0 && nums[j-1] > temp){
      nums[j] = nums[j-1];
      j--;
    
    }

    nums[j] = temp;
  
  }

}
