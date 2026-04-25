#ifndef SearchIndex_H
#define SearchIndex_H

#include "FileNode.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class SearchIndex
{
    unordered_map<string, unordered_set<FileNode *>> index;

public:
    void add(FileNode *f);
    void remove(FileNode *f);
    vector<string> search(const string &name);
};

#endif