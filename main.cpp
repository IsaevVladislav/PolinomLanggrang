#include <iostream>
#include <conio.h>
using namespace std;
 
double my_lagrange(double x, int n, double x_arr[], double y_arr[]);
 
int main()
{
 
    int n = 5;
 
    double x_arr[5] = { -2, -1, 1.2, 3.5, 5};
    double y_arr[5] = { -4, 0, 3.8, -2, 7};
 
 
    for (double x = -2; x <= 5; x += 0.5){
        cout << "f(" << x << ") = "
            << my_lagrange(x, n, x_arr, y_arr) << endl;
 
    }
 
    getchar();
    return 0;
}
 
double my_lagrange(double x, int n, double x_arr[], double y_arr[]){
    //Пусть точки отсортированы по возрастанию координаты x
    
    if (n > 5)
        return (x <= x_arr[n/2]) ? my_lagrange(x, (n + 1)/2, x_arr, y_arr) : 
                                   my_lagrange(x, (n + 1)/2, &x_arr[n/2], &y_arr[n/2]);
    
    double sum = 0;
    for (int i = 0; i < n; ++i){
        
        double l = 1;
        for (int j = 0; j < n; ++j)
            if (j != i)
                l *= (x - x_arr[j]) / (x_arr[i] - x_arr[j]);
        sum += y_arr[i] * l;
    }
    
    return sum;
}

