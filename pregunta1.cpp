#include <iostream>
#include <vector>

#include <chrono>
using namespace std;
using namespace std::chrono;

const int MAX = 10000; 


int main() {
    vector<vector<double>> A(MAX, vector<double>(MAX));
    vector<double> x(MAX), y(MAX,0.0);

    float c = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            A[i][j] = c;
            c++;
        }
        x[i] = c*2;
    }

    // Primer bucle
    auto start1 = high_resolution_clock::now();
    for (int i = 0; i < MAX; i++) { 
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    auto end1 = high_resolution_clock::now();
    cout << "Tiempo bucle 1: " << duration_cast<milliseconds>(end1 - start1).count() << endl;

    // Reiniciar "y"

    for (int i = 0; i < MAX; i++) {
        y[i] = 1;
    }

    // Segundo bucle 
    auto start2 = high_resolution_clock::now();
    
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
    auto end2 = high_resolution_clock::now();
    cout << "Tiempo bucle 2: " 
         << duration_cast<milliseconds>(end2 - start2).count() << endl;

    return 0;
}
