#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Statistics {

    vector<int> arr;        
    vector<int> sorted_arr; 
    int size;           
    


public:
    
    Statistics() {
        size = 0;
    }
   
    void inputFromFile(const string& filename) {
        ifstream file(filename); 
        
        if (!file) {
            cout << "Error opening the file." << endl;
            return;
        }
        
        file >> size; 
        arr.resize(size);
        sorted_arr.resize(size);

        
        for (int i = 0; i < size; i++) {
            file >> arr[i];
            sorted_arr[i] = arr[i];
        }

        file.close();
    }
   
    void insertion_sort() { 
        int key;
        for (int i = 1; i < size; i++) {
            key = sorted_arr[i];
            for (int j = i - 1; j >= 0; j--) {
                if (sorted_arr[j] > key) {
                    sorted_arr[j + 1] = sorted_arr[j];
                    sorted_arr[j] = key;
                }
            }
        }
    }

    int getmin() {
        return sorted_arr[0];
    }
    
    int getmax() {
        return sorted_arr[size - 1];
    }
   
    double getmean() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += sorted_arr[i];
        }
        return (double)sum / size;
    }

    double getmedian() {
        if (size % 2 == 1) {
            return sorted_arr[size / 2];  
        } else {
            return (sorted_arr[size / 2 - 1] + sorted_arr[size / 2]) / 2.0;  
        }
    }

    int getsum() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += sorted_arr[i];
        }
        return sum;
    }

    void showMenu() {
        int choice = 0;
        
        while (choice != 6) {  
            cout << "\n--- Statistics Menu ---\n";
            cout << "1. Find Minimum\n";
            cout << "2. Find Maximum\n";
            cout << "3. Find Mean\n";
            cout << "4. Find Median\n";
            cout << "5. Find Summation\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch(choice) {
                case 1:
                    cout << "Minimum: " << getmin() << endl;
                    break;
                case 2:
                    cout << "Maximum: " << getmax() << endl;
                    break;
                case 3:
                    cout << "Mean: " << getmean() << endl;
                    break;
                case 4:
                    cout << "Median: " << getmedian() << endl;
                    break;
                case 5:
                    cout << "Summation: " << getsum() << endl;
                    break;
                case 6:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

int main(){
    string filename;
    
    cout << "Enter the filename: ";
    cin >> filename;

    Statistics stats;
    stats.inputFromFile(filename);
    stats.insertion_sort();
    stats.showMenu();
    
    return 0;
}
