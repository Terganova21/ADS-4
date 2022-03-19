// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int chet = 0;
    for (int k = 0; k < len - 1; k++)
        for (int i = k + 1; i < len; i++)
            if (arr[k] + arr[i] == value) {
                chet++;
            }
    return chet;
}
void Sort1(int* arr, int l, int h) {
    int i = l;
    int j = h;
    int cen = arr[(i + j) / 2];
    int num;

    while (i <= j) {
        while (arr[i] < cen)
            i++;
        while (arr[j] > cen)
            j--;
        if (i <= j) {
            num = arr[i];
            arr[i] = arr[j];
            arr[j] = num;
            i++;
            j--;
        }
    }
    if (j > l)
        Sort1(arr, l, j);
    if (i < h)
        Sort1(arr, i, h);
}
int bin(int* arr, int left, int right, int value) {
    if (right >= left) {
        int cen = left + (right - left) / 2;
        if (arr[cen] == value)
            return bin(arr, left, cen - 1, value)
            + bin(arr, cen + 1, right, value) + 1;
        if (arr[cen] > value)
            return bin(arr, left, cen - 1, value);
        return bin(arr, cen + 1, right, value);
    }
    return 0;
}
int countPairs2(int *arr, int len, int value) {
  Sort1(arr, 0, len - 1);
    int chet = 0;
    for (int i = 0; i < len; i++) {
        for (int j = len - 1; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                chet++;
            }
        }
    }
    return chet;
}
int countPairs3(int *arr, int len, int value) {
  Sort1(arr, 0, len - 1);
    int chet = 0;
    for (int i = 0; i < len; i++) {
        chet += bin(&arr[i + 1], 0, len - i, value - arr[i]);
    }
    return chet;
}
