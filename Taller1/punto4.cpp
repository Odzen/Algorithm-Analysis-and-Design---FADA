// Merge sort in C++

#include <iostream>
using namespace std;


constexpr int numParejas=4;
constexpr int sizeParejas=2;


// Print the array
void printArray(int arr[numParejas][sizeParejas], int size) {
    int arrAux[numParejas][sizeParejas];
     for (int i = 0; i < numParejas; ++i) {
         cout<<"{ ";
        for (int j = 0; j < sizeParejas; ++j) {
            cout<<arr[i][j]<< "  ";
            
        }
        cout<<"}, ";
    }
    
  //for (int i = 0; i < size; i++)
   // cout << arr[i] << " ";
  cout << endl;
}



// Merge two subarrays L and M into arr
void merge(int arr[numParejas][sizeParejas], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1][sizeParejas], M[n2][sizeParejas];

  for (int i = 0; i < n1; i++)
  {
    L[i][0] = arr[p + i][0];
    L[i][1] = arr[p + i][1];
  }
  for (int j = 0; j < n2; j++)
  {
    M[j][0] = arr[q + 1 + j][0];
    M[j][1] = arr[q + 1 + j][1];
  }
  
  //printArray(L,n1);
  //printArray(M,n2);

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;
 
  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if(L[i][0] == M[j][0])
    {
      if (L[i][1] <= M[j][1]) 
      {
        arr[k][1] = L[i][1];
        arr[k][0] = L[i][0];
        i++;
      } 
      else 
      {
        arr[k][1] = M[j][1];
        arr[k][0] = M[j][0];
        j++;
      }
    }
    else
    {
      if (L[i][0] <= M[j][0])
      {
      arr[k][1] = L[i][1];
      arr[k][0] = L[i][0];
      i++;
      } 
      else
      {
        arr[k][1] = M[j][1];
        arr[k][0] = M[j][0];
        j++;
      }
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k][0] = L[i][0];
    arr[k][1] = L[i][1];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k][0] = M[j][0];
    arr[k][1] = M[j][1];
    j++;
    k++;
  }
  
  
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[numParejas][sizeParejas], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}


bool pairs(int arr[numParejas][sizeParejas]){
    bool pairs_done=false;
    int last=numParejas-1;
    int begin=0;
    int sumNivelA=arr[begin][0]+arr[last][0];
    int sumNivelB=arr[begin][1]+arr[last][1];
    last--;
    begin++;

    while(begin<(numParejas/2) && last>=(numParejas/2)){
        int sumNivelA_Actual=arr[begin][0]+arr[last][0];
        int sumNivelB_Actual=arr[begin][1]+arr[last][1];
        
        if((sumNivelA_Actual==sumNivelA) &&  (sumNivelB_Actual==sumNivelB))
            pairs_done=true;
        else
            pairs_done=false;
        last--;
        begin++;
    }
    return pairs_done;
    
}

// Driver program
int main() {
  int arr[6][2] = { {2,1}, {4,2}, {3,0},{4,2},{3,0}, {5,1}};
  int arr2[4][2] = { {1,0}, {0,1}, {-2,0},{0,-2}};
  
  mergeSort(arr2, 0, numParejas - 1);
  printArray(arr2, numParejas);
  
  //Look if they can organize equal pairs
  bool pairs_done=pairs(arr2);
  
  cout<<pairs_done;
  
  return 0;
}