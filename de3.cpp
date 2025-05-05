#include <iostream>
#include <ctime>
using namespace std;

// === Nhập mảng A đệ quy ===
void nhapMangDeQuy(int* A, int n, int i = 0) {
    if (i == n) return;
    cout << "A[" << i << "] = ";
    cin >> A[i];
    nhapMangDeQuy(A, n, i + 1);
}

// === Xuất mảng A ===
void xuatMang(int* A, int n) {
    cout << "Mang A: ";
    for (int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << endl;
}

// === Tìm vị trí giá trị nhỏ nhất đệ quy ===
int viTriMin(int* A, int n, int i = 0, int minIdx = 0) {
    if (i == n) return minIdx;
    if (A[i] < A[minIdx]) minIdx = i;
    return viTriMin(A, n, i + 1, minIdx);
}

// === Tìm vị trí giá trị lớn nhất đệ quy ===
int viTriMax(int* A, int n, int i = 0, int maxIdx = 0) {
    if (i == n) return maxIdx;
    if (A[i] > A[maxIdx]) maxIdx = i;
    return viTriMax(A, n, i + 1, maxIdx);
}

// === Hoán đổi giá trị ===
void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

// === Tạo mảng 2D M với giá trị ngẫu nhiên không trùng ===
void taoMangNgauNhienKhongTrung(int** M, int r, int c, int minVal = 10, int maxVal = 559) {
    int size = r * c;
    int range = maxVal - minVal + 1;
    if (size > range) {
        cout << "Khong du gia tri khac nhau trong [" << minVal << ", " << maxVal << "]\n";
        return;
    }

    int* temp = new int[range];
    for (int i = 0; i < range; ++i)
        temp[i] = minVal + i;

    for (int i = 0; i < range; ++i) {
        int j = rand() % range;
        swap(temp[i], temp[j]);
    }

    int index = 0;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            M[i][j] = temp[index++];

    delete[] temp;
}

// === Xuất mảng 2 chiều M ===
void xuatMang2Chieu(int** M, int r, int c) {
    cout << "Ma tran M:\n";
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
            cout << M[i][j] << "\t";
        cout << endl;
    }
}

// === Tính trung bình từng hàng ===
void tinhTrungBinhTungHang(int** M, int r, int c) {
    cout << "\nTrung binh moi hang:\n";
    for (int i = 0; i < r; ++i) {
        int tong = 0;
        for (int j = 0; j < c; ++j)
            tong += M[i][j];
        float tb = (float)tong / c;
        cout << "Hang " << i << ": " << tb << endl;
    }
}

// === Đảo ngược mảng theo hàng ===
void daoNguocTheoHang(int** M, int r, int c) {
    for (int i = 0; i < r / 2; ++i)
        for (int j = 0; j < c; ++j)
            swap(M[i][j], M[r - 1 - i][j]);
}

// === MAIN ===
int main() {
    srand(time(0)); // seed random

    // a) Mảng 1 chiều A
    int n;
    cout << "Nhap so phan tu cua mang A: ";
    cin >> n;
    int* A = new int[n];
    nhapMangDeQuy(A, n);
    xuatMang(A, n);

    // b) Tìm min/max đệ quy
    int minPos = viTriMin(A, n);
    int maxPos = viTriMax(A, n);
    cout << "Vi tri gia tri nho nhat: " << minPos << " (A[" << minPos << "] = " << A[minPos] << ")\n";
    cout << "Vi tri gia tri lon nhat: " << maxPos << " (A[" << maxPos << "] = " << A[maxPos] << ")\n";
    delete[] A;

    // c) Mảng 2 chiều M với số ngẫu nhiên không trùng
    int r, c;
    cout << "\nNhap so hang M: "; cin >> r;
    cout << "Nhap so cot M: "; cin >> c;

    int** M = new int*[r];
    for (int i = 0; i < r; ++i)
        M[i] = new int[c];

    taoMangNgauNhienKhongTrung(M, r, c);
    xuatMang2Chieu(M, r, c);

    // d) Trung bình mỗi hàng
    tinhTrungBinhTungHang(M, r, c);

    // e) Đảo ngược theo hàng
    daoNguocTheoHang(M, r, c);
    cout << "\nMa tran M sau khi dao nguoc theo hang:\n";
    xuatMang2Chieu(M, r, c);

    // Giải phóng
    for (int i = 0; i < r; ++i)
        delete[] M[i];
    delete[] M;

    return 0;
}
