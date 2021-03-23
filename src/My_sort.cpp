//
// Created by jacob on 2021/3/13.
//
// sort algorithm

template<class T>
void swap(T & a, T & b)
{
    T temp = a;
    a = b;
    b = temp;
}

// selection sort
// choose the minimum element and put it in the first place
template<class T>
void selection_sort(T arr[], int size){
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size; ++j)
            if (arr[j] < arr[i])
                swap(arr[j], arr[i]);
}


// insertion sort
// sort current part of the array
template<class T>
void insertion_sort(T arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        int j = i;
        while (j > 0 && (arr[j] < arr[j-1]))
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}


// quick sort
// put the elements that are smaller than the pivot in the left
// and put the elements that re larger than the pivot in the right
template<class T>
void quickSort(T arr[], int left, int right){
    T pivot = arr[left];
    int i = left, j = right; 
    while (j > i){
        while (j > i && arr[j] > pivot)
            j--;
        swap(arr[j], arr[i]);
        while (j > i && arr[i] < pivot)
            i++;
        swap(arr[i], arr[j]);
    }
    quickSort(arr, 0, left);
    quickSort(arr, left + 1, right);
}


// merge sort
// devide the array into two part with the same length, make them sorted
// then merge these two sorted parts
template<class T>
void merge(T arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    T larr[n1], rarr[n2];
    for (int i = 0; i < n1; ++i)  larr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)   rarr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if (larr[i] <= rarr[j])     arr[k++] = larr[i++];
        else arr[k++] = rarr[j++];
    }
    while (i < n1)  arr[k++] = larr[i++];
    while (j < n2)  arr[k++] = rarr[j++];
}

template<class T>
void mergeSort(T arr[], int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        mergeSort(arr, 0, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


// heap sort
template<class T>
void MinSort(T arr[], int i, int n){
    int j = 2 * i + 1; // find the left child of the current node
    T temp = arr[i]; // prepare for value conversion
    while (j < n){
        if (j+1 < n && arr[j] < arr[j+1])
            ++j; // ensure that the largest child is exchanged with the parent node
        if (arr[i] > arr[j])
            break;
        else{
            arr[i] = arr[j];
            i = j;
            j = 2 * i + 1;
        }
    }
    arr[i] = temp;
}

template<class T>
void heapSort(T arr[], int n){
    for (int i = n / 2 - 1; i >= 0; --i)
        MinSort(arr, i, n);
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        MinSort(arr, 0, i);
    }
}