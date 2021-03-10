#ifndef __UTILITY_H__
#define __UTILITY_H__

namespace Util
{
    struct Vec3D
    {
        double x = 0.0f;
        double y = 0.0f;
        double z = 0.0f;
    };

    const double PI = 3.141592653589793;
    const double GRAVITY = 9.80665;

    double dotProd(Vec3D A, Vec3D B);
    Vec3D crossProd(Vec3D A, Vec3D B);
}


#endif // __UTILITY_H__