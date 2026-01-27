/*
 * vec.c
 *
 *  Created on: Nov 6, 2025
 *      Author: benny
 */
#include "math.h"

typedef struct { double x; double z; } Vec2;
typedef struct { double x; double y; double z; } Vec3;


/**
 * @fn Vec3 addVec3(Vec3, Vec3)
 * @brief adds two 3D vectors element wise
 *
 * @pre
 * @post
 * @param a
 * @param b
 * @return
 */
Vec3 addVec3(Vec3 a, Vec3 b)
{
    Vec3 result = {0, 0, 0};
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

/**
 * @fn Vec2 addVec2(Vec2, Vec2)
 * @brief adds two 2D vectors element wise
 *
 * @pre
 * @post
 * @param a
 * @param b
 * @return
 */
Vec2 addVec2(Vec2 a, Vec2 b)
{
    Vec2 result = {0, 0};
    result.x = a.x + b.x;
    result.z = a.z + b.z;
    return result;
}

/**
 * @fn Vec3 subVec3(Vec3, Vec3)
 * @brief subtracts two 3D vectors element wise
 *
 * @pre
 * @post
 * @param a
 * @param b
 * @return
 */
Vec3 subVec3(Vec3 a, Vec3 b)
{
    Vec3 result = {0, 0, 0};
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

/**
 * @fn Vec2 subVec2(Vec2, Vec2)
 * @brief subtracts two 2D vectors element wise
 *
 * @pre
 * @post
 * @param a
 * @param b
 * @return
 */
Vec2 subVec2(Vec2 a, Vec2 b)
{
    Vec2 result = {0, 0};
    result.x = a.x - b.x;
    result.z = a.z - b.z;
    return result;
}

/**
 * @fn Vec3 mulVec3(Vec3, Vec3)
 * @brief element wise multiply two 3D vectors
 *
 * @pre
 * @post
 * @param a
 * @param b
 * @return
 */
Vec3 mulVec3(Vec3 a, Vec3 b)
{
    Vec3 result = {0, 0, 0};
    result.x = a.x * b.x;
    result.y = a.y * b.y;
    result.z = a.z * b.z;
    return result;
}

/**
 * @fn Vec2 mulVec2(Vec2, Vec2)
 * @brief element wise multiply two 2D vectors
 *
 * @pre
 * @post
 * @param a
 * @param b
 * @return
 */
Vec2 mulVec2(Vec2 a, Vec2 b)
{
    Vec2 result = {0, 0};
    result.x = a.x * b.x;
    result.z = a.z * b.z;
    return result;
}

/**
 * @fn Vec3 mulVec3Scalar(Vec3, double)
 * @brief Multiply 3D vector by an integer scalar
 *
 * @pre
 * @post
 * @param v
 * @param s
 * @return
 */
Vec3 mulVec3Scalar(Vec3 v, double s)
{
    v.x = v.x * s;
    v.y = v.y * s;
    v.z = v.z * s;
    return v;
}

/**
 * @fn Vec2 mulVec2Scalar(Vec2, double)
 * @brief Multiply 2D vector by an integer scalar
 *
 * @pre
 * @post
 * @param v
 * @param s
 * @return
 */
Vec2 mulVec2Scalar(Vec2 v, double s)
{
    v.x = v.x * s;
    v.z = v.z * s;
    return v;
}

/**
 * @fn Vec3 divVec3(Vec3, Vec3)
 * @brief element wise division of two 3D vectors
 *
 * @pre
 * @post
 * @param a
 * @param b
 * @return
 */
Vec3 divVec3(Vec3 a, Vec3 b)
{
    Vec3 result = {0, 0, 0};
    result.x = a.x / b.x;
    result.y = a.y / b.y;
    result.z = a.z / b.z;
    return result;
}

/**
 * @fn Vec2 divVec2(Vec2, Vec2)
 * @brief element wise division of two 2D vectors
 *
 * @pre
 * @post
 * @param a
 * @param b
 * @return
 */
Vec2 divVec2(Vec2 a, Vec2 b)
{
    Vec2 result = {0, 0};
    result.x = a.x / b.x;
    result.z = a.z / b.z;
    return result;
}

/**
 * @fn Vec3 crossVec3(Vec3, Vec3)
 * @brief Cross product of two 3D vectors
 *
 * @pre
 * @post
 * @param a
 * @param b
 * @return
 */
Vec3 crossVec3(Vec3 a, Vec3 b)
{
    return (Vec3){a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x};
}

/**
 * @fn double normVec3(Vec3)
 * @brief calculates the euclidean norm of a 3D vector
 *
 * @pre
 * @post
 * @param v
 * @return
 */
double normVec3(Vec3 v)
{
    double result = 0.0;
    result = sqrt(pow(v.x,2)+ pow(v.y,2)+ pow(v.z,2));
    return result;
}

/**
 * @fn double normVec2(Vec2)
 * @brief calculates the euclidean norm of a 2D vector
 *
 * @pre
 * @post
 * @param v
 * @return
 */
double normVec2(Vec2 v)
{
    double result = 0.0;
    result = sqrt(pow(v.x,2) + pow(v.z,2));
    return result;
}

/**
 * @fn double dotVec3(Vec3, Vec3)
 * @brief Dot product of two 3D vectors
 *
 * @pre
 * @post
 * @param a
 * @param b
 * @return
 */
double dotVec3(Vec3 a, Vec3 b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

