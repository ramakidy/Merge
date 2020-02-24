#include <iostream>
 
using namespace std;
 
//method to merge the two half into a sorted data.
void Merge(int *a, int left, int right, int mid)
{
	// We have left to mid and mid+1 to high already sorted.
	int i, j, k, temp[right-left+1];
	i = left;
	k = 0;
	j = mid + 1;
 
	// Merge the two parts into temp[].
	while (i <= mid && j <= right){
		if (a[i] < a[j]){
			temp[k] = a[i];
			k++;
			i++;
		}else{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	//copy all the remaining values from i to mid into temp[]
	while (i <= mid){
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// copy all the remaining values from j to right into temp[].
	while (j <= right){
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	// declaring and initiating sorted data stored in temp[] to a[].
	for (i = left; i <= right; i++){
		a[i] = temp[i-left];
	}
}
 
// A method to split array into two parts.
void MergeSort(int *a, int left, int right){
	int mid;
	if (left < right){
		mid=(left+right)/2;
		// Split the data into two half.
		MergeSort(a, left, mid);
		MergeSort(a, mid+1, right);
 
		// Merge them to get sorted output.
		Merge(a, left, right, mid);
	}
}
 
int main(int argc, char** argv){
	int n, i;
	cout<<"ENTER NUMBER OF DATA ELEMENTS TO SORT: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++){
		cout<<"ENTER ELEMENT "<<i+1<<": ";
		cin>>arr[i];
	}
	
	cout<<"ORIGINAL ARRAY:[ ";
	//printing original array
	for(int i = 0;i<n;i++){
	
	cout<<arr[i]<<" ";
}
	cout<<" ]";
	MergeSort(arr, 0, n-1);
 
	// Printing the sorted array
	cout<<"\n\nSORTED DATA ";
	for (i = 0; i < n; i++){
	
	       cout<<" "<<arr[i];
}
	return 0;
}
