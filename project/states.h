#pragma once
#include <string>
#include <queue>

class CommentsRemover;

class State {
protected:
    CommentsRemover *context;

public:
    State(CommentsRemover *context):context(context){}
    virtual void processNextChar(char c, std::string &res) = 0;
    virtual void processInputEnd(std::string &res) {}
};
