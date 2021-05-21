#include <vector>
#include "project1.h"
#include <cmath>

/*
 *merge_hybrid2
 *Arguments: reference to vector of ints, int for index of partiton start, 
 *int for index of partition end, int for partition middle
 *Returns: void
 *
 *A function that merges two sorted partitions
 */
void merge_hybrid2(std::vector<int>& nums, int left, int right, int mid){
	
	
	// temporary lists to hold the two partitions
	std::vector<int> Left;
	std::vector<int> Right;


	int partition1Size = mid - left + 1;
	int partition2Size = right - mid;
	
	// add elements to each temp partition list
	for(int i=0; i < partition1Size; i++){

		Left.push_back(nums[left + i]);
		
	}

	for(int j=0; j < partition2Size; j++){
		Right.push_back(nums[mid + j + 1]);
		
	}
	
	int i = 0;
	int j = 0;
	int q = left;

	// compare elements
	while(i < partition1Size && j < partition2Size){
		if(Left[i] <= Right[j]){
			nums[q] = Left[i];
			i++;
		}
		else{
			nums[q] = Right[j];
			j++;
		}

		q++; 
	}
	
	// add in other elements in the temporary
	// vectors
	while(i < partition1Size){
		nums[q] = Left[i];
		i++;
		q++;
	}

	while( j < partition2Size){
		nums[q] = Right[j];
		j++;
		q++;
	}
}

/*
 *insertion_sort_hybrid2
 *Arguments: reference to vector of ints, int for index of partiton start, int for index of partition end
 *Returns: void
 *
 *A function that sorts a specified partition of a vector of ints
 *in place using insertion sort algorithm
 */
void insertion_sort_hybrid2(std::vector<int>& nums, int left, int right){

  /*iterate through elements starting at index
  to the right of the partition start index*/
  for(int i = left + 1; i <= right; i++){
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

/*
 *hybrid_sort_rec2
 *Arguments: reference to vector of ints, int for index of partiton start, 
 *int for index of partition end, long h for hybridization value
 *Returns: void
 *
 *A function that recursively sorts a vector in place using a hybrid
 *of merge sort and insertion sort depending on hybridization value
 *
 *merge sort is chosen when h > the partition that needs to be sorted
 *insertion sort is chosen when the problem size is less than h
 */
void hybrid_sort_rec2(std::vector<int>& nums, int left, int right,long h){
	

	if(left >= right)
		return;
	
	
	if(h > (right-left) + 1){
	  int mid = left + (right - left) / 2;// partition the list
	  hybrid_sort_rec2(nums, left, mid,h); // sort first partition
	  hybrid_sort_rec2(nums, mid+1, right,h); // sort second partition
	  merge_hybrid2(nums, left, right, mid); // merge the two sorted partitions
	}
	else{
	  insertion_sort_hybrid2(nums, left, right);
	
	}

}

/*
 *hybrid_sort2
 *Arguments: reference to vector of ints
 *Returns: void
 *
 *A function that calculates h = n^0.25 and 
 *calls recursive function hybrid_sort_rec2
 *to sort using a merge sort, insertion sort hybrid
 *algorithm
 */
void hybrid_sort2(std::vector<int>& nums){
  
	unsigned long h = pow(nums.size(), 0.25);
	if(nums.size() > 1){
	
	  hybrid_sort_rec2(nums,0,nums.size()-1,h);
	}
	
}



