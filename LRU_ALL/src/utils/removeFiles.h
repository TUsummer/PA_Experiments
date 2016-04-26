/*
 * removeFiles.h
 *
 *  Created on: Jan 11, 2016
 *      Author: Wang
 */

#ifndef SRC_UTILS_REMOVEFILES_H_
#define SRC_UTILS_REMOVEFILES_H_

#include <stdio.h>
#include <dirent.h>
#include <vector>
#include <iostream>

using namespace std;


//get Files' name
void getFileNames(vector<string> *fileNames);


//remove files
void removeFiles();


#endif /* SRC_UTILS_REMOVEFILES_H_ */
