#include <iostream>
#include <math.h>

//pre-declaration class and functions
template<typename T> class Vector3;
template<typename T> Vector3<T> operator + (const Vector3<T>&, const Vector3<T>&); // vector + vector
template<typename T> Vector3<T> operator - (const Vector3<T>&, const Vector3<T>&); // vector - vector
template<typename T> Vector3<T> operator * (const Vector3<T>&, const Vector3<T>&);  // vector multiplication
template<typename T> Vector3<T> operator ! (const Vector3<T>&); //
template<typename T> T operator ^ (const Vector3<T>&, const Vector3<T>&); // scalar multiplication
template<typename T> Vector3<T> operator * (const Vector3<T>&, const T&); // vector * scalar
template<typename T> Vector3<T> operator * (const T&, const Vector3<T>&); // scalar * vector

template <typename T> class Vector3
{
private:
    T x, y, z;
    T length;
public:
    friend Vector3<T> operator + <> (const Vector3<T>&, const Vector3<T>&);
    friend Vector3<T> operator - <> (const Vector3<T>&, const Vector3<T>&);
    friend Vector3<T> operator * <> (const Vector3<T>&, const Vector3<T>&);
    friend Vector3<T> operator ! <> (const Vector3<T>&);
    friend T operator ^ <> (const Vector3<T>&, const Vector3<T>&);
    friend Vector3<T> operator * <> (const Vector3<T>&, const T&);
    friend Vector3<T> operator * <> (const T&, const Vector3<T>&);

    Vector3()  //constructor
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
        this->length = 0;
    }

    Vector3(T x, T y, T z)  //parametrized constructor
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->length = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    void Print()
    {
        std::cout<<"X: "<<this->x<<std::endl;
        std::cout<<"Y: "<<this->y<<std::endl;
        std::cout<<"Z: "<<this->z<<std::endl<<std::endl;
    }

    Vector3 operator ++ ()
    {
        this->x++;
        this->y++;
        this->z++;
        return *this;
    }

    Vector3 operator ++ (int)
    {
        this->x++;
        this->y++;
        this->z++;
        return *this;
    }

    Vector3 operator -- ()
    {
        this->x--;
        this->y--;
        this->z--;
        return *this;
    }

    Vector3 operator -- (int)
    {
        this->x--;
        this->y--;
        this->z--;
        return *this;
    }

};


template <typename T> Vector3<T> operator + (const Vector3<T> &V, const Vector3<T> &W)
{
        return Vector3<T>(W.x + V.x,  W.y + V.y, W.z + V.z);
}

template <typename T> Vector3<T> operator - (const Vector3<T> &V, const Vector3<T> &W)
{
        return Vector3<T>(V.x-W.x, V.y-W.y, V.z-W.z);
}

template <typename T> Vector3<T> operator * (const Vector3<T> &V, const Vector3<T> &W)
{
        return Vector3<T>(V.y*W.z-V.z*W.y, V.z*W.x-V.x*W.z, V.x*W.y-V.y*W.x);
}

template <typename T> Vector3<T> operator ! (const Vector3<T> &V)
{
    return Vector3<T>(0-V.x, 0-V.y, 0-V.z);
}

template<typename T> T operator ^ (const Vector3<T> &V, const Vector3<T> &W)
{
    T t = V.x*W.x + V.y*W.y + V.z*W.z;
    return t;
}

template<typename T> Vector3<T> operator * (const Vector3<T>& V, const T& t)
{
    return Vector3<T>(V.x*t, V.y*t, V.z*t);
}

template<typename T> Vector3<T> operator * (const T& t, const Vector3<T>& V)
{
    return Vector3<T>(V.x*t, V.y*t, V.z*t);
}
