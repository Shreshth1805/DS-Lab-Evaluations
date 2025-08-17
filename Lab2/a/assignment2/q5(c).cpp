class LowerTriangular {
    int *arr;
    int n;
public:
    LowerTriangular(int size) {
        n = size;
        arr = new int[n * (n + 1) / 2];
    }
    void set(int i, int j, int value) {
        if (i >= j)
            arr[i * (i - 1) / 2 + (j - 1)] = value;
    }
    int get(int i, int j) {
        if (i >= j)
            return arr[i * (i - 1) / 2 + (j - 1)];
        else
            return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};
