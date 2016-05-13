// dynamic programming in Introduction to Algorithm
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int Max(int a, int b) {
	return a > b ? a : b;
}

int cut(int* arr, int left) {
	int max = 0;
	if (left == 0) {
		return 0;
	}
	for (int i = 0; i < left; i++) {
		max = Max(max, arr[i] + cut(arr, left - i - 1));
	}	
	return max;
}
int memorized_cut_rod_aux(int* price, int left, int* arr) {
	int max = 0;
	if (left == 0)
		return 0;
	if (arr[left - 1] >= 0)
		return arr[left - 1];
	else {
		for (int i = 0; i < left; i++) {
			max = Max(max, price[i] + memorized_cut_rod_aux(price, left - i - 1, arr));
		}
	}
	arr[left - 1] = max;
	return max;
}
int memorized_cut_rod(int* price, int left, int* arr) {
	int max = memorized_cut_rod_aux(price, left, arr);
	return max;
}

int bottom_up_cut(int* price, int left, int* arr) {
	arr[0] = 0;
	int max = -1;
	for (int i = 1; i <= left; i++) {
		for (int j = 1; j <= i; j++) {
			max = Max(max, price[j - 1] + arr[i - j]);
		}
		arr[i] = max;
	}
	return max;
}

int main()
{
	const int n = 10;
	int price[n] = { 1,5,8,9,10,17,17,20,24,30 };
	int arr[n + 1];
	for (int i = 0; i < 11; i++)
		arr[i] = -1;
	int result = bottom_up_cut(price, 4, arr);
	cout << result << endl;
	system("pause");
    return 0;
}

