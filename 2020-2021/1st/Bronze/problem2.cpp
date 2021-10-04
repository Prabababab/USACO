#include <bits/stdc++.h>
using namespace std;
//Problem Name: Do You Know Your ABCs?

int main(){
    
    int arr[7];
    for(int& i : arr) cin >> i;
    
    sort(arr, arr + 7);
    
    int a = arr[0], b = arr[1], c = arr[2];
    if(a + b == c) c = arr[3];
    
    cout << a << " " << b << " " << c << "\n";
    
    return 0;
    
}
