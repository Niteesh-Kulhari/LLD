#include "StackOverflow.hpp"
#include <iostream>
#include <algorithm>

StackOverflow::StackOverflow() : userIdCounter(1), postIdCounter(1), commentIdCounter(1) {}

StackOverflow::~StackOverflow()
{
    for (auto user : users)
        delete user;
    for (auto post : posts)
        delete post;
}

// User Management
User *StackOverflow::registerUser(const string &userName, const string &email)
{
    string userId = generateUserId();
    User *user = new User(userId, userName, email);
    users.push_back(user);
    return user;
}

void StackOverflow::removeUser(const string &userId)
{
    auto it = find_if(users.begin(), users.end(),
                      [userId](User *user)
                      { return user->getUserId() == userId; });

    if (it != users.end())
    {
        delete *it;
        users.erase(it);
    }
}

// Post Management

Post *StackOverflow::createQuestion(const string &userId, const string &content, vector<string> &tags)
{
    if (!findUser(userId))
        return nullptr;

    string postId = generatePostId();
    Post *question = new Post(postId, userId, content, tags, PostType::QUESTION);
    posts.push_back(question);
    return question;
}

Post *StackOverflow::createAnswer(const string &userId, const string &questionId, const string &content)
{
    if (!findUser(userId))
        return nullptr;

    Post *question = findPost(questionId);
    if (!question || question->getType() != PostType::QUESTION)
        return nullptr;

    string postId = generatePostId();
    Post *answer = new Post(postId, userId, content, vector<string>(), PostType::ANSWER);
    posts.push_back(answer);
    return answer;
}

Comment *StackOverflow::createComment(const string &userId, const string &postId, const string &content)
{
    if (!findUser(userId))
        return nullptr;

    Post *post = findPost(postId);
    if (!post)
        return nullptr;

    string commentId = generateCommentId();
    Comment *comment = new Comment(commentId, userId, content);
    post->addComment(comment);
    return comment;
}

bool StackOverflow::votePost(const string &userId, const string &postId)
{
    User *user = findUser(userId);
    Post *post = findPost(postId);

    if (!user || !post || userId == post->getUserId())
        return false;

    if (post->addVote(userId))
    {
        updateUserReputation(post->getUserId(), 10);
        return true;
    }
    return false;
}

bool StackOverflow::unvotePost(const string &userId, const string &postId)
{
    if (!findUser(userId))
        return false;
    Post *post = findPost(postId);
    if (!post)
        return false;

    if (post->removeVote(userId))
    {
        updateUserReputation(post->getUserId(), -10);
        return true;
    }

    return false;
}

bool StackOverflow::acceptAnswer(const string &userId, const string &answerId)
{
    Post *answer = findPost(answerId);
    if (!answer || answer->getType() != PostType::ANSWER)
        return false;

    answer->setAccepted(true);
    updateUserReputation(answer->getUserId(), 15);
    return true;
}

User *StackOverflow::findUser(const string &userId) const
{
    for (auto user : users)
    {
        if (user->getUserId() == userId)
        {
            return user;
        }
    }

    return nullptr;
}

Post *StackOverflow::findPost(const string &postId) const
{
    auto it = find_if(posts.begin(), posts.end(),
                      [postId](Post *post)
                      { return post->getPostId() == postId; });

    return it != posts.end() ? *it : nullptr;
}

void StackOverflow::updateUserReputation(const string &userId, int points)
{
    if (User *user = findUser(userId))
    {
        user->updateReputation(points);
    }
}

string StackOverflow::generateUserId()
{
    return "U" + to_string(userIdCounter++);
}

string StackOverflow::generatePostId()
{
    return "P" + to_string(postIdCounter++);
}
string StackOverflow::generateCommentId()
{
    return "C" + to_string(commentIdCounter++);
}