#include <iostream>
#include "Vector3.cpp"
#include "Vector2.cpp"
#include "Matrix.cpp"

using namespace std;

int main()
{
    int m=3;
    int n=3;
    std::vector<double> arraj;

    for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                arraj.push_back(i*n+j+1);
            }
        }
    arraj[8]=1;

    Matrix<double> a(arraj, m, n);

    //int det = Determinant<int>(a);
    //cout<<"Determinant="<<det<<endl;
    Matrix<double> x = DownTriangular<double>(a);
    return 0;
}
