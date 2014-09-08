#ifndef CURLRECEIVEBUFFER_H_
#define CURLRECEIVEBUFFER_H_

#include <string>
#include <sstream>
#include <map>

#include "CurlBuffer.h"

using namespace std;

class CurlReceiveBuffer : public CurlBuffer
{
private:
public:
	CurlReceiveBuffer();

	virtual ~CurlReceiveBuffer();

	size_t receive(const char *buffer, size_t numBytes);

	void parse(map<string, string> &headers, map<string, string> &cookies, string &body, string &httpVersion, string &httpResponseCode, string &httpResponseMessage);
};

#endif /* CURLRECEIVEBUFFER_H_ */
