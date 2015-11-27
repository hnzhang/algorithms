#include <vector>
size_t quicksort_partition(std::vector<int>& data, size_t left, size_t right)
{
	//[] [] [] [] [] [] [] [] []  []
	
	//initialization: pivot is the last element: pivot = data[right] 
	//				size_t l = left, so that any elements with index = l -1 are partitioned to left
	//				size_t r = right-1, so that any elements with index= r +1 to right are partitioned to right.
	//				at the very beginning, these two parts are empty, or zero sized.

	//maintanence: if(data[l] < pivot) l++;// the declaration is still true
	//				else // swap data[l] with data[r], and r decrease 1, the declaration is still true

	//termination: l should always no greater than r; when l is greater than r, partion completed.

	//swap pivot to the middle
	//return the index of the pivot.

	size_t l = left, r = right-1;
	
	while(l < r )
	{
		if(data[l] < data[right] )
		{
			l++;
		}
		else
		{
			int temp = data[l];
			data[l] = data[r];
			data[r] = temp;
			r--;
		}
	}
	//note that data[l](data[r]) is not processed yet
	//swap pivot to the middle
	size_t pivot_index = 0;
	if(data[l] < data[right])// pivot should be at the location of l+1
	{
		if(l+1 < right)
		{
			pivot_index = l+1;
			int temp = data[pivot_index];
			data[pivot_index] = data[right];
			data[right] = temp;
		}
	}
	else
	{
		pivot_index = l;
		int temp = data[l];
		data[l] = data[right];
		data[right] = temp;
	}
	return pivot_index;
}

void quicksort_helper(std::vector<int>& data, size_t left, size_t right)
{
    if (left >= right) return;

    size_t p = quicksort_partition(data, left, right);
    if (left < p)
    {
        quicksort_helper(data, left, p - 1);
    }
    if (p < right)
    {
        quicksort_helper(data, p + 1, right);
    }
}

void quicksort(std::vector<int>& data)
{
    quicksort_helper(data, 0, data.size() -1);
}

//////////////////////////////////////////////////////////////////////////
//for testing
int main()
{
    std::vector<int> data1 = {1};
    std::vector<int> data2 = { 2, 1 };
    std::vector<int> data3 = { 2, 2 };
    std::vector<int> data4 = { 2, 4, 3, 6, 9, 5, 8, 7 };
    quicksort(data1);
    quicksort(data2);
    quicksort(data3);
    quicksort(data4 );

    return 0;
}