#include <iostream>
#include <math.h>

//pre-declaration class and functions
template<typename T> class Vector2;
template<typename T> Vector2<T> operator + (const Vector2<T>&, const Vector2<T>&); // vector + vector
template<typename T> Vector2<T> operator - (const Vector2<T>&, const Vector2<T>&); // vector - vector
template<typename T> Vector2<T> operator ! (const Vector2<T>&); //
template<typename T> T operator ^ (const Vector2<T>&, const Vector2<T>&); // scalar multiplication
template<typename T> Vector2<T> operator * (const Vector2<T>&, const T&); // vector * scalar
template<typename T> Vector2<T> operator * (const T&, const Vector2<T>&); // scalar * vector

template <typename T> class Vector2
{
private:
    T x, y;
    T length;
public:
    friend Vector2<T> operator + <> (const Vector2<T>&, const Vector2<T>&);
    friend Vector2<T> operator - <> (const Vector2<T>&, const Vector2<T>&);
    friend Vector2<T> operator ! <> (const Vector2<T>&);
    friend T operator ^ <> (const Vector2<T>&, const Vector2<T>&);
    friend Vector2<T> operator * <> (const Vector2<T>&, const T&);
    friend Vector2<T> operator * <> (const T&, const Vector2<T>&);

    Vector2()  //constructor
    {
        this->x = 0;
        this->y = 0;
        this->length = 0;
    }

    Vector2(T x, T y)  //parametrized constructor
    {
        this->x = x;
        this->y = y;
        this->length = sqrt(this->x * this->x + this->y * this->y);
    }

    void Print()
    {
        std::cout<<"X: "<<this->x<<std::endl;
        std::cout<<"Y: "<<this->y<<std::endl<<std::endl;
    }

    Vector2 operator ++ ()
    {
        this->x++;
        this->y++;
        return *this;
    }

    Vector2 operator ++ (int)
    {
        this->x++;
        this->y++;
        return *this;
    }

    Vector2 operator -- ()
    {
        this->x--;
        this->y--;
        return *this;
    }

    Vector2 operator -- (int)
    {
        this->x--;
        this->y--;
        return *this;
    }

};


template <typename T> Vector2<T> operator + (const Vector2<T> &V, const Vector2<T> &W)
{
        return Vector2<T>(W.x + V.x,  W.y + V.y);
}

template <typename T> Vector2<T> operator - (const Vector2<T> &V, const Vector2<T> &W)
{
        return Vector2<T>(V.x-W.x, V.y-W.y);
}

template <typename T> Vector2<T> operator ! (const Vector2<T> &V)
{
    return Vector2<T>(0-V.x, 0-V.y);
}

template<typename T> T operator ^ (const Vector2<T> &V, const Vector2<T> &W)
{
    T t = V.x*W.x + V.y*W.y;
    return t;
}

template<typename T> Vector2<T> operator * (const Vector2<T>& V, const T& t)
{
    return Vector2<T>(V.x*t, V.y*t);
}

template<typename T> Vector2<T> operator * (const T& t, const Vector2<T>& V)
{
    return Vector2<T>(V.x*t, V.y*t);
}
