
#include "CurlException.h"

CurlException::CurlException(CURLcode result, char *message) :
	m_result(result),
	m_message(message)
{
}

/********************************************************************************/

CurlException::~CurlException()  throw()
{
}

/********************************************************************************/

const char* CurlException::what() const throw()
{
	return m_message;
}

/********************************************************************************/

CURLcode CurlException::curlCode()
{
	return m_result;
}
