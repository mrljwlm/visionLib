// 定位边缘点的位置(亚像素精度)
// lineProfile 为边缘区域横截面灰度的导数
// pEdgePoint 为边缘点在该横截面上的坐标
VISIONLIB_API BOOL vlExtractLinearEdge(const FloatArray& lineProfile,
									   const int threshold,
									   const int steepness,
									   float* const pEdgePoint)
{
}
