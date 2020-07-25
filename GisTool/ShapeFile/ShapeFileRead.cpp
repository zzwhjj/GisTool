#include "..\pch.h"
#include "ShapeFileRead.h"
#include "..\shapelib\shapefil.h"


ShapeFileRead::ShapeFileRead()
{
}

ShapeFileRead::~ShapeFileRead()
{
}

//∂¡»°shp
void ShapeFileRead::ReadShp(const std::string &strShpPathName)
{
	const char* pszShapeFile = strShpPathName.c_str();
	SHPHandle hShp = SHPOpen(pszShapeFile, "r");
	int nShapeType;
	int nEntities = 0;
	double* minB = new double[4];
	double* maxB = new double[4];
	SHPGetInfo(hShp, &nEntities, &nShapeType, minB, maxB);
	
	for (int i = 0; i < nEntities; i++)
	{
		int iShape = i;
		SHPObject* obj = SHPReadObject(hShp, iShape);
		int parts = obj->nParts;
		int verts = obj->nVertices;
		for (int i = 0; i < verts; i++)
		{
			double x = obj->padfX[i];
			double y = obj->padfY[i];
		}
	}
	SHPClose(hShp);
}