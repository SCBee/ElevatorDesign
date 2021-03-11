#include <utility.h>
#include <cmath>

namespace Util
{
    double dotProd(Vec3D A, Vec3D B) 
    {
        return (A.x * B.x) + (A.y * B.y) + (A.z * B.z);
    }
    
    Vec3D crossProd(Vec3D A, Vec3D B) 
    {
        Vec3D resultant;

        resultant.x = (A.y*B.z - A.z*B.y);
        resultant.y = (A.x*B.z - A.z*B.x);
        resultant.z = (A.x*B.y - A.y*B.x);

        return resultant;
    }

    double normalize(Vec3D A)
    {
        double resultant = 0.0f;

        resultant = std::sqrt(std::pow(A.x, 2) + std::pow(A.y, 2) + std::pow(A.z, 2));

        return resultant;
    }
}