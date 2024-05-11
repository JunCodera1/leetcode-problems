#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int partition(int a[], int l, int r){
    int pivot = a[l];
    int i = l-1; int j = r+1;
    while(true){
        do{
            i++;
        }while(a[i] < pivot);
        do{
            j--;
        }while(a[j] > pivot);
        if(i < j){
            swap(a[i], a[j]);
        }   
        else return j;
    }
}

void quick_sort(int a[], int l, int r){
    if(l >= r) return;
    int p = partition(a, l, r);
    quick_sort(a, l, p);
    quick_sort(a, p+1, r);
}

int main(){
    int * a = new int[1000];
    srand(time(nullptr));
    int n; 
    cout << "Enter number elements to random : ";
    cin >> n;
    for(int i = 0; i < n; i++){
        a[i] = rand() % 1000;
    }
    quick_sort(a, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}