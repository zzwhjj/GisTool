#include "..\pch.h"
#include "ShapeFileWrite.h"
#include "..\shapelib\shapefil.h"


ShapeFileWrite::ShapeFileWrite()
{
}

ShapeFileWrite::~ShapeFileWrite()
{
}

//记录shp
void ShapeFileWrite::WriteShp(const std::string& strShpPathName)
{
	//简化后保存
	const char* saveFileName = "data\\simplyRoom.shp";
	int nShpTpyeSave = SHPT_POLYGON;
	SHPHandle outShp = SHPCreate(saveFileName, nShpTpyeSave);
	DBFHandle dbf_h = DBFCreate(saveFileName);
	int fieldIdx = DBFAddField(dbf_h, "Shape", FTInteger, 2, 0);
	SHPObject* psShape;

	/*for (int ir = 0; ir < rooms_.size(); ir++)
	{
		printf("--------------Room:%d------------\n", ir);
		std::vector<Coordinate> coords = rooms_[ir].simplyCoords_;
		double* xCoords = new double[coords.size()];
		double* yCoords = new double[coords.size()];
		for (int ip = 0; ip < coords.size(); ip++)
		{
			double x = coords[ip].x;
			double y = coords[ip].y;
			xCoords[ip] = x;
			yCoords[ip] = y;
			printf("%f,%f;\n", x, y);
		}
		printf("\n");
		psShape = SHPCreateObject(nShpTpyeSave, -1, 0, NULL, NULL, coords.size(), xCoords, yCoords, NULL, NULL);

		std::cout << std::endl;
		int ishape = SHPWriteObject(outShp, -1, psShape);
		SHPDestroyObject(psShape);
		DBFWriteIntegerAttribute(dbf_h, ishape, 0, ishape);
	}*/
	SHPClose(outShp);
	DBFClose(dbf_h);
}