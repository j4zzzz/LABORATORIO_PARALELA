#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;



int main() {
    int max = 1000;
    int current = 100;
    vector<vector<int>> A(max, vector<int>(max));
    vector<vector<int>> B(max, vector<int>(max));
    vector<vector<int>> C(max, vector<int>(max));
    int c = 0;
    for (int i = 0; i < max; i++){
        for (int j = 0; j < max; j++) {
            A[i][j] = (i + j) % 10;
            B[i][j] = (i * j) % 10;
        }
    }

    auto start = high_resolution_clock::now();
    
    for (int ii = 0; ii < max; ii += current) {
        for (int jj = 0; jj < max; jj += current) {
            for (int kk = 0; kk < max; kk += current) {
                for (int i = ii; i < min(ii + current, max); i++) {
                    for (int j = jj; j < min(jj + current, max); j++) {
                        double sum = C[i][j];
                        for (int k = kk; k < min(kk + current, max); k++) {
                            sum += A[i][k] * B[k][j];
                        }
                        C[i][j] = sum;
                    }
                }
            }
        }
    }


    auto end = high_resolution_clock::now();

    cout << "Tiempo: " << duration_cast<milliseconds>(end - start).count() << endl;
    return 0;
}