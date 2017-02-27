#include<iostream>
#include<string> 
using namespace std;
 
int binarySearch(long long A[], int left, int right, long long key) 
{
  	while(left + 1 < right) 
		{
  	 	 	int mid = left + (right - left) / 2;
			if(A[mid]<key) 
  	   		 left = mid;
  	  		else 
  	    		right = mid;
  	 	 }
 	 return right;
}
 
int LICS(long long A[], int length) 
{
	  long long *temp = new long long[length];
	  for(int i = 0; i < length; i++)
	  	temp[i] = 0;
	  int len;
	  temp[0] = A[0];
  	  len = 1;
  	  for(int i = 0; i < length; ++i) 
		{
	    	 if(A[i] < temp[0])
      				temp[0] = A[i];
	    	 else if (A[i] > temp[len-1])
      			{	
				temp[len] = A[i];
      				len++;
			}
    		 else
			{
      				long long key = A[i];
     				temp[binarySearch(temp, -1, len - 1, key)] = A[i];
   		 	}
		}
	 delete[] temp;
  	 return len;
}
 
int main() 
{
  	int t;
  	cin>>t;
  	while(t--)
	{
    		int n;
   		cin>>n;
    		long long data[2*n];
 		for(int i = 0; i < n; i++)
		{
      			cin>>data[i];
      			data[i+n] = data[i];
   		}
   	 int result = 0;
   	 for(int i = 0; i < n; i++) 
	{
    	 	int a = LICS(data+i, n);
      	 	if(a > result) 
         	result = a;
        }
        cout<<result<<endl;
	}
	return 0;
}
 
