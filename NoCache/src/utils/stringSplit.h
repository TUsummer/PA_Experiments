/**
 * ################################################
 * ################## String Split ################
 * ################################################
 *
 * Version: 1.0
 * File: stringSplit.h
 * Author: Jie Wang
 * Description: String Split
 * Date: 2016-01-07
 * Copyright (C) 2016 NAOC-TJUCS
 **/

#ifndef SRC_UTILS_STRINGSPLIT_H_
#define SRC_UTILS_STRINGSPLIT_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
 * FUNCTION: split
 * INPUT: string str && string pattern
 * OUTPUT: vector<string>
 * (SIDE)EFFECTS: string split
 */
vector<string> split(string str, string pattern);


#endif /* SRC_UTILS_STRINGSPLIT_H_ */
