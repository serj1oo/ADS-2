int countPairs1(int* arr, int len, int value)
{
	int counter = 0;
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] + arr[j] == value)
				counter++;
		}
	}

	return counter;
}
int countPairs2(int* arr, int len, int value)
{
	int counter = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j =len-1 ; j>i; j--)
		{
			while (arr[i] + arr[j] == value && j > i)
			{
				counter++;
				j--;
			}
			if (arr[i] + arr[j] < value)
				break;
		}
	}

	return counter;
}
int countPairs3(int* arr, int len, int value)
{
	int counter = 0;
	for (int i = 0; i < len - 1; i++)
	{
		int first = i, last = len;
		
		while (first < last-1)
		{
			int center = (first + last) / 2;
			if (arr[i] + arr[center] == value)
			{
				counter++;
				int j = center+1;
				while (arr[i] + arr[j] == value && j<last)
				{
					counter++;
					j++;
				}
				j = center - 1;
				while (arr[i] + arr[j] == value && j>first)
				{
					counter++;
					j--;
				}
				break;
			}
			if (arr[i] + arr[center] > value)
				last = center;
			else
				first = center;
		}
	
	}
	
	return counter;
}
