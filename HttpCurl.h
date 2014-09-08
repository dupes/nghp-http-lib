#ifndef HTTPCURL_H_
#define HTTPCURL_H_

#include <time.h>
#include <map>
#include <iostream>

#include <errno.h>

#include <curl/curl.h>

#include "CurlException.h"
#include "CurlSendBuffer.h"
#include "CurlReceiveBuffer.h"

class HttpCurl
{
private:
	static bool m_curlInitialized;
	static int m_instanceCount;

	struct curl_slist *m_requestHeaders;

	char m_message[CURL_ERROR_SIZE];
	CURL *m_curl;
	CurlReceiveBuffer m_receiveBuffer;
	CurlSendBuffer m_sendBuffer;

	map<string, string> m_headers;
	map<string, string> m_cookies;

	string m_httpResponseCode;
	string m_httpResponseMessage;

	string m_httpVersion;
	string m_responseBody;

	size_t readFunction(void *ptr, size_t size, size_t nmemb);
	friend size_t readFunction(void *ptr, size_t size, size_t nmemb, void *userdata);

	size_t writeFunction(char *ptr, size_t size, size_t nmemb);
	friend size_t writeFunction(char *ptr, size_t size, size_t nmemb, void *userdata);

	void initRequest(string url);

	void perform();

public:
	HttpCurl();
	virtual ~HttpCurl();

	bool post(string url, string content);
	bool get(string url, string parameter, string value);

	string getRequestBody();
	string getResponseBody();

	string getResponseCode();
	string getResponseMessage();

	time_t getResponseTime();
	string getServerDate();
};

#endif /* HTTPCURL_H_ */
