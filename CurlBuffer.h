#ifndef CURLBUFFER_H_
#define CURLBUFFER_H_

#include <string>

using namespace std;

class CurlBuffer
{
protected:
	string m_content;

public:
	CurlBuffer();
	virtual ~CurlBuffer();

	const char* contentBuffer();
	size_t numBytes();

	string content();

	void clear();
};

#endif /* CURLBUFFER_H_ */
