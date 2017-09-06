#include "hiredis.h"

int main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	/* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
	wVersionRequested = MAKEWORD(2, 2);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		/* Tell the user that we could not find a usable */
		/* Winsock DLL.                                  */
		printf("WSAStartup failed with error: %d\n", err);
		return 1;
	}

	redisContext* rc = redisConnect("192.168.10.53", 19000);
	if (!rc || rc->err)
	{
		if (rc)
		{
			printf("connect error %s\n", rc->errstr);
		}
		else
		{
			printf("redis context init error!\n");
		}

		if (rc)
		{
			redisFree(rc);
			rc = NULL;
		}
	}

	redisReply* rp = (redisReply*)redisCommand(rc, "get a");
	if (rp)
		printf("rp xxxxxxxxx\n");
	else
		printf("rp 11111111111111\n");

	system("pause");

	return 0;
}