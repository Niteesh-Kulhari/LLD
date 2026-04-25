#include "FileNode.h"

FileNode::FileNode(string n, FSNode *p) : FSNode(n, p) {}
bool FileNode::isDir() { return false; }