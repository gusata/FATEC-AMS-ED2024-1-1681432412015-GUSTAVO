int buscaLinearOrdenada(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
        else if (arr[i] > x)
            return -1;  // Como a lista é ordenada, podemos parar
    }
    return -1;
}
