#include "Post.hpp"
#include "Comment.hpp"

#include <string>
#include <vector>
#include <ctime>
#include <iostream>

using namespace std;

Post::Post(string postId, string userId, string content, const vector<string> &tags, PostType type)
    : postId(postId), userId(userId), content(content), tags(tags), type(type), score(0), accepted(false)
{
    timestamp = time(nullptr);
}

Post::~Post()
{
    for (auto comment : comments)
    {
        delete comment;
    }
}

string Post::getPostId() const { return postId; }
string Post::getUserId() const { return userId; }
string Post::getContent() const { return content; }
const vector<string> &Post::getTags() const { return tags; }
const vector<Comment *> &Post::getComments() const { return comments; }
int Post::getScore() const { return score; }
bool Post::isAccepted() const { return accepted; }
PostType Post::getType() const { return type; }
time_t Post::getTime() const { return timestamp; }

void Post::addComment(Comment *Comment)
{
    comments.push_back(Comment);
}

bool Post::addVote(const string &userId)
{
    if (find(votes.begin(), votes.end(), userId) == votes.end())
    {
        votes.push_back(userId);
        score++;
        return true;
    }

    return false;
}

bool Post::removeVote(string &userId)
{
    auto it = find(votes.begin(), votes.end(), userId);
    if (it != votes.end())
    {
        votes.erase(it);
        score--;
        return true;
    }

    return false;
}

void Post::setAccepted(bool status)
{
    accepted = status;
}

void Post::displayInfo() const
{
    cout << "\nPost ID: " << postId << endl;
    cout << "Type: " << (type == PostType::QUESTION ? "Question" : "Answer") << endl;
    cout << "Content: " << content << endl;
    cout << "Score: " << score << endl;
    cout << "Status: " << (accepted ? "Accepted" : "Not Accepted") << endl;

    if (!tags.empty())
    {
        cout << "Tags: ";
        for (const auto &tag : tags)
        {
            cout << tag << " ";
        }
        cout << endl;
    }

    if (!comments.empty())
    {
        cout << "Comments: " << endl;
        for (const auto &comment : comments)
        {
            comment->displayInfo();
        }
    }

    cout << "Time: " << ctime(&timestamp) << endl;
}