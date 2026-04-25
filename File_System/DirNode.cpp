#include "DirNode.h"

DirNode::DirNode(string n, FSNode *p) : FSNode(n, p) {}
bool DirNode::isDir() { return true; }

DirNode::~DirNode() {
    for (auto& [_, child] : children) {
        delete child;
    }
}