/*
 * vec.c
 *
 *  Created on: Nov 6, 2025
 *      Author: benny
 */
#include "math.h"

typedef struct { double x; double z; } Vec2;
typedef struct { double x; double y; double z; } Vec3;


Vec3 addVec3(Vec3 a, Vec3 b)
{
	/* Function to element wise add two 3D vectors
	 *
	 */
    Vec3 result = {0, 0, 0};
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}


Vec2 addVec2(Vec2 a, Vec2 b)
{
	/* Function to element wise add two 2D vectors
	 *
	 */
    Vec2 result = {0, 0};
    result.x = a.x + b.x;
    result.z = a.z + b.z;
    return result;
}


Vec3 subVec3(Vec3 a, Vec3 b)
{
	/* Function to element wise subtract two 3D vectors
	 *
	 */
    Vec3 result = {0, 0, 0};
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}


Vec2 subVec2(Vec2 a, Vec2 b)
{
	/* Function to element wise subtract two 2D vectors
	 *
	 */
    Vec2 result = {0, 0};
    result.x = a.x - b.x;
    result.z = a.z - b.z;
    return result;
}


Vec3 mulVec3(Vec3 a, Vec3 b)
{
	/* Function to element wise multiply two 3D vectors
	 *
	 */
    Vec3 result = {0, 0, 0};
    result.x = a.x * b.x;
    result.y = a.y * b.y;
    result.z = a.z * b.z;
    return result;
}


Vec2 mulVec2(Vec2 a, Vec2 b)
{
	/* Function to element wise multiply two 2D vectors
	 *
	 */
    Vec2 result = {0, 0};
    result.x = a.x * b.x;
    result.z = a.z * b.z;
    return result;
}


Vec3 mulVec3Scalar(Vec3 v, double s)
{
	/* Multiply 3D vector by an integer scalar
	 *
	 */
    v.x = v.x * s;
    v.y = v.y * s;
    v.z = v.z * s;
    return v;
}


Vec2 mulVec2Scalar(Vec2 v, double s)
{
	/* Multiply 2D vector by an integer scalar
	 *
	 */
    v.x = v.x * s;
    v.z = v.z * s;
    return v;
}


Vec3 divVec3(Vec3 a, Vec3 b)
{
	/* Function to element wise division of two 3D vectors
	 *
	 */
    Vec3 result = {0, 0, 0};
    result.x = a.x / b.x;
    result.y = a.y / b.y;
    result.z = a.z / b.z;
    return result;
}


Vec2 divVec2(Vec2 a, Vec2 b)
{
	/* Function to element wise division of two 2D vectors
	 *
	 */
    Vec2 result = {0, 0};
    result.x = a.x / b.x;
    result.z = a.z / b.z;
    return result;
}


double normVec3(Vec3 v)
{
	/* Function to calculate the euclidean norm of a 3D vector
	 *
	 */
    double result = 0.0;
    result = sqrt(pow(v.x,2)+ pow(v.y,2)+ pow(v.z,2));
    return result;
}


double normVec2(Vec2 v)
{
	/* Function to calculate the euclidean norm of a 2D vector
	 *
	 */
    double result = 0.0;
    result = sqrt(pow(v.x,2) + pow(v.z,2));
    return result;
}
