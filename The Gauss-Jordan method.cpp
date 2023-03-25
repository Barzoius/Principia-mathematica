typedef std::vector<std::vector<double>> Matrix;

std::vector<double> GAUSS_JORDAN_METHOD(Matrix A, std::vector<double> a)
{
    int n = a.size();
    Matrix Aa(n, std::vector<double>(n + 1));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            Aa[i][j] = A[i][j];
        }
        Aa[i][n] = a[i];
    }

    for(int i = 0; i < n; i++)
    {
        int pivot = i;
        for(int j = i + 1; j < n; j++)
        {
            if(abs(Aa[j][i] > abs(Aa[pivot][i])))
            {
                pivot = j;
            }
        }
        if(pivot != i) { swap(Aa[i], Aa[pivot]); }
        double Pivot = Aa[i][i];
        for(int j = i; j < n; j++)
        {
            Aa[i][j] /= Pivot;
        }
        for(int j = 0; j < n; j++)
        {
            if(j != i)
            {
                double F = Aa[j][i];
                for(int k = i; k <= n; k++)
                {
                    Aa[j][k] -= F * Aa[i][k];
                }
            }

        }
    }
    std::vector<double> x(n);
    for(int i = 0; i < n; i++)
    {
        x[i] = Aa[i][n];
    }
    return x;
}
