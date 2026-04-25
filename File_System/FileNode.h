#ifndef FILENODE_H
#define FILENODE_H

#include "FSNode.h"

class FileNode : public FSNode
{
public:
    FileNode(string n, FSNode *p);
    bool isDir() override;
};

#endif