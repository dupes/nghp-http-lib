
#include "CurlBuffer.h"

CurlBuffer::CurlBuffer()
{
}

/********************************************************************************/

CurlBuffer::~CurlBuffer()
{

}

/********************************************************************************/

const char* CurlBuffer::contentBuffer()
{
	return m_content.c_str();
}

/********************************************************************************/

size_t CurlBuffer::numBytes()
{
	return m_content.length();
}

/********************************************************************************/

string CurlBuffer::content()
{
	return m_content;
}

/********************************************************************************/

void CurlBuffer::clear()
{
	m_content.clear();
}
