#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "student.h"

using namespace std;

template <typename T>
class Node
{
public:
    T val;
    Node* next;
    Node(T _val) : val(_val), next(nullptr){}
    Node(): next(nullptr){}
};

template <typename T>
class list
{
public:

    Node<T>* first;
    Node<T>* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty()
    {
        return first == nullptr;
    }

    void push_back(T _val)
    {
        Node<T>* p = new Node<T>(_val);
        if (is_empty())
        {
          first = p;
          last = p;
          return;
        }
        last->next = p;
        last = p;
    }

    Node<T>* find(T _val)
    {
        Node<T>* p = first;
        while (p && p->val != _val)
            p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }

    void pop_back()
    {
        if (is_empty())
            return;
        Node<T>* p = first;
        while (p->next != last)
            p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void remove(T _val)
    {
        if (is_empty())
            return;

        if (last->val == _val)
        {
            pop_back();
            return;
        }

        Node<T>* p= first;
        Node<T>* n= first->next;

        while (p && p->val != _val)
        {
            n = n->next;
            p = p->next;
        }
        if (!p)
        {
            cout << "This element does not exist\n";
            return;
        }

        p=p->next;

        //delete p;
    }

    T operator[] (const int index)
    {
        if (is_empty())
            return nullptr;
        Node<T>* p = first;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
            if (!p)
                return nullptr;
        }
        return p->val;
    }

    size_t size()
    {
        if (is_empty())
            return 0;
        size_t count=0;
        Node<T>* p = first;
        while (p)
        {
            ++count;
            p = p->next;
        }
        return count;
    }

    void fileRead(string name) //минимум 3 параметра (int , string, int) иначе п*здец
    {
        ifstream file(name);
        string str, word = "";


        while(file>>str)
        {
            vector<string> allWords;
            for(int i=0;i<str.size();++i)
            {
                if(str[i]==';')
                {
                    allWords.push_back(word);
                    word="";
                }
                else
                    word.push_back(str[i]);
            }

            if(allWords[0].find("age=") != string::npos)
                allWords[0].replace(allWords[0].find("age="), 4, "");
            if(allWords[1].find("name=") != string::npos)
                allWords[1].replace(allWords[1].find("name="), 5, "");
            if(allWords[2].find("iq=") != string::npos)
                allWords[2].replace(allWords[2].find("iq="), 3, "");
            //cerr<<allWords[0] << allWords[1] <<allWords[2];
            T newWord(stoi(allWords[0]), allWords[1], stoi(allWords[2]));
            //cerr<<newWord;
            push_back(newWord);
        }
    }

    void fileWrite(string name)
    {
        ofstream file(name);
        if (is_empty())
            return;
        Node<T>* p = first;
        while(p)
        {
            file<<p->val;
            p = p->next;
        }
    }
};




template <typename T>
ostream& operator<<(ostream& out, list<T> f)
{
    if (f.is_empty())
    {
        cerr<<"list empty";
        return out;
    }

    Node<T>* p = f.first;
    //cerr<<"here we go"<<p->val;
    while (p)
    {
        out << p->val;
        p = p->next;
    }
    out << "\n";
    return out;
}

