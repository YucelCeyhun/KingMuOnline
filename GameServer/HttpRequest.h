#include "StdAfx.h";


#define BASE_URL "http://localhost:81/"

class HttpRequest{
public:
	char* getVersion();
};

extern HttpRequest httpRequest;