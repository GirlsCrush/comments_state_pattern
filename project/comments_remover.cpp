#include "comments_remover.h"

// CommentsRemover::CommentsRemover()
//     :outsideState(this), 
//     oneLineCommentState(this), 
//     stringLiteralState(this),
//     currentState(&outsideState)
// {

// }

void CommentsRemover::setState(State* newState)
{
    currentState = newState;
}

std::string CommentsRemover::process() {
    unsigned pos = 0;
    while(pos < source.length()) {
        currentState->processNextChar(source[pos], result);
        pos++;
    }
    currentState->processInputEnd(result);
    return result;
}