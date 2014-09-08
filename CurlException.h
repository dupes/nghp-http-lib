
#ifndef CURLEXCEPTION_H_
#define CURLEXCEPTION_H_

#include <exception>

#include <curl/curl.h>

using namespace std;

// CURL error codes: http://curl.haxx.se/libcurl/c/libcurl-errors.html

class CurlException : public exception
{
private:
	CURLcode m_result;
	char *m_message;

public:
	CurlException(CURLcode result, char *message);
	virtual ~CurlException() throw();

	const char* what() const throw();
	CURLcode curlCode();
};

#endif /* CURLEXCEPTION_H_ */
