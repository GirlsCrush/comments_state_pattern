#pragma once
#include <string>
#include <queue>

//Here you can see usage of Singelton pattern. It doesnt feet tests though :-)

class CommentsRemover;

class State {
public:
    virtual State* processNextChar(char c, std::string &res) = 0;
    virtual void processInputEnd(std::string &res) {}
};

class OutsideState : public State {
private:
    OutsideState(){};
    static OutsideState * uniqueStateP ;
public:
    static OutsideState* getInstance();
    State* processNextChar(char c, std::string &res) override;
    void processInputEnd(std::string &res) override{};
    ~OutsideState();
};

class StringLiteralState : public State {
private:
    StringLiteralState(){}
    static StringLiteralState * uniqueStateP;
public:
    static StringLiteralState* getInstance();
    State* processNextChar(char c, std::string &res) override;
    void processInputEnd(std::string &res) override{};
    ~StringLiteralState();
};

class BlockCommentState : public State {
private:
    BlockCommentState(){}
    static BlockCommentState * uniqueStateP;
public:
    static BlockCommentState* getInstance();
    State* processNextChar(char c, std::string &res) override;
    void processInputEnd(std::string &res) override{};
    ~BlockCommentState();
};

class OneLineCommentState : public State {
private:
    OneLineCommentState(){}
    static OneLineCommentState * uniqueStateP;
public:
    static OneLineCommentState* getInstance();
    State* processNextChar(char c, std::string &res) override;
    void processInputEnd(std::string &res) override{};
    ~OneLineCommentState();
};

class PotentialCommentState : public State {
private:
    PotentialCommentState(){}
    static PotentialCommentState * uniqueStateP;
public:
    static PotentialCommentState* getInstance();
    State* processNextChar(char c, std::string &res) override;
    void processInputEnd(std::string &res) override{};
    ~PotentialCommentState();
};

class PotentialCommentEndState : public State {
private:
    PotentialCommentEndState(){}
    static PotentialCommentEndState * uniqueStateP;
public:
    static PotentialCommentEndState* getInstance();
    State* processNextChar(char c, std::string &res) override;
    void processInputEnd(std::string &res) override{};
    ~PotentialCommentEndState();
};


// class PotentialRawCommentFirstState : public State {
// private:
//     PotentialRawCommentFirstState(){}
//     static PotentialRawCommentFirstState * uniqueStateP;
// public:
//     static PotentialRawCommentFirstState* getInstance();
//     State* processNextChar(char c, std::string &res) override;
//     void processInputEnd(std::string &res) override;
//     ~PotentialRawCommentFirstState();
// };

// class PotentialRawCommentSecondState : public State {
// private:
//     PotentialRawCommentSecondState(){}
//     static PotentialRawCommentSecondState * uniqueStateP;
// public:
//     static PotentialRawCommentSecondState* getInstance();
//     State* processNextChar(char c, std::string &res) override;
//     void processInputEnd(std::string &res) override;
//     ~PotentialRawCommentSecondState();
// };

// class PotentialRawCommentEndState : public State {
// private:
//     PotentialRawCommentEndState(){}
//     static PotentialRawCommentEndState * uniqueStateP;
// public:
//     static PotentialRawCommentEndState* getInstance();
//     State* processNextChar(char c, std::string &res) override;
//     void processInputEnd(std::string &res) override;
//     ~PotentialRawCommentEndState();
// };
