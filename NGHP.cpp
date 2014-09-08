/*
 * NGHP.cpp
 *
 *  Created on: Sep 8, 2014
 *      Author: dupes
 */

#include "NGHP.h"

NGHP::NGHP(string host)
{
}

/********************************************************************************/


NGHP::~NGHP()
{
}

/********************************************************************************/

string NGHP::getQuery(string url)
{
	m_http.get(url);

	istringstream iss(m_http.getResponseBody());

	vector<string> tokens;
	string token;

	while(getline(iss, token, ' '))
		tokens.push_back(token);

	if (tokens.size() == 0)
		return "";

	return tokens[tokens.size() - 1];
}

/********************************************************************************/

string NGHP::getCVar(string var)
{
	string url = m_host + "/getcvar?" + var;

	return getQuery(url);
}

/********************************************************************************/


string NGHP::setCVar(string var, string value)
{
	string url = m_host + "/getcvar?" + var + "&" + value;

	return getQuery(url);
}

/********************************************************************************/


int NGHP::getCVarInt(string var)
{
	string value = getCVar(var);

	return atoi(value.c_str());
}

/********************************************************************************/


double NGHP::getCVarDouble(string var)
{
	string value = getCVar(var);

	return atof(value.c_str());
}

/********************************************************************************/

string NGHP::setCVarInt(string var, int value)
{
	stringstream ssValue;

	ssValue << value;

	return setCVar(var, ssValue.str());
}

/********************************************************************************/


string NGHP::setCVarDouble(string var, double value)
{
	stringstream ssValue;

	ssValue << value;

	return setCVar(var, ssValue.str());
}

/********************************************************************************/


string NGHP::setDuration(int duration)
{
	return setCVarInt("hp_duration", duration);
}

/********************************************************************************/


int NGHP::getDuration()
{
	return getCVarInt("hp_duration");
}

/********************************************************************************/

string NGHP::setReduction(double reduction)
{
	return setCVarDouble("hp_reduction", reduction);
}

/********************************************************************************/

double NGHP::getReduction()
{
	return getCVarDouble("hp_reduction");
}

/********************************************************************************/

string NGHP::getResponseCode()
{
	return m_http.getResponseCode();
}

/********************************************************************************/

string NGHP::getResponseMessage()
{
	return m_http.getResponseMessage();
}

/********************************************************************************/

string NGHP::getResponseBody()
{
	return m_http.getResponseBody();
}
