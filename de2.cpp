bool laSoDoiXung(int n) {
    int dao = 0, tmp = n;
    while (tmp > 0) {
        dao = dao * 10 + tmp % 10;
        tmp /= 10;
    }
    return dao == n;
}
