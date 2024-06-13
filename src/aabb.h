#ifndef AABB_H
#define AABB_H

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <eigen3/Eigen/Core>

#include <QDebug>

using PointXYZ = pcl::PointXYZ;

class AABB
{
public:
    AABB();
    AABB(float minX,float minY,float minZ,float maxX,float maxY,float maxZ);
    AABB(float minX,float minY,float maxX,float maxY);
    void update(float x,float y,float z);
    void update(const AABB& a);
    PointXYZ getPosition(const float& viewX,const float& viewY,const float& viewZ,
                         const float& scalar);
    inline PointXYZ getMidPnt() {return PointXYZ((maxP.x+minP.x)/2,(maxP.y+minP.y)/2,(maxP.z+maxP.z)/2);};
    inline bool isUpdated() {return updated;};
    void printAABB();
protected:
    PointXYZ minP,maxP;
    bool updated;
};





#endif // AABB_H
