/*
 * Author: Ben Burghardt
 */

#include <chrono>
#include <iostream>
#include <iomanip>

#include "Naive-Stack.hpp"
#include "Improved-Stack.hpp"
using namespace std;

// Function prototypes
double time_n_pushes_improved(unsigned n);
double time_n_pushes_naive(unsigned n);

double time_n_pops_improved(unsigned n);
double time_n_pops_naive(unsigned n);

double time_multi_improved(unsigned n);
double time_multi_naive(unsigned n);

int main (){
    unsigned iterations = 50000;

    cout << "  (ms)   |   Push   |   Pop    |   All 3"    << endl;
    cout << "---------+----------+----------+----------" << endl;\

    cout << "Naive    |";
    cout << fixed << setprecision(4);
    cout << setw(8) << time_n_pushes_naive(iterations) << " |";
    cout << setw(8) << time_n_pops_naive(iterations) << "  |";
    cout << setw(8) << time_multi_naive(iterations) << endl;


    cout << "Improved |";
    cout << setw(8) << time_n_pushes_improved(iterations) << "  |";
    cout << setw(8) << time_n_pops_improved(iterations) << "  |";
    cout << setw(8) << time_multi_improved(iterations) << endl;

    return 0;
}

double time_n_pushes_improved(unsigned n) {
    ImprovedStack<unsigned> s;

    // get starting clock value
    auto start_time = chrono::system_clock::now();
    // do the n pushes
    for (unsigned i = 0; i < n; i++) {
        s.push(i);
    }
    // get ending clock value
    auto stop_time = chrono::system_clock::now();

    // compute elapsed time in microseconds
    auto elapsed = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
    return elapsed.count() / 1000.0;
}

double time_n_pushes_naive(unsigned n){
    NaiveStack<unsigned> s;

    // get starting clock value
    auto start_time = chrono::system_clock::now();
    // do the n pushes
    for (unsigned i = 0; i < n; i++) {
        s.push(i);
    }
    // get ending clock value
    auto stop_time = chrono::system_clock::now();

    // compute elapsed time in microseconds
    auto elapsed = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
    return elapsed.count() / 1000.0;
}


double time_n_pops_improved(unsigned n){
    ImprovedStack<unsigned> s;

    // do n pushes
    for (unsigned i = 0; i < n; i++) {
        s.push(i);
    }
    
    // get starting clock value
    auto start_time = chrono::system_clock::now();

    // do n pops
    for (unsigned i = 0; i < n; i++) {
        s.pop();
    }

    // get ending clock value
    auto stop_time = chrono::system_clock::now();

    // compute elapsed time in microseconds
    auto elapsed = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
    return elapsed.count() / 1000.0;
}
double time_n_pops_naive(unsigned n){
    NaiveStack<unsigned> s;

    // do n pushes
    for (unsigned i = 0; i < n; i++) {
        s.push(i);
    }
    
    // get starting clock value
    auto start_time = chrono::system_clock::now();

    // do n pops
    for (unsigned i = 0; i < n; i++) {
        s.pop();
    }

    // get ending clock value
    auto stop_time = chrono::system_clock::now();

    // compute elapsed time in microseconds
    auto elapsed = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
    return elapsed.count() / 1000.0;
}

double time_multi_improved(unsigned n){
    ImprovedStack<unsigned> s;
    unsigned temp = 0;

    // get starting clock value
    auto start_time = chrono::system_clock::now();
    // do n pushes
    for (unsigned i = 0; i < n; i++) {
        s.push(i);
    }
    // get the top element and pop it
    for (unsigned i = 0; i < n; i++) {
        temp = s.top();
        s.pop();
    }

    // get ending clock value
    auto stop_time = chrono::system_clock::now();

    // compute elapsed time in microseconds
    auto elapsed = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
    return elapsed.count() / 1000.0;
}
double time_multi_naive(unsigned n){
    NaiveStack<unsigned> s;
    unsigned temp = 0;

    // get starting clock value
    auto start_time = chrono::system_clock::now();
    // do n pushes
    for (unsigned i = 0; i < n; i++) {
        s.push(i);
    }
    // get the top element and pop it
    for (unsigned i = 0; i < n; i++) {
        temp = s.top();
        s.pop();
    }

    // get ending clock value
    auto stop_time = chrono::system_clock::now();

    // compute elapsed time in microseconds
    auto elapsed = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
    return elapsed.count() / 1000.0;
}