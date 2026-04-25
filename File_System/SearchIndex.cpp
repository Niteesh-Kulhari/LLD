#include "SearchIndex.h"
using namespace std;

void SearchIndex::add(FileNode *f)
{
    index[f->getName()].insert(f);
}

void SearchIndex::remove(FileNode *f)
{
    auto &s = index[f->getName()];
    s.erase(f);
    if (s.empty())
        index.erase(f->getName());
}

vector<string> SearchIndex::search(const string &name)
{
    vector<string> res;
    if (index.count(name))
    {
        for (auto f : index[name])
        {
            res.push_back(f->getPath());
        }
    }

    return res;
}