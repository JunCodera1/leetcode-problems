#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void merge(int a[], int l, int m, int r){
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    while(i < x.size() && j < y.size()){
        if(x[i] <= y[j]){
            a[l] = x[i]; ++l; ++i;
        }
        else{
            a[l] = y[j]; ++l; ++j;
        }
    }
    while(x[i] < x.size()){
        a[l] = x[i]; ++l; ++i;
    }
    while(y[j] < y.size()){
        a[l] = y[j]; ++l; ++j;
    }
}

void merge_sort(int a[], int l, int r){
    if(l >= r) return;
    int m = (l+r)/2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    merge(a, l, m , r);
}

int main(){
    int * a = new int[1000];
    int n;
    cout << "Enter the number of elements :  "; cin >> n;
    srand(time(nullptr));
    for(int i = 0; i < n; i++){
        a[i] = rand() % 1000;
    }
    merge_sort(a, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}