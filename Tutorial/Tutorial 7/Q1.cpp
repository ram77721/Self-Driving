#include <iostream>
using namespace std;

int getval (int* x, int n){
    int count = 0; int total = 0;
    total = n*(n+1)/2;
    for(int i = 0; i<n;i++){
        count += x[i];     
    }
    return total - count;

    
}




int main(){
int x[6] = {4,2,0,6,3,5};
cout << 3000 / 4095.0 / 9.89 / (9.89 + 19.80) * 0.1;
cout << 3000/4095/3/10;


}