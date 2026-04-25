#ifndef DirNode_H
#define DirNode_H

#include "FSNode.h"
#include "unordered_map"

class DirNode : public FSNode
{
public:
    unordered_map<string, FSNode*> children;
    DirNode(string n, FSNode *p);
    bool isDir() override;
    ~DirNode();
};

#endif