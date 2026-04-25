#include "Comment.hpp"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

Comment::Comment(string commentId, string userId, string content)
    : commentId(commentId), userId(userId), content(content)
{
    timestamp = time(nullptr);
}

string Comment::getCommentId() const
{
    return commentId;
}

string Comment::getUserId() const
{
    return userId;
}

string Comment::getContent() const
{
    return content;
}

time_t Comment::getTimestamp() const
{
    return timestamp;
}

void Comment::displayInfo() const
{
    cout << "- " << content << "(By User: " << userId << ")" << endl;
}