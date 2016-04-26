/*
 * removeFiles.cpp
 *
 *  Created on: Jan 11, 2016
 *      Author: hong
 */

#include "removeFiles.h"
#include "../variables/variables.h"


//get Files' name
void getFileNames(vector<string> *fileNames) {
    int return_code;
    DIR *dir;
    struct dirent entry;
    struct dirent *res;
    string real_dir = SSD_TARGET_PATH;//搜索的目录
    if ((dir = opendir(real_dir.c_str())) != NULL) {//打开目录
        for (return_code = readdir_r(dir, &entry, &res);res != NULL && return_code == 0;return_code = readdir_r(dir, &entry, &res)) {
            if (entry.d_type != DT_DIR) {//存放到列表中
                (*fileNames).push_back(string(real_dir+entry.d_name));
            }
        }
        closedir(dir);//关闭目录
    }
}


//remove files
void removeFiles(){

	 vector<string> fileNames;
	 getFileNames(&fileNames);

	 int size = fileNames.size();

	 for(int i=0; i<size; i++){
		 if(remove(fileNames[i].c_str())) {
			 printf("Could not delete the file");
		 }
	 }
}



