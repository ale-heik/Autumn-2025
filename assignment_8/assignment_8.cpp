#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

// Utility function to calculate the factorial of a number
long long factorial(int num) {
    long long fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate the sum of factorials in a range asynchronously
long long sumFactorialsAsync(int start, int end) {
    long long sum = 0;
    for (int i = start; i <= end; i++) {
        sum += factorial(i);
    }
    return sum;
}

// Utility function to calculate the factorial of a number
long long factorial2(int num) {
    long long fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate the sum of factorials in a range asynchronously
long long sumFactorialsdeferred(int start, int end) {
    long long sum = 0;
    for (int i = start; i <= end; i++) {
        sum += factorial(i);
    }
    return sum;
}


int main() {
    cout << "launch::async" << endl;
    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::duration;
    using chrono::milliseconds;

    int start = 1;
    int end = 10;

    // Calculate the sum of factorials asynchronously and recording execution time
    auto t1 = high_resolution_clock::now();
    auto future1 = async(launch::async, sumFactorialsAsync, start, end);
 

    // Wait for the result of the asynchronous calculation
    auto result = future1.get();
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as a double. */
    duration<double, milli> ms_double = t2 - t1;

    cout << "Sum of factorials from " << start <<  "to " << end << " is: " << result << endl;
    cout << ms_double.count() << "ms\n";


    //------------------------------------------------------------------------------------------


    cout << "launch::deferred" << endl;

    int start2 = 1;
    int end2 = 10;

    // Calculate the sum of factorials asynchronously and recording execution time
    auto t3 = high_resolution_clock::now();
    auto future2 = async(launch::deferred, sumFactorialsdeferred, start2, end2);

    // Wait for the result of the asynchronous calculation
    auto result2 = future2.get();
    auto t4 = high_resolution_clock::now();

    /* Getting number of milliseconds as a double. */
    duration<double, milli> ms_double2 = t4 - t3;

    cout << "Sum of factorials from " << start2 << "to " << end2 << " is: " << result2 << endl;
    cout << "Execution time of launch::deferred" << ms_double2.count() << "ms\n";

    return 0;
}


/* Report

std::launch::async takes longer time to execute


std::launch::deferred is lot faster so I would prefer that one if you need fast calculations

*/