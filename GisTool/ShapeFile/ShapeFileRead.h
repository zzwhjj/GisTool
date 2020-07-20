/**
 * 说明：shp文件读取
 * date: 2020-07-21
 * author: zhangzw
 */
#ifndef _SHAPEFILEREAD_H
#define _SHAPEFILEREAD_H

#include <string>

class ShapeFileRead
{
public:
	ShapeFileRead();
	virtual ~ShapeFileRead();

public:
	//读取shp
	void ReadShp(const std::string& strShpPathName);

private:

};

#endif