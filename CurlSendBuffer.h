#ifndef CURLSENDBUFFER_H_
#define CURLSENDBUFFER_H_

#include <string>
#include <string.h>

#include "CurlBuffer.h"

using namespace std;

class CurlSendBuffer : public CurlBuffer
{
private:
	size_t m_bytesSent;

public:
	CurlSendBuffer();
	virtual ~CurlSendBuffer();

	void initialize(string contents);

	size_t send(char *buffer, size_t maxBytes);
};

#endif /* CURLSENDBUFFER_H_ */
