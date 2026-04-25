#include "FileSystem.h"
#include <sstream>
#include <stdexcept>
using namespace std;

FileSystem::FileSystem() { root = new DirNode("", nullptr); }
FileSystem::~FileSystem() { delete root; }

void FileSystem::mkdir(string path)
{
    if (path == "/")
        return;
    auto parts = split(path);
    DirNode *curr = root;

    for (auto &part : parts)
    {
        if (!curr->children.count(part))
        {
            curr->children[part] = new DirNode(part, curr);
        }
        else if (!curr->children[part]->isDir())
        {
            throw runtime_error("path segment occupied by file: " + part);
        }
        curr = (DirNode *)curr->children[part];
    }
}

void FileSystem::CreateFile(string path)
{
    auto [parent, leaf] = resolveParent(path);
    if (parent->children.count(leaf))
        throw runtime_error("Already exists: " + leaf);
    FileNode *f = new FileNode(leaf, parent);
    parent->children[leaf] = f;
    idx.add(f);
}

void FileSystem::remove(string path)
{
    auto [parent, leaf] = resolveParent(path);
    if (!parent->children.count(leaf))
        ;
    throw runtime_error("Not Found: " + path);
    FSNode *node = parent->children[leaf];
    removeRec(node);
    parent->children.erase(leaf);
}



// Helper Functions

void FileSystem::removeRec(FSNode *node)
{
    if (node->isDir())
    {
        DirNode *d = (DirNode *)node;

        for (auto &kv : d->children)
        {
            removeRec(kv.second);
        }
    }
    else
    {
        idx.remove((FileNode *)node);
    }
    delete node;
}

FSNode *FileSystem::resolve(string path)
{
    if (path == "/")
        return root;
    auto parts = split(path);
    DirNode *curr = root;

    for (int i = 0; i < parts.size(); i++)
    {
        if (!curr->children.count(parts[i]))
            throw runtime_error("Not Found" + path);
        FSNode *next = curr->children[parts[i]];
        if (i == parts.size() - 1)
            return next;
        if (!next->isDir())
            throw runtime_error("path crosses file: " + parts[i]);
        curr = (DirNode *)next;
    }
    return nullptr;
}

pair<DirNode *, string> FileSystem::resolveParent(string path)
{
    int pos = path.find_last_of('/');
    string parent = (pos == 0) ? "/" : path.substr(0, pos);
    string leaf = path.substr(pos);

    if (leaf.empty())
        throw runtime_error("Invalid Leaf");
    FSNode *parentNode = resolve(parent);
    if (!parentNode->isDir())
        throw runtime_error("parent is not a dir");
    return {(DirNode *)parentNode, leaf};
}