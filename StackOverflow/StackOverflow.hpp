#ifndef STACK_OVERFLOW_HPP
#define STACK_OVERFLOW_HPP

#include <vector>
#include <string>
#include <ctime>
#include "User.hpp"
#include "Post.hpp"
#include "Comment.hpp"
using namespace std;

class StackOverflow
{

private:
    vector<User *> users;
    vector<Post *> posts;
    int userIdCounter;
    int postIdCounter;
    int commentIdCounter;

public:
    StackOverflow();
    ~StackOverflow();

    // User Managament
    User *registerUser(const string &userName, const string &email);
    void removeUser(const string &userId);

    // Post Management
    Post *createQuestion(const string &userId, const string &content, vector<string> &tags);
    Post *createAnswer(const string &userId, const string &questionId, const string &content);
    Comment *createComment(const string &userId, const string &postId, const string &content);

    // Voting Management
    bool votePost(const string &userId, const string &postId);
    bool unvotePost(const string &userId, const string &postId);
    bool acceptAnswer(const string &useId, const string &answerId);

    // Search and Display
    vector<Post *> searchQuestion(const string &tag) const;
    void displayUserProfile(const string &userId) const;
    void displayQuestion(const string &questionId) const;
    void displayAllQuestion() const;

private:
    User *findUser(string &userId) const;
    Post *findPost(string &postId) const;
    void updateUserReputation(const string &userId, int points);
    string generateUserId();
    string generatePostId();
    string generateCommentId();
};

#endif