#include <iostream>
//#include "libutils/io.h"
using namespace std;

void selection(int* a, int n) {
	if (n == 0 || n == 1)return;
	for (int i = 0; i < n - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < n; ++j) {
			if (a[j] < a[min])min = j;
		}
		int tmp = a[i];
		a[i] = a[min];
		a[min] = tmp;
	}
}

void babbleSort(int* a, int n) {
	if (n == 0 || n == 1)return;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - 1 - i; ++j) {
			if (a[j] > a[j + 1]) {
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

void shellSort(int* a, int n) {
	if (n == 0 || n == 1)return;
	int d = n / 2;
	while (d > 0) {
		for (int i = 0; i < n - d; ++i) {
			int j = i;
			while (j >= 0 && a[j] > a[j + d]) {
				int tmp = a[j];
				a[j] = a[j + d];
				a[j + d] = tmp;
				--j;
			}
		}
		d = d / 2;
	}
}

void quickSort(int* a, int n) {
	if (n == 0 || n == 1)return;
	int mid = a[0];
	int f = 0, l = n-1;
	while (f < l) {
		while (a[f] < mid)++f;
		while (a[l] > mid)--l;
		if (f <= l) {
			int tmp = a[f];
			a[f] = a[l];
			a[l] = tmp;
			++f;
			--l;
		}
	} 
	if (0 < l) quickSort(a, l+1);
	if (f < n)quickSort(&a[f], n-f);
}

void MergeSort(int* arr, int size) {
	int* b = new int[size];
	int j = 0, n = 1, k = size - 1, w = 0, t = size - 1, u = 0;
	int p = 0, q = size - 1;
	bool flag = false;
	while (flag != true) {
		flag = true;
		while (p <= q) {
			if (n % 2 != 0) j = u;
			if (n % 2 == 0)j = k;
			if (p == q) {
				b[j] = arr[p];
				if (n % 2 != 0)++j;
				if (n % 2 == 0)--j;
			}
			else {
				for (int i = w; i < size; ++i) {
					if (arr[i] <= arr[i + 1])++w;
					else  break;
				}
				for (int i = t; i >= 0; --i) {
					if (arr[i] <= arr[i - 1])--t;
					else  break;
				}
				while (q > t || p < w) {
					bool h = false;
					if (arr[p] >= arr[q] && q >= t) {
						b[j] = arr[q];
						if (n % 2 != 0)++j;
						if (n % 2 == 0)--j;
						--q;
						h = true;
					}
					if (arr[p] >= arr[q] && q < t && h == false) {
						b[j] = arr[p];
						if (n % 2 != 0)++j;
						if (n % 2 == 0)--j;
						++p;
					}
					h = false;
					if (arr[p] <= arr[q] && p <= w) {
						b[j] = arr[p];
						if (n % 2 != 0)++j;
						if (n % 2 == 0)--j;
						++p;
						h = true;
					}
					if (arr[p] <= arr[q] && p > w && h == false) {
						b[j] = arr[q];
						if (n % 2 != 0)++j;
						if (n % 2 == 0)--j;
						--q;
					}
					h = false;
				}
				if (p == q) {
					b[j] = arr[p];
					if (n % 2 != 0)++j;
					if (n % 2 == 0)--j;
				}
				if (p < q) {
					if (arr[p] <= arr[q]) {
						if (p == w) {
							b[j] = arr[p];
							if (n % 2 != 0)++j;
							if (n % 2 == 0)--j;
						}
						if (q == t) {
							b[j] = arr[q];
							if (n % 2 != 0)++j;
							if (n % 2 == 0)--j;
						}
					}
					else {
						if (q == t) {
							b[j] = arr[q];
							if (n % 2 != 0)++j;
							if (n % 2 == 0)--j;
						}
						if (p == w) {
							b[j] = arr[p];
							if (n % 2 != 0)++j;
							if (n % 2 == 0)--j;
						}
					}
				}
			}
			if (q == t)--q;
			if (p == w)++p;
			++w;
			--t;
			if (n % 2 != 0)u = j;
			if (n % 2 == 0)k = j;
			++n;
		}
		for (int i = 0; i < size; ++i) {
			arr[i] = b[i];
		}
		for (int i = 0; i < size - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				flag = false;
				u = 0;
				n = 1;
				k = size - 1;
				p = 0;
				w = 0;
				t = size - 1;
				q = size - 1;
				break;
			}
		}
	}
	delete[]b;
}

int main() {
	//int a[9] = { 9, 20,1,6,12,3,54,7,43 };
	//int a[4] = { 37, 2, 4, 43};
	int a[16] = { 1, 2, 60, 7, 12, 5, 7, 4, 9, 3, 11, 15, 8, 6, 3, 1 };
	//selection(a, 16);
	//babbleSort(a, 16);
	//shellSort(a, 16);
	quickSort(a, 16);
	//MergeSort(a, 16);
	for (int i = 0; i < 16; ++i) {
		cout << a[i] << ' ';
	}
	
}