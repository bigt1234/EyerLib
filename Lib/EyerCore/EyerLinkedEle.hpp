#ifndef	Yao_LINKEDElE_H
#define	Yao_LINKEDElE_H

#include <stdio.h>

namespace Eyer {
    
    template <class T>
    class YaoLinkedEle
    {
    public:
        T data;
        YaoLinkedEle<T> * next;
    public:
        YaoLinkedEle<T>(T _data, YaoLinkedEle<T> * _next = nullptr){
            data = _data;
            next = _next;
        }
        ~YaoLinkedEle<T>(){
            
        }
    };  
}

#endif