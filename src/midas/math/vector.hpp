#pragma once

class vector2
{
public:
    int x;
    int y;

    vector2(int _x, int _y)
        : x(_x), y(_y)
    { }

    vector2()
        : x(0), y(0)
    { }

    ~vector2() { }

    vector2 operator+(const vector2& other) const
    {
        return vector2(x + other.x, y + other.y);
    }

    vector2 operator-(const vector2& other) const
    {
        return vector2(x - other.x, y - other.y);
    }

    vector2 operator*(const vector2& other) const
    {
        return vector2(x * other.x, y * other.y);
    }

    vector2 operator*(const float& other) const
    {
        return vector2(x * other, y * other);
    }

    vector2 operator/(const vector2& other) const
    {
        return vector2(x / other.x, y / other.y);
    }

    vector2 operator/(const float& other) const
    {
        return vector2(x / other, y / other);
    }
};

class vector3
{
public:
    int x;
    int y;
    int z;

    vector3(int _x, int _y, int _z)
        : x(_x), y(_y), z(_z)
    { }

    vector3()
        : x(0), y(0), z(0)
    { }

    ~vector3() { }

    vector3 operator+(const vector3& other) const
    {
        return vector3(x + other.x, y + other.y, z + other.z);
    }

    vector3 operator-(const vector3& other) const
    {
        return vector3(x - other.x, y - other.y, z - other.z);
    }

    vector3 operator*(const vector3& other) const
    {
        return vector3(x * other.x, y * other.y, z * other.z);
    }

    vector3 operator*(const float& other) const
    {
        return vector3(x * other, y * other, z * other);
    }

    vector3 operator/(const vector3& other) const
    {
        return vector3(x / other.x, y / other.y, z / other.z);
    }

    vector3 operator/(const float& other) const
    {
        return vector3(x / other, y / other, z / other);
    }
};

class vector4
{
public:
    int x;
    int y;
    int z;
    int w;

    vector4(int _x, int _y, int _z, int _w)
        : x(_x), y(_y), z(_z), w(_w)
    { }

    vector4()
        : x(0), y(0), z(0), w(0)
    { }

    ~vector4() { }

    vector4 operator+(const vector4& other) const
    {
        return vector4(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    vector4 operator-(const vector4& other) const
    {
        return vector4(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    vector4 operator*(const vector4& other) const
    {
        return vector4(x * other.x, y * other.y, z * other.z, w * other.w);
    }

    vector4 operator*(const float& other) const
    {
        return vector4(x * other, y * other, z * other, w * other);
    }

    vector4 operator/(const vector4& other) const
    {
        return vector4(x / other.x, y / other.y, z / other.z, w / other.w);
    }

    vector4 operator/(const float& other) const
    {
        return vector4(x / other, y / other, z / other, w / other);
    }
};