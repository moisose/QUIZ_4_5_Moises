/*
Quiz 4 y 5
Moisés Solano Espinoza
2021144322
Análisis de Algoritmos
*/

#include <iostream>
#include <cmath>
#include <list>

using namespace std;

int costo(int N, int M, int x[], int y[]) {
    int costo1 = 0; // primero horizontal  +1
    int costo2 = 0; // primero vertical    +1

    int maximo;
    N > M ? maximo = N : maximo = M; // +2

    for (int i = 0; i < maximo; i++){ // +1 +(3
        if(i < N-1){ // +2
            costo1 += y[i]; // +3          
            costo2 += y[i] * M; // +4
        }

        if(i < M-1){ // +2
            costo1 += x[i] * N; // +4
            costo2 += x[i]; // +3
        }
    }
    if(costo1 < costo2) // +1
        return costo1; // +1
    return costo2; // +1
}


/*
1+1+2+1+(3+2+3+4+2+4+3)n +2
= 5 +(21)n +2
= 21n + 7
f(n) = 21n + 7

O(n)

Loop invariant: (costo1/(costo2 + 1)) < maximo

*/

// -------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------

void radixSort(int *arr, int n, int max) { // +3

    int i, j, m, p = 1, index, temp, count = 0; // +2
    list<int> pocket[10];      //radix of decimal number is 10   +1

    for(i = 0; i < max; i++) { // +1 (+1 +2)
        m = pow(10, i+1); // +1 +2 +1 +2 = 6
        p = pow(10, i); // +1 +2 +2 = 5
        
        for(j = 0; j<n; j++) { // +1 (+1 +2)
            temp = arr[j]%m; // 
            index = temp/p;      //find index for pocket array // +2
            pocket[index].push_back(arr[j]); // +5
        }
        count = 0; // +1
      
        for(j = 0; j<10; j++) { // +1 (+1 +2)
         //delete from linked lists and store to array
            while(!pocket[j].empty()) { // +4
                arr[count] = *(pocket[j].begin()); // +5
                pocket[j].erase(pocket[j].begin()); // +7
                count++; // +2
            }
        }
    }
}



/*
k = max
n = lenght

= 2+1+1+ [1+2+6+5+1+(1+2+3+2+5)n +1+1+ [1+2+ (4+5+7+2)n]10]k
= 4 + [15+13n+2+(3+18n)10]k
= 4 + k(15+13n+2+30+180n)
= 4 + k(47+193n)
= 4 + 47k + 193kn

= c1 + c2k + c3kn
=> k + kn
=> k (1+n)
=> kn

O(kn)

Loop invariant: "todos los números en arr[1..n] van a estar 
                ordenados del 1..i-1 digitos menos significativos."

Nota: con números menos significativos se hace referencia en ir recorriendo
      de derecha a izquierda.
      Los dos puntos ".." significan "al"
*/

void pintar (int *arr, int n){
    cout << "{";
    for (int i=0; i < n; i++){
        cout << arr[i] << ", ";
    }
    cout << "}" << endl;
}


int main(){

    cout << "Pruebas" << endl;
    cout << "-------------------------------------" << endl;
    cout << "--------Costo Chocolate--------------" << endl;
    cout << "-------------------------------------" << endl;
    cout << "   -> f(n) = 21n + 7" << endl;
    cout << "   -> O(n)\n" << endl;
    cout << "X: {5,20,13,3,9}"<<endl;
    cout << "Y: {6,2,7}"<<endl;
    cout << "N = 4; M = 6" << endl;

    int h[5] = {5,20,13,3,9};
    int v[3] = {6,2,7};

    cout<< "El menor costo es: "<< costo(4,6,h,v) << endl;


    cout << "-------------------------------------" << endl;
    cout << "-------------Radix Sort--------------" << endl;
    cout << "-------------------------------------" << endl;
    cout << "   -> f(n) = 4 + 47k + 193kn" << endl;
    cout << "   -> O(kn)\n" << endl;
    cout << "Lista: {2,5,1,10,3,27,63}; n = 7; max = 2" << endl;

    int list[7]= {2,5,1,10,3,27,63};

    radixSort(list, 7, 2);

    cout << "Lista ordenada: " << endl;
    pintar(list, 7);

    return 0;
}