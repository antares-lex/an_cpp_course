#include <iostream>
using namespace std;


void show(){
    for (int i=0; i<10;i++){
        cout << i << ' ';
    }
}

void show_1(int n){
    for (int i=0; i<n;i++){
        cout << i << ' ';
    }
}


int sum (int a, int b){
    return a+b;
}

int pyramid(int n) {
    // Your solution goes here
    
    int max_in_rows = 0; 
    int row = 0;
    int i = 0;
    while (max_in_rows <= n) {
        row = i-1;
        max_in_rows += i;
        i++;
    }
    return row;
            
}

int maxMultiple(int divisor, int bound) 
{
  int N = 0;
  N = (bound/divisor)*divisor;
  return N;
}





int main()
{
    cout << maxMultiple(2,-7) << endl;
    cout << maxMultiple(3,10) << endl;
    cout << maxMultiple(7,17) << endl;

    cout << maxMultiple(10,50) << endl;
    cout << maxMultiple(37,200) << endl;
    cout << maxMultiple(7,100) << endl;

    //cout << pyramid(   1) << endl;
    //cout << pyramid(   4) << endl;
    //cout << pyramid(  20) << endl;
    //cout << pyramid( 100) << endl;
    //cout << pyramid(9999) << endl;

    /*int n;
    cin >> n;
    for(int i=0 ; i<n; i++)
    {
        cout << i << " " << i*i << endl;
    }
   

   int n;
   cin >> n;
   if (n > 0) {
       cout << "+";
   }
   else if (n < 0) {
       cout << "-";
   }
   else {
       cout << 0;
   }
    

   //function

   // show();
    
    int k;
    cin >> k;
    show_1(k);

   int r = sum(2,3)*sum(5,6);
    cout << r;

    
   // arrays

   double arr[3];
    const int n = 3;
   for (int i=0; i<n; i++){
       cin >> arr[i];

   }
    double res = 0;
    for (int i=0; i<n; i++){
       res += arr[i];

   }
   cout << res;
    */


   

}