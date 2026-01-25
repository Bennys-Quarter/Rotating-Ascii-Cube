/*
 * vec.h
 *
 *  Created on: Nov 6, 2025
 *      Author: benny
 */

#ifndef INC_VEC_H_
#define INC_VEC_H_

#include <math.h>

typedef struct { double x; double z; } Vec2;
typedef struct { double x; double y; double z; } Vec3;

Vec3 addVec3(Vec3 a, Vec3 b);
Vec2 addVec2(Vec2 a, Vec2 b);
Vec3 subVec3(Vec3 a, Vec3 b);
Vec2 subVec2(Vec2 a, Vec2 b);
Vec3 mulVec3(Vec3 a, Vec3 b);
Vec2 mulVec2(Vec2 a, Vec2 b);
Vec3 mulVec3Scalar(Vec3 v, double s);
Vec2 mulVec2Scalar(Vec2 v, double s);
Vec3 divVec3(Vec3 a, Vec3 b);
Vec2 divVec2(Vec2 a, Vec2 b);
Vec3 crossVec3(Vec3 a, Vec3 b);
double dotVec3(Vec3 a, Vec3 b);
double normVec3(Vec3 v);
double normVec2(Vec2 v);

#endif /* INC_VEC_H_ */
