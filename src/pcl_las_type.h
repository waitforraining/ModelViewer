#define PCL_NO_PRECOMPILE
#include <pcl/memory.h>
#include <pcl/pcl_macros.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>

struct EIGEN_ALIGN16 LasType    // enforce SSE padding for correct memory alignment
{
    PCL_ADD_POINT4D;                  // preferred way of adding a XYZ+padding
    float test;
    PCL_MAKE_ALIGNED_OPERATOR_NEW     // make sure our new allocators are aligned
};

POINT_CLOUD_REGISTER_POINT_STRUCT (LasType,           // here we assume a XYZ + "test" (as fields)
                                  (float, x, x)
                                  (float, y, y)
                                  (float, z, z)
                                  (float, test, test)
                                  )
void test()
{

}

