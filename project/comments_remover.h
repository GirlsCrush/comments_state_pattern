#pragma once

#include "states.h"

class CommentsRemover {
protected:
    State *currentState;
    
    // OutsideState outsideState;
    // OneLineCommentState oneLineCommentState;
    // StringLiteralState stringLiteralState;

    std::string source;
    std::string result;

public:
    CommentsRemover(std::string source):source(source),currentState(OutsideState::getInstance()) {}
    std::string process();

    // void setCommentStartState();
    // void setOneLineCommentStartState();
    // void setOutsideState();
    
    void setState(State* newState);
};