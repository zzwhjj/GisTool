/**
 * ˵����shp�ļ���ȡ
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
	//��ȡshp
	void ReadShp(const std::string& strShpPathName);

private:

};

#endif