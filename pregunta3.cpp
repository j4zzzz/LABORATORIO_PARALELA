#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;



int main() {
    int max = 1000;
    int tam_bloque = 100;
    vector<vector<int>> A(max, vector<int>(max));
    vector<vector<int>> B(max, vector<int>(max));
    vector<vector<int>> C(max, vector<int>(max));
    int c = 0;
    for (int i = 0; i < max; i++){
        for (int j = 0; j < max; j++) {
            A[i][j] = c;
            B[i][j] = c*2;
            c++;
        }
    }

    auto start = high_resolution_clock::now();
    
    for (int blq_i = 0; blq_i < max; blq_i += tam_bloque) {
        for (int blq_j = 0; blq_j < max; blq_j += tam_bloque) {
            for (int blq_k = 0; blq_k < max; blq_k += tam_bloque) {
                
                // Límites del bloque actual
                int fin_i = min(blq_i + tam_bloque, max);
                int fin_j = min(blq_j + tam_bloque, max);
                int fin_k = min(blq_k + tam_bloque, max);
                
                // Procesar bloque
                for (int i = blq_i; i < fin_i; i++) {
                    for (int j = blq_j; j < fin_j; j++) {
                        double suma_parcial = C[i][j];
                        
                        for (int k = blq_k; k < fin_k; k++) {
                            suma_parcial += A[i][k] * B[k][j];
                        }
                        
                        C[i][j] = suma_parcial;
                    }
                }
            }
        }
    }

    auto end = high_resolution_clock::now();

    cout << "Tiempo: " << duration_cast<milliseconds>(end - start).count() << endl;
    return 0;
}