#include "aabb.h"

AABB::AABB()
{
    updated = false;
}
AABB::AABB(float minX,float minY,float minZ,float maxX,float maxY,float maxZ)
{
    minP.x = minX;
    minP.y = minY;
    minP.z = minZ;
    maxP.x = maxX;
    maxP.y = maxY;
    maxP.z = maxZ;

    updated = true;
};


void AABB::update(float x,float y,float z)
{
    if(!updated)
    {
        minP.x = x;
        minP.y = y;
        minP.z = z;
        maxP.x = x;
        maxP.y = y;
        maxP.z = z;
        updated = true;
        return;
    }
    minP.x = fmin(x,minP.x);
    minP.y = fmin(y,minP.y);
    minP.z = fmin(z,minP.z);
    maxP.x = fmax(x,maxP.x);
    maxP.y = fmax(y,maxP.y);
    maxP.z = fmax(z,maxP.z);

}

void AABB::printAABB()
{

    qDebug() << minP.x << " " << minP.y << " "<<minP.z;
    qDebug() << maxP.x << " " << maxP.y << " "<<maxP.z;
}
void AABB::update(const AABB& a)
{
    update(a.minP.x,a.minP.y,a.minP.z);
    update(a.maxP.x,a.maxP.y,a.maxP.z);
}


PointXYZ AABB::getPosition(const float& viewX,const float& viewY,const float& viewZ,
                           const float& scalar)
{

    Eigen::Vector3f aabbVec(maxP.x-minP.x,
                            maxP.y-minP.y,
                            maxP.z-minP.z);
    Eigen::Vector3f camerVec(viewX,viewY,viewZ);
    Eigen::Vector3f vec = aabbVec.dot(camerVec) * camerVec;

    float digLen = sqrt(aabbVec.squaredNorm() -  vec.squaredNorm());
    Eigen::Vector3f camera2Minp = digLen * vec * scalar;

    return PointXYZ(minP.x-camera2Minp.x(),minP.y-camera2Minp.y(),minP.z-camera2Minp.z());
}
