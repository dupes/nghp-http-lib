
#include "CurlReceiveBuffer.h"

CurlReceiveBuffer::CurlReceiveBuffer()
{
}

/********************************************************************************/

CurlReceiveBuffer::~CurlReceiveBuffer()
{
}

/********************************************************************************/

size_t CurlReceiveBuffer::receive(const char *buffer, size_t numBytes)
{
	m_content.append(buffer, numBytes);

	return numBytes;
}

/********************************************************************************/

void CurlReceiveBuffer::parse(map<string, string> &headers, map<string, string> &cookies, string &body, string &httpVersion, string &httpResponseCode, string &httpResponseMessage)
{
	stringstream ss(m_content);
	string line;
	string value;
	size_t totalBytesRead = 0;

	// HTTP version, response code, response message: HTTP/1.1 200 OK
	getline(ss, line, '\r');
	totalBytesRead += line.length() + 1;

	size_t pos = line.find(' ');
	size_t pos2 = line.find(' ', pos + 1);

	httpVersion = line.substr(0, pos);
	httpResponseCode = line.substr(pos + 1, 3);
	httpResponseMessage = line.substr(pos2 + 1); // ignore the final \r

	// discard the newline character
	getline(ss, line, '\n');

	while (getline(ss, line, '\r'))
	{
		string key;
		string value;

		// discard the newline character
		string discard;
		getline(ss, discard, '\n');

		// add two for the discarded carriage return and line feed characters
		totalBytesRead += line.length() + 2;

		// marks the end of the headers and the start of they body
		if (line.length() <= 1)
		{
			body = ss.str().substr(totalBytesRead+1);
			break;
		}

		// parse a header
		// ETag: "ce9fc5cb1bdd952d0b00d904ca96dac4"
		size_t pos = line.find(':');

		key = line.substr(0, pos);
		value = line.substr(pos+2); // skip the : and a space

		// TODO: does this compare need to be case insensitive?
		if (key.compare("Set-Cookie") == 0)
		{
			// parse a cookie
			// Set-Cookie: oadr_remember_token=; path=/; expires=Thu, 01-Jan-1970 00:00:00 GMT
			pos = value.find('=');

			key = value.substr(0, pos);
			value = value.substr(pos+1);

			cookies[key] = value;
		}
		else
			headers[key] = value;
	}
}
