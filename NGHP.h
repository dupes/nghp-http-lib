/*
 * NGHP.h
 *
 *  Created on: Sep 8, 2014
 *      Author: dupes
 */

#ifndef NGHP_H_
#define NGHP_H_

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>

#include "HttpCurl.h"

using namespace std;

class NGHP
{
private:
	string m_host;

	HttpCurl m_http;

	string getQuery(string url);

public:
	NGHP(string host);
	virtual ~NGHP();

	string getCVar(string var);
	string setCVar(string var, string value);

	int getCVarInt(string var);
	double getCVarDouble(string var);

	string setCVarInt(string var, int value);
	string setCVarDouble(string var, double value);

	string setDuration(int duration);
	int getDuration();

	string setReduction(double reduction);
	double getReduction();

	int getCurrentPower();

	string getResponseCode();
	string getResponseMessage();

	string getResponseBody();
};

#endif /* NGHP_H_ */
