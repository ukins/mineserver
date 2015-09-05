#include "stdafx.h"
#include "charset.h"

std::string UTF8ToGBK( const std::string& strUTF8 )
{
	int len = MultiByteToWideChar( CP_UTF8, 0, strUTF8.c_str(), -1, NULL, 0 );
	unsigned short * wszGBK = new unsigned short[len + 1];
	memset( wszGBK, 0, len * 2 + 2 );
	MultiByteToWideChar( CP_UTF8, 0, (LPCCH)strUTF8.c_str(), -1, (LPWSTR)wszGBK, len );

	len = WideCharToMultiByte( CP_ACP, 0, (LPWSTR)wszGBK, -1, NULL, 0, NULL, NULL );
	char *szGBK = new char[len + 1];
	memset( szGBK, 0, len + 1 );
	WideCharToMultiByte( CP_ACP, 0, (LPWSTR)wszGBK, -1, szGBK, len, NULL, NULL ); //strUTF8 = szGBK; 
	std::string strTemp( szGBK );
	delete[]szGBK;
	delete[]wszGBK;
	return strTemp;
}

std::string GBKToUTF8( const std::string& strGBK )
{
	std::string strOutUTF8 = "";
	WCHAR * str1;
	int n = MultiByteToWideChar( CP_ACP, 0, strGBK.c_str(), -1, NULL, 0 );
	str1 = new WCHAR[n];
	MultiByteToWideChar( CP_ACP, 0, strGBK.c_str(), -1, str1, n ); n = WideCharToMultiByte( CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL );
	char * str2 = new char[n];
	WideCharToMultiByte( CP_UTF8, 0, str1, -1, str2, n, NULL, NULL );
	strOutUTF8 = str2;
	delete[]str1;
	str1 = NULL;
	delete[]str2;
	str2 = NULL;
	return strOutUTF8;
}


void UTF_8ToUnicode( wchar_t* pOut, char *pText )

{

	char* uchar = (char *)pOut;

	uchar[1] = ((pText[0] & 0x0F) << 4) + ((pText[1] >> 2) & 0x0F);

	uchar[0] = ((pText[1] & 0x03) << 6) + (pText[2] & 0x3F);

	return;

}

void UnicodeToUTF_8( char* pOut, wchar_t* pText )

{

	// 注意 WCHAR高低字的顺序,低字节在前，高字节在后  

	char* pchar = (char *)pText;

	pOut[0] = (0xE0 | ((pchar[1] & 0xF0) >> 4));

	pOut[1] = (0x80 | ((pchar[1] & 0x0F) << 2)) + ((pchar[0] & 0xC0) >> 6);

	pOut[2] = (0x80 | (pchar[0] & 0x3F));

	return;

}

void UnicodeToGB2312( char* pOut, wchar_t uData )

{

	WideCharToMultiByte( CP_ACP, NULL, &uData, 1, pOut, sizeof( wchar_t ), NULL, NULL );

	return;

}

void Gb2312ToUnicode( wchar_t* pOut, char *gbBuffer )

{

	::MultiByteToWideChar( CP_ACP, MB_PRECOMPOSED, gbBuffer, 2, pOut, 1 );

	return;

}

void GB2312ToUTF_8( std::string& pOut, char *pText, int pLen )

{

	char buf[4];

	int nLength = pLen * 3;

	char* rst = new char[nLength];

	memset( buf, 0, 4 );

	memset( rst, 0, nLength );

	int i = 0;

	int j = 0;

	while ( i < pLen )

	{

		//如果是英文直接复制就可以  

		if ( *(pText + i) >= 0 )

		{

			rst[j++] = pText[i++];

		}

		else

		{

			wchar_t pbuffer;

			Gb2312ToUnicode( &pbuffer, pText + i );

			UnicodeToUTF_8( buf, &pbuffer );

			unsigned short int tmp = 0;

			tmp = rst[j] = buf[0];

			tmp = rst[j + 1] = buf[1];

			tmp = rst[j + 2] = buf[2];

			j += 3;

			i += 2;

		}

	}

	rst[j] = '\0';

	//返回结果  

	pOut = rst;

	delete[]rst;

	return;

}

void UTF_8ToGB2312( std::string &pOut, char *pText, int pLen )

{

	char * newBuf = new char[pLen];

	char Ctemp[4];

	memset( Ctemp, 0, 4 );

	int i = 0;

	int j = 0;

	while ( i < pLen )

	{

		if ( pText > 0 )

		{

			newBuf[j++] = pText[i++];

		}

		else

		{

			WCHAR Wtemp;

			UTF_8ToUnicode( &Wtemp, pText + i );

			UnicodeToGB2312( Ctemp, Wtemp );

			newBuf[j] = Ctemp[0];

			newBuf[j + 1] = Ctemp[1];

			i += 3;

			j += 2;

		}

	}

	newBuf[j] = '\0';

	pOut = newBuf;

	delete[]newBuf;

	return;

}