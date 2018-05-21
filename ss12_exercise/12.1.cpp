////
////  12.1.cpp
////  ss12_exercise
////
////  Created by 王星洲 on 2018/5/21.
////  Copyright © 2018年 cn.edu.tongji.1652977. All rights reserved.
////
//
//#include "12.1.hpp"
//#include <cstring>
//#include <iostream>
//
//Cow::Cow()
//{
//    hobby = new char [1];
//    name[0] = '\0';
//    hobby[0] = '\0';
//    weight = 0;
//    return;
//}
//Cow::Cow(const char *nm, const char *hm, double wt)
//{
//    strcpy(name, nm);
//    int len = strlen(hm);
//    hobby = new char [len + 1];
//    strcpy(hobby, hm);
//    weight = wt;
//}
//Cow::Cow(const Cow & a)
//{
//    hobby = new char [strlen(a.name) + 1];
//    strcpy(hobby, a.hobby);
//    strcpy(name,a.name);
//    weight = a.weight;
//}
//Cow::~Cow()
//{
//    delete [] hobby;
//}
//Cow & Cow::operator = (const Cow & c)
//{
//    strcpy(name, c.name);
//    int len = strlen(c.hobby);
//    delete [] hobby;
//    hobby = new char [len + 1];
//    strcpy(hobby, c.hobby);
//    weight = c.weight;
//    return *this;
//}
//void Cow::showCow() const
//{
//    std::cout<<name<<'\t'<<hobby<<'\t'<<weight<<'\n';
//}
//
//
//
//int main()
//{
//    Cow b("12","13",23.2);
//    Cow a;
//    a = b;
//    b.showCow();
//    a.showCow();
//    Cow c("23","24",25.4);
//    Cow d(c);
//    d.showCow();
//    return 0;
//}
