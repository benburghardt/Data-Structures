#include <chrono>
//#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include <vector>
//#include "Node.h"
// #include "stack-optimized.h"
#include "Naive-Stack.hpp"
#include "Improved-Stack.hpp"


using namespace std;

//double time_n_pushes(unsigned n);
double time_n_ksorts(vector<int>, int k);

int main (){

    srand(time(0));
    rand();
    ofstream data("sortData.csv");
    data << "k,n,time\n";
    vector<int>* list;
    int ks[] = {2,3,5,10,50,100,200,500};
    int sizes[] = {100000,200000,300000,400000,500000,700000,1000000};
    //bool con(true);
    //while (con){
        /*cout << "How many elements do you want to add: ";
        cin >> size;
        cout << endl;*/
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 7; j++){
                
                //double count = 0;
                double time;
                for(int k = 0; k < 30; k++){

                    data << ks[i] << "," << sizes[j] << ",";

                    list = new vector<int>(sizes[j]);
                    for(int l = 0; l < sizes[j]; l++){
                        list->at(l) = rand();
                    }

                    time = time_n_ksorts(*list,ks[i]);
                    data << time*1000 << "\n";
                    
                    //count += time;
                    delete list;
                }

                //count = count * 1000 /10;
                //cout << "Average time for sorting " << sizes[j] << " with " << ks[i] << "-way merge sort is " << count << endl;

            }
        }
        /*vector<int>* list;
        int sz = 27;

        list = new vector<int>(1156);
        for(int l = 0; l < 1156; l++){
            list->at(l) = rand();
        }
        time_n_ksorts(*list,sz);*/
        
        /*cout << "Do you want to continue: ";
        char check;
        cin >> check;
        if(check == 'Y' || check == 'y'){
            con = true;
        }
        else{
            con = false;
        }
        

    }*/
    data.close();

    return 0;
}

/*double time_n_pushes(unsigned n) {
    stack<unsigned> s;

    // get starting clock value
    auto start_time = chrono::system_clock::now();
    // do the n pushes
    for (unsigned i = 0; i < n; i++) {
        s.push(i);
    }
    // get ending clock value
    auto stop_time = chrono::system_clock::now();

    // compute elapsed time in seconds
    chrono::duration<double> elapsed = stop_time - start_time;
    return elapsed.count();
}*/

double time_n_ksorts(vector<int> nums, int k) {

    // get starting clock value
    auto start_time = chrono::system_clock::now();
    // do the sort
    // sorter(nums,k);
    nums.at(0) += k;
    // get ending clock value
    auto stop_time = chrono::system_clock::now();

    // compute elapsed time in seconds
    chrono::duration<double> elapsed = stop_time - start_time;
    return elapsed.count();
}