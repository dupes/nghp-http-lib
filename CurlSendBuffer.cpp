#include "CurlSendBuffer.h"

/********************************************************************************/

CurlSendBuffer::CurlSendBuffer()
{
	m_bytesSent = 0;
}

/********************************************************************************/

CurlSendBuffer::~CurlSendBuffer()
{
}

/********************************************************************************/

void CurlSendBuffer::initialize(string content)
{
	m_content = content;

	m_bytesSent = 0;
}

/********************************************************************************/

size_t CurlSendBuffer::send(char *buffer, size_t maxBytes)
{
	size_t remainingBytes = m_content.size() - m_bytesSent;
	size_t bytesToCopy = (maxBytes < remainingBytes ? maxBytes : remainingBytes);

	memcpy(buffer, m_content.c_str() + m_bytesSent, bytesToCopy);

	m_bytesSent += bytesToCopy;

	return bytesToCopy;
}


