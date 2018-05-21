//
//  12.4.hpp
//  ss12_exercise
//
//  Created by 王星洲 on 2018/5/21.
//  Copyright © 2018年 cn.edu.tongji.1652977. All rights reserved.
//

#ifndef _2_4_hpp
#define _2_4_hpp

typedef unsigned long Item;

class Stack
{
private:
    enum {MAX = 10};
    Item * pitems;
    int size;
    int top;
public:
    Stack(int n = MAX);
    Stack(const Stack & st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
    Stack & operator =(const Stack &st);
};

#endif /* _2_4_hpp */
