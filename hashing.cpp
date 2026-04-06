// hashing--> precomputation and fetching

// hashing of number using array
#include <iostream>
void reverse(int i, int arr[], int n){
    if(i>=n/2){return;}
    int x = arr[i];
    arr[i] = arr[n-i-1];
    arr[n-i-1] = x;
    reverse(i+1,arr,n);
}
int main() {
    int n;
    std::cin>>n;
    int arr[n];
    for(int i = 0 ; i<n;i++){
        std::cin>>arr[i];
    }
    reverse(0,arr,n);
    for(int i = 0; i<n;i++){
        std::cout<<arr[i];
    }
    return 0;
}



// hashing of characters using array

#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    
    // pre-computation
    int hash[256] = {0};
    for(int i = 0;i<s.size();i++){
        hash[s[i]]++;
    }
    
    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        
        // fetching
        cout<<hash[c]<<endl;
    }
    return 0;
}


// hashing of number using map

#include<iostream>
#include<map>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    
    // pre-computation 
    map<int,int>mpp;
    for(int i = 0;i<n;i++){
        mpp[arr[i]]++;
    }
    
    // iterate in the map
    for(auto it:mpp){
        cout<<it.first<<"-->"<<it.second<<endl;
    }
    
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        //fetching
        cout<<mpp[num]<<endl;
    }
    return 0;
}



// hashing of characters using map

