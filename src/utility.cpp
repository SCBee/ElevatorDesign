#include <utility.h>

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
}