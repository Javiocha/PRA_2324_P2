#include <iostream>
#include <vector>
using namespace std;

template <typename T>

int BusquedaBinaria(T X,vector<T>&V, int ini, int fin){
	if(ini>fin){
		cout << "No se encuentra el array" << "\n" << endl;
		return -1;
	}
	int mid = (ini + fin)/2;
	if (V[mid] == X){
		return mid;
	}else if(V[mid] < X){
		return BusquedaBinaria(X,V,mid+1,fin);
	}else if(V[mid]>X){
		return BusquedaBinaria(X,V,ini,mid-1);
	}
}

template <typename T>
int Partition(vector<T> &V, int ini, int fin){
        T X = V[fin];
        T aux;
        int i = ini;
        for(int j=ini; j<fin-1; j++){
                if (V[j] <= X){
                        aux = V[i];
                        V[i] = V[j];
                        V[j] = aux;
                        i++;
                }
                aux = V[i];
                V[i] = V[fin];
                V[fin] = V[aux];
        }
        return i;
}


template <typename T>
void QuickSort(vector<T>&V, int ini, int fin){
	if(ini < fin){
		int pivot = Partition(V, ini, fin);
		QuickSort(V, ini, pivot -1);
		QuickSort(V, pivot +1, fin);
	}
}



