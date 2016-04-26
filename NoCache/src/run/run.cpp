/**
 * ################################################
 * ################## Main Function ###############
 * ################################################
 *
 * Version: 1.0
 * File: run.cpp
 * Author: Jie Wang
 * Description: Main Function
 * Date: 2016-01-06
 * Copyright (C) 2016 NAOC-TJUCS
 **/


#include <iostream>
#include <map>
#include <list>
#include "../capacity/capacity.h"
#include "../file/file.h"
#include "../index/index.h"
#include "../mapxy/mapxy.h"
#include "../replacement/replacement.h"
#include "../request/request.h"
#include "../response/response.h"
#include "../struct/structs.h"
#include "../variables/variables.h"
#include "../utils/stringSplit.h"
#include "../track/track.h"

using namespace std;


int CACHE_HIT = 0;
double TOTAL_QOS = 0;

int main(){

	cout << "==========>>>>> START TO RUN <<<<<==========\n" << endl;

	cout << "==========>>>>>  INIT FILES  <<<<<==========\n" << endl;

	//files
	FileInfo files[NUM_FILES];

	//generate files
	initFiles(files);


	cout << "==========>>>>> GENERATE REQUESTS <<<<<==========\n" << endl;
	//store all the request
	list<RequestInfo> requestsList;

	//store all the request result
	list<RequestInfo> resultList;

	//requests' list's iterator
	list<RequestInfo>::iterator reqIter;

	//generate requests
//	genRequests(files, &requestsList);

	//generate requests from track
    genReqFromTrack(&requestsList);

	if(requestsList.size()>0) {
		cout << "==========>>>>> REQUESTS' NUM: " << requestsList.size() << " <<<<<==========\n" << endl;
	}

	cout << "==========>>>>> ALLOT TIME TO REQUESTS <<<<<==========\n" << endl;
//	allotTime2Request(&requestsList);


	if(requestsList.size()>0) {
		cout << "==========>>>>> REQUESTS' NUM: " << requestsList.size() << " <<<<<==========\n" << endl;
	}


	cout << "==========>>>>> START TO SERVE <<<<<==========\n" << endl;


	//Store all indexes
	map<string, list<IndexInfo> > indexMap;


	//serve
	double qos = 0;
	for(reqIter=requestsList.begin(); reqIter!=requestsList.end(); reqIter++) {
		qos = 0;
		qos = response((*reqIter).fileName, (*reqIter).startx,
				(*reqIter).starty, (*reqIter).endx, (*reqIter).endy, 0, 0);

		//update qos
		(*reqIter).qos = qos;
		//store result to new list
		resultList.push_back(*reqIter);

		//cout<<resultList.size()<<endl;
		TOTAL_QOS += qos;
		//OVER
	}


	cout<<"HitTimes:"<<CACHE_HIT<<"    HITRATE:"<<((double)CACHE_HIT/(double)resultList.size())<<endl;
	cout<<"TOTAL_QOS:"<<TOTAL_QOS<<"    AVGRAGE_QOS:"<<(TOTAL_QOS/(double)resultList.size())<<endl;

	stringstream hitRate;
	hitRate<<"RequestSize,HitTimes,HitRate,TotalQos,AvgrageQos\n"<<resultList.size()<<","
				<<CACHE_HIT<<","<<((double)CACHE_HIT/(double)resultList.size())<<","
				<<TOTAL_QOS<<","<<(TOTAL_QOS/(double)resultList.size())<<"\n";

	//record hitRate
	recordRate(hitRate.str());

	//Record resultList
	record(resultList);

}
