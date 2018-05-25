void dantzig(AMatrixGraph matrix) {

    for (int k = 0; k < n - 1; ++k) {
        for (int i = 0; i < k; ++i) {
            matrix[i][k + 1] = getMinOf(i, k, i, k + 1);
            matrix[k + 1][i] = getMinOf(i, k, k + 1, i);
        }
    }

    t = getMinOf();

    if (t < 0) {
        throw ("Existen circuitos negativos");
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            matrix[i][j] = getMin(matrix[i][j], matrix[i][k + 1] + matrix[k + 1][j]);
        }
    }
}

int getMinOf(int i, int limit, int rowValue, int colValue) {
    int result = 0;

    for (int j = 0; j < limit; ++j) {
        value =  matrix[rowValue][j] + matrix[j][colValue];

        if(value > result) {
            result = value;
        }
    }

    return result;
}