//
//  Header.h
//  bb
//
//  Created by 王星洲 on 2018/4/13.
//  Copyright © 2018年 王星洲. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <cstring>
#include <iostream>

using namespace std;

class MyString
{
private:
    char *m_szString;
    int m_nLength;
public:
    MyString(const char* a = "");
    MyString(const MyString &);
    ~MyString();
    int size()const{return m_nLength;}
    MyString &append(const char*);
    MyString &append(const MyString &);
    friend ostream & operator<<(ostream &, const MyString &);
    friend bool operator == (const MyString &, const MyString &);
    friend bool operator != (const MyString &, const MyString &);
    friend bool operator >= (const MyString &, const MyString &);
    friend bool operator <= (const MyString &, const MyString &);
    friend bool operator < (const MyString &, const MyString &);
    friend bool operator > (const MyString &, const MyString &);
    char &operator[](int i);
    const char &operator[](int i)const{return m_szString[i];}
};

#endif /* Header_h */
inline MyString::MyString(const char * a)
{
    m_nLength = strlen(a);
    m_szString = new char[strlen(a) + 1 + 1];
    memmove(m_szString, a, m_nLength + 1);
    m_szString[m_nLength + 1] = 1;
}
inline MyString::MyString(const MyString & a):m_szString(a.m_szString),m_nLength(a.m_nLength)
{
    m_szString[m_nLength + 1] ++;
}
inline MyString::~MyString()
{
    if(m_szString != NULL)
    {
        if(m_szString && --m_szString[m_nLength + 1]==0)
        {
            delete [] m_szString;
            m_nLength = 0;
        }
    }
}
char & MyString::operator[](int i)
{
    if(m_szString[m_nLength + 1] >= 2)
    {
        --m_szString[m_nLength + 1];
        char * newString = new char [m_nLength + 1];
        memmove(newString, m_szString, m_nLength);
        m_szString = newString;
        m_szString[m_nLength + 1] = 1;
        return m_szString[i];
    }
    else
        return m_szString[i];
}
MyString &MyString::append(const char* a)
{
    if(m_szString)
    {
        char* temp = m_szString;
        m_szString= new char[m_nLength + strlen(a) + 1];
        memcpy(m_szString, temp, m_nLength);
        temp[m_nLength + 1]--;
        if(!temp[m_nLength + 1])
        {
            delete[] temp;
        }
        memcpy(m_szString+ m_nLength, a, strlen(a));
        m_nLength= m_nLength + strlen(a);
        m_szString[m_nLength+ 1] = 1;
        return *this;
    }
    else
    {
        m_nLength= strlen(a);
        m_szString= new char[m_nLength+1];
        strcpy(m_szString,a);
        m_szString[m_nLength+ 1] = 1;
        return *this;
    }
}
MyString &MyString::append(const MyString & a)
{
    if(m_szString)
    {
        char* temp = m_szString;
        m_szString= new char[m_nLength + a.size() + 1];
        memcpy(m_szString, temp, m_nLength);
        temp[m_nLength + 1]--;
        if(!temp[m_nLength + 1])
        {
            delete[] temp;
        }
        memcpy(m_szString+ m_nLength, a.m_szString, a.size());
        m_nLength= m_nLength + a.size();
        m_szString[m_nLength+ 1] = 1;
        return *this;
    }
    else
    {
        m_nLength= a.size();
        m_szString= new char[m_nLength+1];
        memcpy(m_szString, a.m_szString, a.size());
        m_szString[m_nLength+ 1] = 1;
        return *this;
    }
}
ostream &operator <<(ostream & os, const MyString & a)
{
    os<<a.m_szString;
    return os;
}
bool operator ==(const MyString & a, const MyString & b)
{
    return (!memcmp(a.m_szString, b.m_szString,(a.m_nLength>b.m_nLength)?a.m_nLength:b.m_nLength));
}
bool operator !=(const MyString & a, const MyString & b)
{
    return (memcmp(a.m_szString, b.m_szString,(a.m_nLength>b.m_nLength)?a.m_nLength:b.m_nLength));
}
bool operator >(const MyString & a, const MyString & b)
{
    return (memcmp(a.m_szString, b.m_szString,(a.m_nLength>b.m_nLength)?a.m_nLength:b.m_nLength)> 0);
}
bool operator <(const MyString & a, const MyString & b)
{
    return (memcmp(a.m_szString, b.m_szString,(a.m_nLength>b.m_nLength)?a.m_nLength:b.m_nLength)<0);
}
bool operator >=(const MyString & a, const MyString & b)
{
    return (memcmp(a.m_szString, b.m_szString,(a.m_nLength>b.m_nLength)?a.m_nLength:b.m_nLength)>=0);
}
bool operator <=(const MyString & a, const MyString & b)
{
    return (memcmp(a.m_szString, b.m_szString,(a.m_nLength>b.m_nLength)?a.m_nLength:b.m_nLength)<=0);
}
