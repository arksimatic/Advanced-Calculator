#include <iostream>
#include <math.h>
#include <vector>

//pre-declaration class and functions
template<typename T> class Matrix;

template<typename T> Matrix<T> operator + (const Matrix<T>&, const Matrix<T>&);
template<typename T> Matrix<T> operator - (const Matrix<T>&, const Matrix<T>&);
template<typename T> Matrix<T> operator * (const Matrix<T>&, const Matrix<T>&);
template<typename T> T Determinant(const Matrix<T>&);
template<typename T> int LongestNumber(const Matrix<T>&);
template<typename T> int SizeOfNumber(const T&);
template<typename T> Matrix<T> DownTriangular(const Matrix<T>&);

template <typename T> class Matrix
{
public:
    std::vector<T> arr;
    int r, c;
public:
    friend Matrix<T> operator + <> (const Matrix<T>&, const Matrix<T>&);
    friend Matrix<T> operator - <> (const Matrix<T>&, const Matrix<T>&);
    friend Matrix<T> operator * <> (const Matrix<T>&, const Matrix<T>&);
    //template<typename U> friend U Determinant(const Matrix<T>&);
    friend T Determinant(const Matrix<T>&);
    friend int LongestNumber(const Matrix<T>&);
    friend int SizeOfNumber(const T&);
    friend Matrix<T> DownTriangular(const Matrix<T>&);

    Matrix(std::vector<T> a, int r, int c)  //parametrized constructor
    {
        this->arr = a;
        this->r = r;
        this->c = c;
        std::cout<<"Creating: "<<std::endl;
        this->Print();
    }

    Matrix(const Matrix &M) //coping constructor
    {
        this->arr = M.arr;
        this->r = M.r;
        this->c = M.c;
        std::cout<<"Creating: "<<std::endl;
        this->SmartPrint();
    }

    virtual ~Matrix() //destructor
    {
        std::cout<<"Deleting: "<<std::endl;
        this->Print();
    }


    void Print()
    {
        for(int i=0; i<r; i++)
        {
            std::cout<<"|";
            for(int j=0; j<c; j++)
            {
                std::cout<<arr[i*c+j]<<" ";
            }

            std::cout<<'\b';
            std::cout<<"|";
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }

    void SmartPrint()
    {
        int longestNumber = LongestNumber<T>(*this);
        int sizeOfNumber;
        for(int i=0; i<r; i++)
        {
            std::cout<<"|";
            for(int j=0; j<c; j++)
            {
                sizeOfNumber = SizeOfNumber(this->arr[i*c+j]);
                for(int k=sizeOfNumber; k<longestNumber; k++)
                {
                    std::cout<<" ";
                }
                std::cout<<this->arr[i*c+j]<<" ";
            }

            std::cout<<'\b';
            std::cout<<"|";
            std::cout<<std::endl;
        }
    }

    Matrix operator ++ ()
    {
        for(int i=0; i<this->r; i++)
        {
            for(int j=0; j<this->c; j++)
            {
                this->arr[i*c+j]+=1;
            }
        }
        return *this;
    }

    Matrix operator ++ (int)
    {
        for(int i=0; i<this->r; i++)
        {
            for(int j=0; j<this->c; j++)
            {
                this->arr[i*c+j]+=1;
            }
        }
        return *this;
    }

    Matrix operator -- ()
    {
        for(int i=0; i<this->r; i++)
        {
            for(int j=0; j<this->c; j++)
            {
                this->arr[i*c+j]-=1;
            }
        }
        return *this;
    }

    Matrix operator -- (int)
    {
        for(int i=0; i<this->r; i++)
        {
            for(int j=0; j<this->c; j++)
            {
                this->arr[i*c+j]-=1;
            }
        }
        return *this;
    }

};


template <typename T> Matrix<T> operator + (const Matrix<T> &M1, const Matrix<T> &M2)
{
        std::vector<T> arr;
        int r = M1.r;
        int c = M1.c;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                arr.push_back(0);
                arr[i*c+j]=M1.arr[i*c+j]+M2.arr[i*c+j];
            }
        }

    return Matrix<T>(arr, r, c);
}

template <typename T> Matrix<T> operator - (const Matrix<T> &M1, const Matrix<T> &M2)
{
        std::vector<T> arr;
        int r = M1.r;
        int c = M1.c;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                arr.push_back(0);
                arr[i*c+j]=M1.arr[i*c+j]-M2.arr[i*c+j];
            }
        }
    return Matrix<T>(arr, r, c);
}

template <typename T> Matrix<T> operator * (const Matrix<T> &M1, const Matrix<T> &M2)
{
        int r = M2.r;
        int c = M1.c;
        int l = M1.r; //=M2.c;
        int h = r *c;
        std::vector<T> arr;

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                arr.push_back(0);
                for(int k=0; k<l; k++)
                {
                    arr[i*r+j]+=(M1.arr[k*r+j]*M2.arr[i*l+k]);
                }
                std::cout<<std::endl;
            }
        }
    return Matrix<T>(arr, r, c);
}

template<typename T> T Determinant(const Matrix<T>& M)
{
    if(M.r == 1)
    {
        //std::cout<<"returning"<<M.arr[0]<<std::endl;
        return M.arr[0];
    }
    else
    {
        T det = 0;
        for(int i=0; i<M.c; i++)
        {
            std::vector<T> v;
            for(int j=0; j<M.arr.size(); j++)
            {
                if(j>=M.c && j%M.c!=i)
                v.push_back(M.arr[j]);
            }

            Matrix<T> help(v, M.r-1, M.c-1);
            T detHelp = Determinant<T>(help);
            if((i+1)%2==0)
            {detHelp = 0-detHelp;}
            detHelp = detHelp * M.arr[i];
            //std::cout<<"calculated det: "<<detHelp<<" ";
            det += detHelp;
        }
        return det;
    }
}

template<typename T> int LongestNumber(const Matrix<T>& M)
{
    int longestNumber = 1;

    for(int i=0; i<M.r; i++)
        {
            for(int j=0; j<M.c; j++)
            {
                if (SizeOfNumber(M.arr[i*M.c+j])>longestNumber)
                {
                    longestNumber = SizeOfNumber(M.arr[i*M.c+j]);
                }
            }
        }
        return longestNumber;
}

template<typename T> int SizeOfNumber(const T& t) //for non-decimal numbers
{
    T number = t;
    int numberSize = 1;
    while(number/10!=0)
    {
        numberSize++;
        number/=10;
    }
    return numberSize;
}

template<typename T> Matrix<T> DownTriangular(const Matrix<T>& M)
{

    std::vector<T> v = M.arr;
    int r = M.r;
    int c = M.c;

    for(int i=0; i<r; i++)
    {
        for(int j=i+1; j<r; j++)
        {
            T multiplier = v[i*c+i]/v[j*c+i];
            for(int k=0; k<c; k++)
            {
                v[j*c+k]=v[j*c+k]*multiplier-v[i*c+k];
            }
        }
    }
    return Matrix<T>(v, r, c);
}
