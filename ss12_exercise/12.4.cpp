//
//  12.4.cpp
//  ss12_exercise
//
//  Created by 王星洲 on 2018/5/21.
//  Copyright © 2018年 cn.edu.tongji.1652977. All rights reserved.
//

#include "12.4.hpp"
#include <iostream>

Stack::Stack(int n)
{
    size = n;
    pitems = new Item [n];
    top = 0;
}
Stack::Stack(const Stack & st)
{
    size = st.size;
    pitems = new Item [st.size];
    top = st.top;
}
Stack::~Stack()
{
    delete [] pitems;
}
bool Stack::isempty() const
{
    if(top == 0)
    {
        return true;
    }
    else{
        return false;
    }
}
bool Stack::isfull() const
{
    if(top == size)
    {
        return true;
    }
    else{
        return false;
    }
}
bool Stack::push(const Item &item)
{
    if(top < size)
    {
        pitems[top++] = item;
        return true;
    }
    else{
        return false;
    }
}
bool Stack::pop(Item & item)
{
    if(top > 0)
    {
        pitems[--top] = item;
        return true;
    }
    else{
        return false;
    }
}
Stack & Stack::operator=(const Stack &st)
{
    size = st.size;
    if(pitems)
    {
        delete [] pitems;
    }
    pitems = new Item [st.size];
    top = st.top;
    return *this;
}


int main()
{
    using std::cout;
    using std::cin;
    Item p;
    Stack a;
    Stack b(a);
    cout<<a.isempty();
    cout<<b.isfull();
    cout<<a.push(1);
    Stack c(2);
    cout<<c.push(2);
    cout<<c.push(3);
    cout<<c.isfull();
    cin>>p;
    cout<<c.pop(p);
    cout<<c.isempty();
    return 0;
}
