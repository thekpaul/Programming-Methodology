#include <iostream>
#include <time.h>
using namespace std;

//O(n^3) algorithm
int max_sum1(int* arr, int arrsize) {
    int maxSum = 0;
    for (int i = 0; i < arrsize; i++) {
        for (int j = i; j< arrsize; j++) {
            int thisSum = 0;
            for (int k = i; k <= j; k++) thisSum += arr[k];
            if (maxSum < thisSum) maxSum = thisSum;
        }
    } return maxSum;
}

//O(n^2) algorithm
int max_sum2(int* arr, int arrsize) {
    int maxSum = 0;
    for (int i = 0; i < arrsize; i++) {
        int iSum = 0;
        for (int j = i; j < arrsize; j++) {
            iSum += arr[j];
            if (maxSum < iSum) maxSum = iSum;
        }
    } return maxSum;
}

//O(nlogn) algorithm
int max_sum3(int* arr, int left, int right) {
    if (left >= right) return arr[left];
    else { int hereMax = 0;
        int leftSum = max_sum3(arr, left, ((left + right) / 2) - 1);
        int rightSum = max_sum3(arr, ((left + right) / 2) + 1, right);
        if (leftSum >= rightSum) hereMax = leftSum;
        else hereMax = rightSum;
        int leftMax = arr[(left + right) / 2], leftTemp = 0;
        int rightMax = arr[(left + right) / 2], rightTemp = 0;
        for (int i = (left + right) / 2; i >= left; i--) {
            leftTemp += arr[i];
            if (leftMax < leftTemp) leftMax = leftTemp;
        } for (int i = (left + right) / 2; i <= right; i++) {
            rightTemp += arr[i];
            if (rightMax < rightTemp) rightMax = rightTemp;
        } int midSum = leftMax + rightMax - arr[(left + right) / 2];
        if (hereMax < midSum) hereMax = midSum;
        return hereMax;
    }
}

//O(n) algorithm, using for loop
int max_sum4(int* arr, int arrsize) {
    int maxSum = arr[0], thisSum = 0;
    for (int i = 0; i < arrsize; i++) {
        thisSum += arr[i];
        if (thisSum > maxSum) maxSum = thisSum;
        else if (thisSum < 0) thisSum = 0;
    }  return maxSum;
}

//O(n) algorithm, using recursion
int max_sum5(int * arr, int end, int& this_sum ) {
    static int maxSum = 0;
    if (end < 0) return maxSum;
    else { this_sum += arr[end];
        if (maxSum < this_sum) maxSum = this_sum;
        else if (this_sum < 0) this_sum = 0;
        return max_sum5(arr, end - 1, this_sum);
    }
}

int main() {
    const int arrsize = 2500; //Change the size of the array
    const int range = 100;
    int* arr = new int[arrsize];
    double m_ratio = 0.5; //Change the ratio of negative numbers

    srand((unsigned int)time(NULL));
    for (int i = 0; i < arrsize; i++) {
        arr[i] = rand() % range - int(m_ratio*range);
    }

    int sum1, sum2, sum3, sum4, sum5, this_sum = 0;
    clock_t begin, end;

    begin = clock();
    sum1 = max_sum1(arr, arrsize);
    end = clock();
    cout << "O(n^3) algorithm\n" << "Max sum : " << sum1 << endl;
    cout << "Elapsed time : " << (end - begin) << endl;

    begin = clock();
    sum2 = max_sum2(arr, arrsize);
    end = clock();
    cout << "O(n^2) algorithm\n" << "Max sum : " << sum2 << endl;
    cout << "Elapsed time : " << (end - begin) << endl;

    begin = clock();
    sum3 = max_sum3(arr, 0, arrsize-1);
    end = clock();
    cout << "O(nlogn) algorithm\n" << "Max sum : " << sum3 << endl;
    cout << "Elapsed time : " << (end - begin) << endl;

    begin = clock();
    sum4 = max_sum4(arr, arrsize);
    end = clock();
    cout << "O(n) algorithm\n" << "Max sum : " << sum4 << endl;
    cout << "Elapsed time : " << (end - begin) << endl;

    sum5 = max_sum5(arr, arrsize - 1, this_sum);
    cout << "O(n) recursion algorithm\n" << "Max sum : " << sum5 << endl;
    return 0;
}
