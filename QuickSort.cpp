#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

bool isSorted(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}
void exchange(int &a, int &b){
	int flag = a;
	a = b;
	b = flag;
}
void quickSort(int *&a, int i, int j){
	int left = 0, right = 0;
    int pivot = j;
    j--;
    if(i >= pivot) {
        return;
    }
	while(i < j){
		if(a[i] > a[pivot] && a[j] <= a[pivot]){
            exchange(a[i], a[j]);
            i++; j--; left++; right++;
        }
        else if(a[i] > a[pivot]){
            j--; right++;
        }
        else if(a[j] <= a[pivot]){
            i++; left++;
        }
        else{
            i++;j--;right++;left++;
        }
    }
    if(a[i] > a[pivot]){
        exchange(a[pivot], a[i]);
        pivot = i;
        if(i==j) right++;
    } else if(i==j){
        exchange(a[pivot], a[i+1]);
        left++;
        pivot = i+1;
    } else left++;
    quickSort(a,pivot - left, pivot - 1);
    quickSort(a,pivot + 1, pivot + right);
}

int main(){
    srand(time(0));
    clock_t begin = clock();
	int n;
	// n = 1000000;
    cin >> n;
	int *a = new int[n];
	for(int i = 0; i < n; i++){
		// a[i] = rand()%4000000001 - 2000000000;
        cin >> a[i];
	}
	quickSort(a, 0, n-1);
		for(int i = 0; i < n; i++){
		cout << a[i]<<' ';
	}
    cout << endl;
    // if (isSorted(a, n)) {
    //     cout << "Dãy số đã tăng dần.\n";
    // } else {
    //     cout << "Dãy số chưa tăng dần.\n";
    // }
    clock_t end = clock(); //ghi lại thời gian lúc sau
   cout << '\n'<<"Time run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
	return 0;
}