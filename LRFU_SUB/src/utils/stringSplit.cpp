/**
 * ################################################
 * ################## String Split ################
 * ################################################
 *
 * Version: 1.0
 * File: stringSplit.cpp
 * Author: Jie Wang
 * Description: String Split
 * Date: 2016-01-07
 * Copyright (C) 2016 NAOC-TJUCS
 **/

#include "stringSplit.h"


/*
 * FUNCTION: split
 * INPUT: string str && string pattern
 * OUTPUT: vector<string>
 * (SIDE)EFFECTS: string split
 */
vector<string> split(string str,string pattern) {

	string::size_type pos;
	vector<string> result;

	str += pattern;

	int size=str.size();

	for(int i=0; i<size; i++) {
		pos=str.find(pattern,i);

		if(pos<size) {
			string s=str.substr(i,pos-i);
			result.push_back(s);
			i=pos+pattern.size()-1;
		}
	}

	return result;
}


