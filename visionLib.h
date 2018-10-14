//============================================================================
//  Morphology functions
//============================================================================
VISIONLIB_API BOOL vlMorphology(const Image &source, Image &dest, const MorphologyMethod method, const RECT& roi, const StructuringElement* const pStructuringElement);
VISIONLIB_API BOOL vlLabel(const Image &source, Image &dest, const RECT& roi, const BOOL connectivity8, int* particleCount);
VISIONLIB_API BOOL vlSimpleConvexHull(const Contour &vertices, Contour &hull);
VISIONLIB_API BOOL vlConvexHull(const PointsSet &vertices, Contour &hull);
// 灰度级的膨胀运算,将当前像素替换为掩模结构内灰度值最高的点
VISIONLIB_API BOOL vlDilation(const Image& source, Image& dest, const int width, const int height, const RECT &roi);
// 灰度级的腐蚀运算,将当前像素值替换为掩模结构内灰度值最低的点
VISIONLIB_API BOOL vlErosion(const Image& source, Image& dest, const int width, const int height, const RECT &roi);
// 闭运算,先膨胀再腐蚀
VISIONLIB_API BOOL vlClosing(const Image& source, Image& dest, const int nDilationCounts, const int nErosionCounts, const int width, const int height, const RECT &roi);
// 开运算,先腐蚀再膨胀
VISIONLIB_API BOOL vlOpening(const Image& source, Image& dest, const int nDilationCounts, const int nErosionCounts, const int width, const int height, const RECT &roi);

//============================================================================
//  Locate Edges Functions
//============================================================================
// 定位边缘点的位置(亚像素精度)
VISIONLIB_API BOOL vlExtractLinearEdge(const FloatArray& lineProfile, const int threshold, const int steepness, FLOAT *const pEdgePoint);

//============================================================================
//  Analytic Geometry functions
//============================================================================
// 先用最小二乘法拟合圆,如果拟合不高,根据权重已经各点都第一次拟合圆的距离进行二次拟合
VISIONLIB_API BOOL vlFitCircle(Edge &edgePoints, const FitCircleOptions *pOptions, BestCircle *const pReport);
// 用最小二乘法拟合圆
VISIONLIB_API BOOL vlFitCircle(const Curve &curve, BestCircle *const pReport);
VISIONLIB_API BOOL vlFitLine(Edge &edgePoints, const FitLineOptions *pOptions, BestLine *const pReport);
VISIONLIB_API BOOL vlGetIntersection(const POINTFLOAT &start1, const POINTFLOAT &end1, const POINTFLOAT &start2, const POINTFLOAT &end2, POINTFLOAT &intersection);
VISIONLIB_API BOOL vlGetAngle(const POINTFLOAT &start1, const POINTFLOAT &end1, const POINTFLOAT &start2, const POINTFLOAT &end2, float &angle);
VISIONLIB_API BOOL vlGetPerpendicularLine(const POINTFLOAT &refLineStart, const POINTFLOAT &refLineEnd, const POINTFLOAT &point, POINTFLOAT &perpLineEnd);
VISIONLIB_API BOOL vlGetPerpendicularDistance(const POINTFLOAT &refLineStart, const POINTFLOAT &refLineEnd, const POINTFLOAT &point, double &distance);

//============================================================================
//  Locate Edges functions
//============================================================================
VISIONLIB_API BOOL vlFindCircularEdge(const Image &image, const Annulus& searchArea, const SpokeDirection direction, const FindEdgeOptions *pFindOptions, const FitCircleOptions *pFitOptions, CircularEdgeReport *pReport);
VISIONLIB_API BOOL vlFindEdge(const Image &image, const RECT &searchRect, const RakeDirection direction, const FindEdgeOptions *pFindOptions, const FitLineOptions *pFitOptions, StraightEdgeReport *pReport);
VISIONLIB_API BOOL vlFindEdge(const Image &image, const RotatedRect &searchRect, const FindEdgeOptions *pFindOptions, const FitLineOptions *pFitOptions, StraightEdgeReport* pReport);

//============================================================================
//  Spatial Filters functions
//============================================================================
VISIONLIB_API BOOL vlMeanFilter(const Image& source, Image& dest, const int width, const int height, const RECT &roi, const Image *pMask);
VISIONLIB_API BOOL vlMedianFilter(const Image& source, Image& dest, const int width, const int height, const RECT &roi, const Image *pMask);
VISIONLIB_API BOOL vlGaussFilter(const Image& source, Image& dest, const GaussKernel kernel, const RECT &roi, const Image *pMask);

//============================================================================
//  Transform Functions
//	Transform functions allow you to replace each pixel in an image using a transfer function
//============================================================================
VISIONLIB_API bool vlMathTransform(const Image& source, Image& dest, const TransformMethod method, const float rangeMin, const float rangeMax, const float power, const Image* pMask);

//============================================================================
//  Image Management functions
//============================================================================
VISIONLIB_API BOOL		vlMakeImage(const HBITMAP hBitmap, Image &image);
VISIONLIB_API void		vlMakeRotatedRect(const FLOAT left, const FLOAT top, const FLOAT width, const FLOAT height, const double angle, RotatedRect &rotatedRect);
VISIONLIB_API BOOL		vlMirrorHor(const Image &source, Image *pDest);
VISIONLIB_API IImage	*vlCreateImage(const ImageType &type);
VISIONLIB_API IImage	*vlLoadImage(LPCSTR lpszFileName);
VISIONLIB_API BOOL		vlSaveImage(LPCSTR lpszFileName, const int width, const int height, const int stride, const ImageType format, const BYTE *scan0);
VISIONLIB_API BOOL		vlSaveImage(LPCSTR lpszFileName, const HBITMAP hBitmap);

//============================================================================
//  Utility
//============================================================================
VISIONLIB_API BOOL vlNormalize(double *pVector, const int nCount , int *pContrast , int *pMean);
VISIONLIB_API BOOL vlNormalize(float *pVector, const int nCount, int*pContrast, int *pMean);
VISIONLIB_API BOOL vlNormalize(FloatArray::iterator start, const int nCount, int *pContrast, int *pMean);
VISIONLIB_API BOOL vlFindPadCenter(const Image &image, const RECT &searchRect, POINTFLOAT &center);
VISIONLIB_API BOOL vlFindPadEllipseParam(const Image &image, const RECT &searchRect, long lEdgeLv,
										long padStableHeight, EllipseParameter &ellipse);
// Find pad ellipse parameter
// Return FALSE on failure, TRUE if success
// image: image data structure
// searchRect: search region
// lEdgeLv: minimum edge level
// padStableHeight: Stable pad height
// ellipse: [output] Infomation about the found ellipse
VISIONLIB_API BOOL vlMatchCircle(const Image& src, const RECT& searchRect, const DoubleRingData* pDoubleRing, SpokeDirection direction, const FindEdgeOptions* pFindOptions, const FitCircleOptions* pFitOptions, CircularEdgeReport* pReport);
VISIONLIB_API BOOL vlMatchCircleEx(const Image& src, const RECT& searchRect, const MatchCircleOptions& opts, CircularEdgeReport* pReport);
VISIONLIB_API ITracker *vlCreateTracker(const TrackerType type, const HWND hContainerWnd, const UINT nStyle, const void *pTrackerData, PCSTR pszName);
VISIONLIB_API IProfileData *vlRingProfile(const IImage *pIImage, const RingData *pRing, const int stepSize);

//============================================================================
//  OCR&OCV
//============================================================================
VISIONLIB_API ICharSet *vlCreateCharSet();
VISIONLIB_API IObjectSet *vlCreateObjectSet();

//============================================================================
//  Angle Soldering Pad Center Searching
//============================================================================
VISIONLIB_API bool vlAngleSolder(const Image& image, const RECT& rcSearch, const HGAType ud,
								 const int thresholdHGA, const int thresholdPCB,
								 const int numPads, PadReport pr[12], const int numPadsEssential,
								 const int maxGap);
VISIONLIB_API bool vlAngleSolderEx(const Image& image, const RECT& rcSearch, const HGAType ud,
								   const ASMInfo* info, PadReport (&pr)[12]);

//============================================================================
//  SBM Pad Center Searching
//============================================================================
VISIONLIB_API bool vlSBM(const Image& image, const RECT& rcSearch, int threshold, const SBMInfo* info, SBMPadReport (&pr)[12]);

//============================================================================
//  TSB Pad Searching
//============================================================================
VISIONLIB_API bool vlTSB(const Image& image, const RECT& rcSearch, TSBTrimMethod trim, const TSBInfo* info, TSBPadReport (&pr)[32]);
VISIONLIB_API void vlContourTracingCCs(BYTE *pSource,int *pDest,const int xStart,const int xEnd,const int yStart,const int yEnd,const int nRowLength,const int nWidth);
