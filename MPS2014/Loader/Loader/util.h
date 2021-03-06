#ifdef __unix__
#include <unistd.h>
#endif
#ifdef _WIN32
#include <windows.h>
#endif

void mySleep(int sleepMs)
{
#ifdef __unix__
    usleep(sleepMs * 1000);   // usleep takes sleep time in us (1 millionth of a second)
#endif
#ifdef _WIN32
    Sleep(sleepMs);
#endif
}

	void assert(int err, char* msg="")
	{
		if(err==0)
			std::cout<<"Eroare!"<<msg<<errno;
	}

	void assert(void* err, char* msg="")
	{
		if(err==NULL)
			std::cout<<"Eroare!"<<msg;
	}

	WCHAR* toWchar(char *text, WCHAR *buffer, int len_buffer)
	{
		MultiByteToWideChar( 0,0, text, -1, buffer, len_buffer);

		return buffer;
	}

	char* toChar(WCHAR *text, char *buffer, int len_buffer)
	{
		size_t ret;
		wcstombs_s(&ret, buffer, len_buffer, text, len_buffer);
		if (ret==len_buffer) buffer[len_buffer-1]='\0';

		return buffer;
	}