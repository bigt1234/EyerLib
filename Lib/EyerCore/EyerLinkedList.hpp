#ifndef	EYER_LINKEDLIST_H
#define	EYER_LINKEDLIST_H

#include <stdio.h>
#include "EyerLinkedEle.hpp"

namespace Eyer {
    template <typename T>
    class EyerLinkedList
    {
    public:
        EyerLinkedList();
        ~EyerLinkedList();
        int circleElement();
        int insertEle(const T & data, int pos);
        int insertBack(const T & data);
        int deleteEle(int pos);
        int find(int pos, T & data) const;
        int getLength() const;
        int clear();

    private:
        EyerLinkedEle<T> * head;

    private:
        int length;

    };

    template <typename T>
    EyerLinkedList<T>::EyerLinkedList()
    {
        head = new EyerLinkedEle<T>(0);
        length = 0;
    }

    template <typename T>
    EyerLinkedList<T>::~EyerLinkedList()
    {
        if (length == 0) {
            delete head;
            head = nullptr;
            return;
        }

        while (head->next != nullptr)
        {
            EyerLinkedEle<T> * temp = head;
            head = head->next;
            //printf("delete temp:%d", temp->data);
            delete temp;
        }
        delete head;
        head = nullptr;
    }

    template <typename T>
    int EyerLinkedList<T>::insertEle(const T & data, int pos)
    {
        if (head == nullptr) {
            //printf("linkList is null \n");
            return -2;
        }

        if (pos < 1) {
            EyerLinkedEle<T> * temp = new EyerLinkedEle<T>(0);
            head->next = temp;
            head->data = data;
            length++;

            return 0;
        }
        else if (pos > length) {
            EyerLinkedEle<T> * temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            EyerLinkedEle<T> * tail = new EyerLinkedEle<T>(data);
            temp->next = tail;
            length++;
            
            //delete temp;
            return 0;
        }
        else {
            EyerLinkedEle<T> * temp = head;
            for (int i = 1; i < pos; i++) {
                temp = temp->next;
            }

            EyerLinkedEle<T> * newEle = new EyerLinkedEle<T>(data, temp->next);

            temp->next = newEle;

            length++;

            return 0;
        }
    }

    template <typename T>
    int EyerLinkedList<T>::insertBack(const T & data)
    {
        if (head == nullptr) {
            //printf("linkList is null \n");
            return -1;
        }

        if (length == 0) {
            head->data = data;
            length++;

            return 0;
        }

        EyerLinkedEle<T> * temp = head;
        while(temp->next != nullptr){
            //printf("int while: temp-data:%d \n", temp->data);
            temp = temp->next;
        }

        EyerLinkedEle<T> * newEle = new EyerLinkedEle<T>(data);
        temp->next = newEle;
        length++;
        return 0;
    }

    template <typename T>
    int EyerLinkedList<T>::deleteEle(int pos)
    {
        if (pos < 0 || pos > length - 1) {
            //printf("pos is out of range\n");
            return -1;
        }

        if (pos < 1) {
            EyerLinkedEle<T> * temp = head;
            head = temp->next;
            delete temp;
            length--;
            return 0;
        }else {
            EyerLinkedEle<T> * temp = head;
            for (int i = 1; i < pos ; i++) {
                temp = temp->next;
                //printf("before delete ele:%d\n", temp->data);
            }

            EyerLinkedEle<T> * deletedEle = temp->next;
            temp->next = deletedEle->next;
            
            delete deletedEle;
            length--;
            return 0;
        }
    }

    template <typename T>
    int EyerLinkedList<T>::circleElement()
    {
        //printf("in circleElement\n");
        EyerLinkedEle<T> * temp = head;
        while (temp->next != nullptr)
        {
            //printf("circle data: %d\n", temp->data);
            temp = temp->next;

        }
        return 0;
    }

    template <typename T>
    int EyerLinkedList<T>::find(int pos, T & data) const
    {
        if (pos < 0 || pos > length - 1) {
            //printf("pos is out of range\n");
            return -1;
        }

        EyerLinkedEle<T> * temp = head;
        for (int i = 0; i < pos ; i++) {
                temp = temp->next;
                //printf("before delete ele:%d\n", temp->data);
        }

        //printf("find data: %f\n", temp->data);
        data = temp->data;        
        return 0;
    }

    template <typename T>
    int EyerLinkedList<T>::getLength() const
    {
        return length;
    }

    template <typename T>
    int EyerLinkedList<T>::clear()
    {
        while(length > 0){
            deleteEle(length - 1);
        }
        head = new EyerLinkedEle<T>(0);
        return 0;
    }

}
#endif

