#ifndef	Yao_LINKEDLIST_H
#define	Yao_LINKEDLIST_H

#include <stdio.h>
#include "EyerLinkedEle.hpp"

namespace Eyer {
    template <class T>
    class YaoLinkedList
    {
    public:
        YaoLinkedList();
        ~YaoLinkedList();
        int circleElement();
        int insertEle(YaoLinkedEle<T> * ele, int pos);
        int deleteEle(int pos);
        int find(int pos, T & data);

    public:
        int length;
        YaoLinkedEle<T> * head;
    };

    template <class T>
    YaoLinkedList<T>::YaoLinkedList()
    {
        head = new YaoLinkedEle<T>(0);
        length = 0;
    }

    template <class T>
    YaoLinkedList<T>::~YaoLinkedList()
    {
        if (length == 0) {
            delete head;
            head = nullptr;
            return;
        }

        while (head->next != nullptr)
        {
            YaoLinkedEle<T> * temp = head;
            head = head->next;
            //printf("delete temp:%d", temp->data);
            delete temp;
        }
        delete head;
        head = nullptr;
    }

    template <class T>
    int YaoLinkedList<T>::insertEle(YaoLinkedEle<T> * ele, int pos)
    {
        if (ele == nullptr) {
            printf("element is null\n");
            return -1;
        }
        if (head == nullptr) {
            printf("linkList is null \n");
            return -2;
        }

        if (pos < 1) {
            YaoLinkedEle<T> * temp = new YaoLinkedEle<T>(0);
            head->next = temp;
            head->data = ele->data;
            length++;

            return 0;
        }
        else if (pos > length) {
            YaoLinkedEle<T> * temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            YaoLinkedEle<T> * tail = new YaoLinkedEle<T>(ele->data);
            temp->next = tail;
            length++;
            
            //delete temp;
            return 0;
        }
        else {
            YaoLinkedEle<T> * temp = head;
            for (int i = 1; i < pos; i++) {
                temp = temp->next;
            }

            YaoLinkedEle<T> * newEle = new YaoLinkedEle<T>(ele->data, temp->next);

            temp->next = newEle;

            length++;

            return 0;
        }
    }

    template <class T>
    int YaoLinkedList<T>::deleteEle(int pos)
    {
        if (pos < 0 || pos > length - 1) {
            printf("pos is out of range\n");
            return -1;
        }

        if (pos < 1) {
            YaoLinkedEle<T> * temp = head;
            head = temp->next;
            delete temp;
            length--;
            return 0;
        }else {
            YaoLinkedEle<T> * temp = head;
            for (int i = 1; i < pos ; i++) {
                temp = temp->next;
                //printf("before delete ele:%d\n", temp->data);
            }

            YaoLinkedEle<T> * deletedEle = temp->next;
            temp->next = deletedEle->next;
            
            delete deletedEle;
            length--;
            return 0;
        }
    }

    template <class T>
    int YaoLinkedList<T>::circleElement()
    {
        //printf("in circleElement\n");
        YaoLinkedEle<T> * temp = head;
        while (temp->next != nullptr)
        {
            //printf("circle data: %f\n", temp->data);
            temp = temp->next;

        }
        return 0;
    }

    template <class T>
    int YaoLinkedList<T>::find(int pos, T & data)
    {
        if (pos < 0 || pos > length - 1) {
            printf("pos is out of range\n");
            return -1;
        }

        YaoLinkedEle<T> * temp = head;
        for (int i = 0; i < pos ; i++) {
                temp = temp->next;
                //printf("before delete ele:%d\n", temp->data);
        }

        //printf("find data: %f\n", temp->data);
        data = temp->data;        
        return 0;
    }
}
#endif

