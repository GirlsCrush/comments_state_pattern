#include <string>
#include "states.h"
#include "comments_remover.h"

OutsideState * OutsideState::uniqueStateP = nullptr;

StringLiteralState * StringLiteralState::uniqueStateP = nullptr;

BlockCommentState * BlockCommentState::uniqueStateP = nullptr;

OneLineCommentState * OneLineCommentState::uniqueStateP = nullptr;

PotentialCommentState * PotentialCommentState::uniqueStateP = nullptr;

PotentialCommentEndState * PotentialCommentEndState::uniqueStateP = nullptr;

// PotentialRawCommentFirstState * PotentialRawCommentFirstState::uniqueStateP = nullptr;

// PotentialRawCommentSecondState * PotentialRawCommentSecondState::uniqueStateP = nullptr;

// PotentialRawCommentEndState * PotentialRawCommentEndState::uniqueStateP = nullptr;

OutsideState::~OutsideState(){
    delete uniqueStateP;
}

StringLiteralState::~StringLiteralState(){
    delete uniqueStateP;
}

BlockCommentState::~BlockCommentState(){
    delete uniqueStateP;
}

OneLineCommentState::~OneLineCommentState(){
    delete uniqueStateP;
}

PotentialCommentState::~PotentialCommentState(){
    delete uniqueStateP;
}

PotentialCommentEndState::~PotentialCommentEndState(){
    delete uniqueStateP;
}

// PotentialRawCommentFirstState::~PotentialRawCommentFirstState(){
//     delete uniqueStateP;
// }


// PotentialRawCommentSecondState::~PotentialRawCommentSecondState(){
//     delete uniqueStateP;
// }

// PotentialRawCommentEndState::~PotentialRawCommentEndState(){
//     delete uniqueStateP;
// }

OutsideState* OutsideState::getInstance(){
    if (uniqueStateP == nullptr)
        uniqueStateP = new OutsideState();
    return uniqueStateP;
}

StringLiteralState* StringLiteralState::getInstance(){
    if (uniqueStateP == nullptr)
        uniqueStateP = new StringLiteralState();
    return uniqueStateP;
}

BlockCommentState* BlockCommentState::getInstance(){
    if (uniqueStateP == nullptr)
        uniqueStateP = new BlockCommentState();
    return uniqueStateP;
}

OneLineCommentState* OneLineCommentState::getInstance(){
    if (uniqueStateP == nullptr)
        uniqueStateP = new OneLineCommentState();
    return uniqueStateP;
}

PotentialCommentState* PotentialCommentState::getInstance(){
    if (uniqueStateP == nullptr)
        uniqueStateP = new PotentialCommentState();
    return uniqueStateP;
}

PotentialCommentEndState* PotentialCommentEndState::getInstance(){
    if (uniqueStateP == nullptr)
        uniqueStateP = new PotentialCommentEndState();
    return uniqueStateP;
}

// PotentialRawCommentFirstState* PotentialRawCommentFirstState::getInstance(){
//     if (uniqueStateP == nullptr)
//         uniqueStateP = new PotentialRawCommentFirstState();
//     return uniqueStateP;
// }

// PotentialRawCommentSecondState* PotentialRawCommentSecondState::getInstance(){
//     if (uniqueStateP == nullptr)
//         uniqueStateP = new PotentialRawCommentSecondState();
//     return uniqueStateP;
// }

// PotentialRawCommentEndState* PotentialRawCommentEndState::getInstance(){
//     if (uniqueStateP == nullptr)
//         uniqueStateP = new PotentialRawCommentEndState();
//     return uniqueStateP;
// }

State* OutsideState::processNextChar(char c, std::string &res){
    res.push_back(c);
    if (c == '/')
        return PotentialCommentState::getInstance();
    if (c == '\"')
        return StringLiteralState::getInstance();
    return getInstance();
}

State* StringLiteralState::processNextChar(char c, std::string &res){
    res.push_back(c);
    if (c == '\"' && !(res.size() >= 2 && res[res.size() - 2] == '\\'))
        return OutsideState::getInstance();
    return getInstance();
}

State* PotentialCommentState::processNextChar(char c, std::string &res){
    res.push_back(c);
    if (c == '*'){
        res.pop_back();
        res.pop_back();
        return BlockCommentState::getInstance();
    }
    if (c == '/'){
        res.pop_back();
        res.pop_back();
        return OneLineCommentState::getInstance();
    }
    return OutsideState::getInstance();
}

State* BlockCommentState::processNextChar(char c, std::string &res){
    if (c == '*')
        return PotentialCommentEndState::getInstance();
    return getInstance();
}

State* OneLineCommentState::processNextChar(char c, std::string &res){
    if (c == '\n'){
        res.push_back(c);
        return OutsideState::getInstance();
    }
    return getInstance();
}

State* PotentialCommentEndState::processNextChar(char c, std::string &res){
    if (c == '/'){
        return OutsideState::getInstance();
    }
    if (c == '*'){
        return getInstance();
    }
    return BlockCommentState::getInstance();
}
