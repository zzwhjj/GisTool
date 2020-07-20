/**
 * 说明：shp文件写入
 * date: 2020-07-21
 * author: zhangzw
 */
#ifndef _SHAPEFILEWRITE_H
#define _SHAPEFILEWRITE_H

#include <string>

class ShapeFileWrite
{
public:
	ShapeFileWrite();
	virtual ~ShapeFileWrite();

public:
	//创建shp，并写入数据
	void WriteShp(const std::string& strShpPathName);

private:

};

#endif