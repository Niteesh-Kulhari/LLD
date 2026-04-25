#include "FSNode.h"
#include <algorithm>

FSNode::FSNode(string n, FSNode *p) : name(n), parent(p) {}

string FSNode::getName() { return name; }

string FSNode::getPath()
{
    vector<string> parts;
    FSNode *curr = this;
    while (curr && curr->parent)
    {
        parts.push_back(curr->name);
        curr = curr->parent;
    }

    reverse(parts.begin(), parts.end());
    string path = "/";
    for (int i = 0; i < parts.size(); i++)
    {
        path += parts[i];
        if (i != parts.size() - 1)
            path += "/";
    }

    return path;
}

FSNode::~FSNode() {}