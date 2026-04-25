#ifndef FSNODE_H
#define FSNODE_H

#include<vector>
#include<string>
using namespace std;


class FSNode{
    protected:
        string name;
        FSNode* parent;

    public:
        FSNode(string n, FSNode* p);
            virtual bool isDir() = 0;
            string getName();
            string getPath();
            virtual ~FSNode();
};

#endif