#ifndef FUNCTION_H
#define FUNCTION_H

// #include <QVTKOpenGLNativeWidget.h>
// #include <pcl/ModelCoefficients.h>
// #include <pcl/PolygonMesh.h>
// #include <pcl/io/obj_io.h>
// #include <pcl/io/pcd_io.h>
// #include <pcl/io/ply_io.h>
// #include <pcl/io/vtk_io.h>
// #include <pcl/io/vtk_lib_io.h>  // loadPolygonFileOBJ
// #include <pcl/point_cloud.h>
// #include <pcl/point_types.h>
// #include <pcl/visualization/common/common.h>
// #include <pcl/visualization/pcl_visualizer.h>
#include <algorithm>


template<class P>
P getMaxP(const P& a,const P& b)
{
    P maxP(std::max(a.x,b.x),std::max(a.y,b.y),std::max(a.z,b.z));
    return maxP;
}

template<class P>
P getMinP(const P& a,const P& b)
{
    P minP(std::min(a.x,b.x),std::min(a.y,b.y),std::min(a.z,b.z));
    return minP;
}


#endif // FUNCTION_H
