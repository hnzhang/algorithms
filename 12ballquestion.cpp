//[1 2 3 4 5 6 7 8 9 10 11 12]
//There is one ball is lighter or heavier. Use weighting only 3 times.

//Solution
if( weight([1,2,3,4], [5,6,7,8]) == equal)
{
	//the weird ball is in [9 10 11 12]
	//weight 9, 10 with 1, 2
	if(weight( [9, 10], [1, 2])== equal)
	{
		//weird ball is in 11, 12
		//weight 11 with 1
		if(weight([1], [11]) == equal)
		{
			//ball 12 is  weird
		}
		else
		{
			//ball 11 is weird
		}
	}	
	else//weird ball is in [9, 10]
	{
		//
	}
}
else //weird ball is in [1--8]
{
	//[1,2 3, 4] weight more
	if(weight([1, 5, 6], [2, 7, 8])== equal)
	{
		//weird ball is in [3,4]
	}
	else if([1,5,6] weight more)---ball 1
	else if([2, 7, 8] weight ball)---ball 2
	//if[5, 6, 7, 8] weight more
	if(weight([5, 1,2], [ 6, 3,4]) == equal)
	{
		//ball is in 7, 8
	}
	else if([5,1 ,2] weight more) //weird ball is 5
	else// weird ball is 6
}

