#include <iostream>

using namespace std;
void swap(int *xp, int *yp);
void printArray(int arr[], int size) ;


void buble(){
	int array[8]={12, 4, 5, 33, 91, 9, 1, 81};
	int swap, i, j;
	cout << "Data sebelum diurutkan: " << endl;
	for(i=0;i<8;i++){
		cout << " " << array[i];
	}
	for(i=0; i<8; i++){
		for(j=0; j<8; j++){
			if(array[j]>array[j+1]){
				swap = array[j];
				array[j] = array[j+1];
				array[j+1] = swap;
			}
		}
	}
	cout << endl << endl << "Data sesudah diurutkan: " <<endl;
	for(i=0;i<8;i++){
		cout << " " << array[i];
	}
}


//////////////////////////////////////////////////

  

  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        swap(&arr[min_idx], &arr[i]); 
    } 
} 




void selection(){
	int arr[] = {64, 25, 12, 22, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Array before sorting: " << endl;
    printArray(arr, n);
    selectionSort(arr, n); 
    cout << "Sorted array: \n"; 
    printArray(arr, n); 
}



/////////////////////////////////////



void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 



void insertion(){
	int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array before sorting: " << endl;
    printArray(arr,n);
 
    insertionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
}

///////////////////////////////////////

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
    {
       
        if (arr[j] < pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        
        int pi = partition(arr, low, high);
 
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quick(){
	int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array before sorting: " << endl;
    printArray(arr,n);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
}



///////////////////////////////////////

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++){
	
		L[i] = arr[l + i];
			for (j = 0; j < n2; j++){
			
				R[j] = arr[m + 1+ j];
			}
		}
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}	
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l+(r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

void margepanggil(){
	int arr[] = {12, 11, 13, 5, 6, 7};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	cout << "Given array is " << endl;
	printArray(arr, arr_size);
	mergeSort(arr, 0, arr_size - 1);
	cout << endl << "Sorted array is " << endl;
	printArray(arr, arr_size);
}

/////////////////

int shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
 
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            arr[j] = temp;
        }
    }
    return 0;
}


void shell(){
	int arr[] = {12, 34, 54, 2, 3}, i;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Array before sorting: " << endl;
	printArray(arr, n);
	shellSort(arr, n);
	cout << endl << "Array after sorting: " <<
	endl; printArray(arr, n);
}

///////////////////

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int main(){
	
	buble();
	cout << "\n"<<endl;
	selection();
	cout << "\n"<<endl;
	insertion();
	cout << "\n"<<endl;
	quick();
	cout << "\n"<<endl;
	margepanggil();
	cout << "\n"<<endl;
	shell();

	
}
