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
	/**
	 * host: http://localhost http://10.10.0.1
	 * connectTimeout: delay in seconds to wait for tcp connect to complete
	 */
	NGHP(string host, int connectTimeout = 0);
	virtual ~NGHP();

	/**
	 * read a variable from the controller
	 * example variables: hp_duration, hp_reduction, hp_W
	 * expected return value: var = value
	 * example: hp_duration = 7200
	 */
	string getCVar(string var);

	/**
	 * set the value of a variable on the controller
	 * example variables: hp_duration, hp_reduciton
	 * expected return value: var = value OK
	 * example: hp_duration = 7200 OK
	 */
	string setCVar(string var, string value);

	/**
	 * reads a value from the controller and converts the result
	 *   to an int
	 * internally calls getCVar
	 */
	int getCVarInt(string var);

	/**
	 * reads a variable from the controller and converts the result
	 *   to a double
	 * internally calls getCVar
	 */
	double getCVarDouble(string var);

	/**
	 * writes a double variable to the controller
	 * internally calls setCVar
	 */
	string setCVarInt(string var, int value);
	string setCVarDouble(string var, double value);

	/**
	 * the next 5 convenience functions can be used to read and write
	 *   the 3 variables defined by the controller
	 * since hw_W is read only, only a get function is defined
	 */
	string setDuration(int duration);
	int getDuration();

	string setReduction(double reduction);
	double getReduction();

	int getCurrentPower();

	/**
	 * the following three functions are the HTTP response
	 * use them to determine if the HTTP call was
	 * successful
	 */
	string getResponseCode();
	string getResponseMessage();

	string getResponseBody();
};

#endif /* NGHP_H_ */
