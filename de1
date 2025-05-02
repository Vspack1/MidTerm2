#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

void taoMangNgauNhien(int** &M, int r, int c) {
    srand(time(0));
    int tong;
    do {
        tong = 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j) {
                M[i][j] = rand() % 550 + 10;
                tong += M[i][j];
            }
    } while (!laSoNguyenTo(tong));
}

void timX(int** M, int r, int c, int x) {
    bool found = false;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (M[i][j] == x) {
                cout << "Tim thay tai dong " << i << ", cot " << j << endl;
                found = true;
            }
    if (!found)
        cout << "Khong tim thay x\n";
}

void kyPhapDoiDoi(int* A, int n) {
    for (int i = 0; i < n / 2; ++i)
        swap(A[i], A[n - 1 - i]);
}

int timMangATrongM(int** M, int r, int c, int* A, int n) {
    if (r != n) return -1;
    for (int j = 0; j < c; ++j) {
        bool match = true;
        for (int i = 0; i < r; ++i)
            if (M[i][j] != A[i]) {
                match = false;
                break;
            }
        if (match) return j;
    }
    return -1;
}

int main() {
    int r, c, n, x;
    cout << "Nhap so hang va cot cua M: ";
    cin >> r >> c;

    int** M = new int*[r];
    for (int i = 0; i < r; ++i)
        M[i] = new int[c];

    taoMangNgauNhien(M, r, c);

    cout << "Ma tran M:\n";
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
            cout << M[i][j] << "\t";
        cout << endl;
    }

    cout << "Nhap so nguyen x can tim: ";
    cin >> x;
    timX(M, r, c, x);

    cout << "Nhap so phan tu mang A: ";
    cin >> n;
    int* A = new int[n];
    cout << "Nhap mang A:\n";
    for (int i = 0; i < n; ++i) cin >> A[i];

    kyPhapDoiDoi(A, n);

    cout << "Mang A sau khi doi doi: ";
    for (int i = 0; i < n; ++i) cout << A[i] << " ";
    cout << endl;

    int kq = timMangATrongM(M, r, c, A, n);
    if (kq == -1)
        cout << "Khong tim thay mang A trong M\n";
    else
        cout << "Mang A xuat hien o cot " << kq << " trong M\n";

    for (int i = 0; i < r; ++i) delete[] M[i];
    delete[] M;
    delete[] A;
    return 0;
}
