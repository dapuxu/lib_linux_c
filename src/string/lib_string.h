#ifndef __LIB_STRING_H__
#define __LIB_STRING_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************************************************
**	函数名:String_Lib_Version
**	描	述:获取库版本号
**	参	数:无
**	返回值:版本号指针
********************************************************************************************************************/
char *String_Lib_Version(void);

/*******************************************************************************************************************
**	函数名:String_Select_Key
**	描	述:查询缓存中的字符串位置
**	参	数:[in]str:字符串
**		   [in]key:关键词
**	返回值:字符串中关键词所在的位置
********************************************************************************************************************/
char *String_Select_Key(char *str, char *key);

/*******************************************************************************************************************
**	函数名:String_Select_Key_Num
**	描	述:查询字符串中关键词个数
**	参	数:[in]str:字符串
**		   [in]key:关键词
**	返回值:关键词个数
********************************************************************************************************************/
unsigned short String_Select_Key_Num(char *str, char *key);

/*******************************************************************************************************************
**	函数名:String_Splicing
**	描	述:字符串拼接
**	参	数:[out]buf:缓存
**		   [in]buflen:缓存长度
**		   [in]front:前字符串
**		   [in]last:后字符串
**	返回值:字符串中关键词所在的位置
********************************************************************************************************************/
char String_Splicing(char *buf, unsigned short buflen, char *front, char *last);

/*******************************************************************************************************************
**	函数名:String_Splicing
**	描	述:字符串拼接
**	参	数:[in]data:数据
**	返回值:数据长度
********************************************************************************************************************/
char String_Length(char *data);

#ifdef __cplusplus
}
#endif

#endif
