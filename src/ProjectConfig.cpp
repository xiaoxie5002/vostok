#include "ProjectConfig.h"

#include <cmath>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

ProjectConfig::ProjectConfig() {

	m_computeShadows = 1;
	m_dayStart = 1;
	m_dayEnd = 365;
	m_minuteStep = 30;
	m_dayStep = 1;
	mVoxelSize = 1;
	m_year = 2013;
	m_timezone = 1;
	m_lon = 0;
	m_lat = 0;
	m_openMp = 0;
}

ProjectConfig::~ProjectConfig() {
	// TODO Auto-generated destructor stub
}

bool ProjectConfig::loadFromFile(std::string filePath) {
	std::ifstream projectFile(filePath.c_str());

	if (!projectFile.good()) {
		return false;
	}

	getline(projectFile, mShadowPointsFilePath);
	getline(projectFile, mQueryPointsFilePath);

	std::string temp = "";

	getline(projectFile, temp);
	mVoxelSize = atof(temp.c_str());

	getline(projectFile, temp);
	m_lat = atof(temp.c_str());

	getline(projectFile, temp);
	m_lon = atof(temp.c_str());

	getline(projectFile, temp);
	m_timezone = atoi(temp.c_str());

	getline(projectFile, temp);
	m_year = atoi(temp.c_str());

	getline(projectFile, temp);
	m_dayStart = atoi(temp.c_str());

	getline(projectFile, temp);
	m_dayEnd = atoi(temp.c_str());

	getline(projectFile, temp);
	m_dayStep = atoi(temp.c_str());

	getline(projectFile, temp);
	m_minuteStep = atoi(temp.c_str());

	getline(projectFile, temp);
	m_computeShadows = atoi(temp.c_str());

	getline(projectFile, mOutputFilePath);


	getline(projectFile, temp);
	m_openMp = atoi(temp.c_str());


	std::cout << getSettingsString() << std::endl << std::endl;

	return true;
}


std::string ProjectConfig::getSettingsString() {

	std::string result = "";

	std::ostringstream convert;

	convert << "------------------------------------------------------" << std::endl;
	convert << "Shadow points file path:      " << mShadowPointsFilePath << std::endl;
	convert << "Query points file path:       " << mQueryPointsFilePath << std::endl;
	convert << "Output file(s) path:          " << mOutputFilePath << std::endl;
	convert << "Use Multithreading:           " << m_openMp << std::endl;
	convert << std::endl;

	convert << "Lat:                          " << m_lat << " degrees" << std::endl;
	convert << "Lon:                          " << m_lon << " degrees" << std::endl;
	convert << "Time Zone:                    " << m_timezone << std::endl << std::endl;

	convert << "Year:                         " << m_year << std::endl;
	convert << "Day Start:                    " << m_dayStart << std::endl;
	convert << "Day End:                      " << m_dayEnd << std::endl;
	convert << "Days step:                    " << m_dayStep << std::endl;
	convert << "Minutes step:                 " << m_minuteStep << std::endl;

	convert << std::endl;

	convert << "Shadow mode:                  " << m_computeShadows << std::endl;
	convert << "Shadow voxel size:            " << mVoxelSize << " m" << std::endl;
	convert << "------------------------------------------------------" << std::endl;

	result = convert.str();

	return result;
}
