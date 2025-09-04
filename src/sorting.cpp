#include "sorting.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

namespace SortingAlgorithms {
//mingw32-make clean
//mingw32-make all
//./sorting_demo
// mingw32-make test
// TERMINADO
//git add .
// git commit -m "Terminado Hugo"            
// git push 

void bubbleSort(int arr[], int n) {
    int temporal;
    for(int i = 0; i<n-1 ; i++){ // Numero de veces que recorera el arreglo
        for (int j = 1; j<n;j++){
            if (arr[j-1] > arr[j]){
                temporal = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temporal;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for(int j = 0;j<n-1;j++){
        int index_alto = 0;
        for (int i = 0; i<n-j ; i++){
        if (arr[i] >= arr[index_alto]){
            index_alto = i;
            }
        }
        int temporal = arr[(n-j)-1];
        arr[(n-j)-1] = arr[index_alto];
        arr[index_alto] = temporal;
    }
}

void insertionSort(int arr[], int n) {
    int clave; //  A comparar
    int j;
    for (int i = 1; i<n;i++){
        // i = 2
        clave = arr[i]; 
        // Clave = ARR[2]
        j = i - 1;

        while(j >= 0 && arr[j] > clave){
            arr[j+1] = arr[j];
            // ARR[2] = ARR[1]
            j--;
        }
        // ARR[1] = ARR[2] 
        arr[j+1] = clave;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int punto1 = left; // Inicio
    int punto2 = mid+1; // Inicio arreglo 2
    int arr_temp[right - left + 1]; // arreglo temporal
    int p = 0;
    while(punto1 <= mid && punto2 <= right){
        if(arr[punto1] <= arr[punto2]){
            arr_temp[p] = arr[punto1];
            p++;
            punto1++;
        }
        else{
            arr_temp[p] = arr[punto2];
            p++;
            punto2++;
        }
    }

    while (punto1 <= mid){
        arr_temp[p] = arr[punto1];
        p++;
        punto1++;
    }
    while (punto2 <= right){
        arr_temp[p] = arr[punto2];
        p++;
        punto2++;
    }
    
    for (int i = 0 ; i < right - left + 1 ; i++){
        arr[left + i]=arr_temp[i];
    }
}

void mergeSort(int arr[], int left, int right) {
    if(left < right){
        int medio = left+(right-left)/2;
        // Ordenamos a la izquierda
        mergeSort(arr,left,medio);
        // Ordenamos a la derecha
        mergeSort(arr,medio+1,right);

        merge(arr,left,medio,right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1 ;  //indice de los elementos a la izquieda del pivote
    int temporal;
    for (int j = low ; j < high ; j++){
        if(arr[j] <= pivot){
            i++;
            temporal = arr[i];
            arr[i] = arr[j];
            arr[j] = temporal;
        }
    }
    temporal = arr[i+1];
    arr[i+1] = pivot;
    arr[high] = temporal;

    return i+1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Obtenemos el índice del pivote
        int i = partition(arr, low, high);
        // i =  posicion del pivote

        // Ordenamos a la izquierda del pivote
        quickSort(arr, low, i - 1);
        // Ordenamos a la derecha del pivote
        quickSort(arr, i + 1, high);
    }
}

void heapify(int arr[], int n, int i) {
    
}

void heapSort(int arr[], int n) {
    
}

void printArray(int arr[], int n) {
    if (n == 0) {
        std::cout << "[]" << std::endl;
        return;
    }
    
    std::cout << "[";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i < n - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void SortingTimer::start() {
    start_time = std::chrono::high_resolution_clock::now();
}

void SortingTimer::stop() {
    end_time = std::chrono::high_resolution_clock::now();
}

double SortingTimer::getElapsedMilliseconds() const {
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    return duration.count() / 1000.0;
}

std::string SortingTimer::getElapsedTime() const {
    double ms = getElapsedMilliseconds();
    std::stringstream ss;
    
    if (ms < 1.0) {
        ss << std::fixed << std::setprecision(3) << (ms * 1000) << " microseconds";
    } else if (ms < 1000.0) {
        ss << std::fixed << std::setprecision(3) << ms << " ms";
    } else {
        ss << std::fixed << std::setprecision(3) << (ms / 1000.0) << " seconds";
    }
    
    return ss.str();
}

std::vector<int> generateRandomArray(int size, int minVal, int maxVal) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minVal, maxVal);
    
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    
    return arr;
}

std::vector<int> generateSortedArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

std::vector<int> generateReverseSortedArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
    }
    return arr;
}

std::vector<int> generateNearlySortedArray(int size, int swaps) {
    std::vector<int> arr = generateSortedArray(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, size - 1);
    
    for (int i = 0; i < swaps && i < size/2; i++) {
        int idx1 = dis(gen);
        int idx2 = dis(gen);
        std::swap(arr[idx1], arr[idx2]);
    }
    
    return arr;
}

}