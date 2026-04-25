#ifndef FileSystem_H
#define FileSystem_H

#include "DirNode.h"
#include "FileNode.h"
#include "SearchIndex.h"
#include <string>
#include <vector>
#include <utility>
using namespace std;

class FileSystem
{
    DirNode *root;
    SearchIndex idx;

public:
    FileSystem();
    ~FileSystem();

    void mkdir(string path);
    void CreateFile(string path);
    void remove(string path);
    vector<string> ls(string path);
    vector<string> searchByname(string name);

private:
    void removeRec(FSNode *node);
    FSNode *resolve(string path);
    pair<DirNode *, string> resolveParent(string path);
    vector<string> split(string path);
};

#endif