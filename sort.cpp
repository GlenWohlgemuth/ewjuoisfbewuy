// Glen Wohlgemuth - 12588377



// libraries
#include<iostream>
#include<vector>


using namespace std;


// Functions


// Fizz Buzz helper funcs
bool isFizz(int num){
    return num % 3 == 0 && num % 5 != 0;
}

bool isBuzz(int num){
    return num % 5 == 0 && num % 3 != 0;
}

bool isFizzBuzz(int num){
    return num % 5 == 0 && num % 3 == 0;
}


// Swap() for reduced redundancy
void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;

    return;
}


// quickSort FUNCS

// quickSort function statistics
int static quickSortSwaps = 0;
int static fizzCount = 0, buzzCount = 0, fizzBuzzCount = 0;

// quickSort Helper func
// 
int partition(vector<int>& array, int start, int end){
    int pivot = array[end];
    int i = start - 1;
    int product;

    for(int j = start; j <= end - 1; ++j){
        if(array[j] < pivot){
            ++i;
            //Debug
            
            // output statistics
            ++quickSortSwaps; 
            product = array[i] * array[j];
            if(isFizz(product)) ++fizzCount;
            if(isBuzz(product)) ++buzzCount;
            if(isFizzBuzz(product)) ++fizzBuzzCount;
            cout << quickSortSwaps << " " << fizzCount << " " << buzzCount << " " << fizzBuzzCount << endl;
            cout << "Swapped: " << array[i]<< " " << array[j] << endl;
            cout << "Product: " << array[i] * array[j] << endl << endl; // DEBUG
            swap(array[i], array[j]);
            for (int i = 0; i < array.size(); ++i){
                cout << array[i] << " ";
            }
            cout << endl;
            product = 0;
        }
    }
    ++i;
    
    //cout << "Swapping indicies " << i << " and " << end << endl; // DEBUG

    // DEBUG //
    
    ++quickSortSwaps;
    product = array[i] * array[end];
    if(isFizz(product)) ++fizzCount;
    if(isBuzz(product)) ++buzzCount;
    if(isFizzBuzz(product)) ++fizzBuzzCount;
    cout << quickSortSwaps << " " << fizzCount << " " << buzzCount << " " << fizzBuzzCount << endl; // DEBUG
    cout << "Swapped: " << array[i]<< " " << array[end] << endl;
    cout << "Product: " << array[i] * array[end] << endl << endl; // DEBUG
    swap(array[i], array[end]);

    for (int i = 0; i < array.size(); ++i){
        cout << array[i] << " ";
    }
    cout << endl;

    return i; // pivot index
}

// quickSort main
void quickSort(vector<int>& array, int start, int end){

    if (start < end) {
      

        int pi = partition(array, start, end);

        quickSort(array, start, pi - 1);
        quickSort(array, pi + 1, end);
    }

    /*
    if(end <= start) {return;} // base case

    int pivot = partition(array, start, end);
    quickSort(array, start, pivot - 1);
    quickSort(array, pivot + 1, end);
    */
}








// main function
int main(){
    int n;
    cin >> n;

    vector<int> Numbers(n);

    // Collect input and store into 'Numbers' vector
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        Numbers[i] = num;
    }


    // DEBUG //
    for (int i = 0; i < Numbers.size(); ++i){
        cout << Numbers[i] << " ";
    }
    cout << endl;


    // function calls
    quickSort(Numbers, 0, Numbers.size() - 1);


    // Output to terminal
    cout << quickSortSwaps << " " << fizzCount << " " << buzzCount << " " << fizzBuzzCount << endl;


    return 0;
}



