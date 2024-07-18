#ifndef __MY_CLOUD_H__
#define __MY_CLOUD_H__

#include <pcl/PolygonMesh.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/features/moment_of_inertia_estimation.h>

#include <QDebug>
#include <QFileInfo>
#include <string>

#include "tools.h"
#include "aabb.h"

using namespace std;

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

class Data {
 public:
  Data();
  ~Data();

  bool isValid = false;


  PointCloudT::Ptr cloud;      // point cloud pointer
  pcl::PolygonMesh::Ptr mesh;  // polygon mesh pointer
  pcl::MomentOfInertiaEstimation<PointT> featureExtractor;

  AABB cloudAABB;

  string filePath;    // dir + file name   e.g. /home/user/hello.min.ply
  string fileDir;     // only dir          e.g. /home/user
  string fileName;    // only file name    e.g. hello.min.ply
  string fileSuffix;  // file name suffx   e.g. ply

  string cloudId;  // cloud id in `viewer`: "cloud-" + fileName
  string meshId;   // mesh id in `viewer`: "mesh-" + fileName

  bool hasCloud = false;
  bool hasMesh = false;

  bool visible = true;

  std::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
  string curMode = "point";  // default show mode
  vector<string> supportedModes;
  int viewport;
  pcl::visualization::Camera camera;

  void setPointColor(int r, int g, int b);
  void setPointAlpha(int a);
  void setShowMode(const string& mode);
  void showCloud();
  void hideCloud();
  void showMesh();
  void hideMesh();
  void show();
  void hide();

  void init(const QFileInfo& fileInfo, bool hasCloud, bool hasMesh);

  static Data getInvalidMyCloud() {
    Data myCloud;
    myCloud.isValid = false;
    return myCloud;
  }
};

#endif
