/**
 * ˵����shp�ļ�д��
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
	//����shp����д������
	void WriteShp(const std::string& strShpPathName);

private:

};

#endif