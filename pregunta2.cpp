#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;



int main() {
    int max = 1000;
    vector<vector<int>> A(max, vector<int>(max));
    vector<vector<int>> B(max, vector<int>(max));
    vector<vector<int>> C(max, vector<int>(max));
    int c = 0;
    for (int i = 0; i < max; i++)
        for (int j = 0; j < max; j++) {
            A[i][j] = (i + j) % 10;
            B[i][j] = (i * j) % 10;
        }

    auto start = high_resolution_clock::now();
    
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            C[i][j] = 0;
            for (int k = 0; k < max; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }


    auto end = high_resolution_clock::now();

    cout << "Tiempo: " << duration_cast<milliseconds>(end - start).count() << endl;
    return 0;
}