/*
 * comments.cpp
 *
 *  Created for: GlobalLogic Bootcamp
 *       Author: vitalii.lysenko
 *
 * You have to write an implementation of remove_comments()
 * which should remove all C++ comments from the input string.
 *
 * This source will be used when Jenkins builds the unit tests.
 *
 */

#include <string>

#include "comments.h"

#include "states.h"
#include "comments_remover.h"

std::string remove_comments(const std::string& str)
{    
    CommentsRemover test(str);    
    return test.process();
}

/*
enum states {OUTSIDE, ONELINE_COMMENT, BLOCK_COMMENT, STRING_LITERAL};

std::string remove_comments(const std::string& str)
{
    states state = states::OUTSIDE;
    std::string res;

    for(unsigned int i=0; i<str.length(); i++) {
        char c = str[i];
        char cn = i < str.length()-1 ? str[i+1] : 0;
        char cp = i > 0 ? str[i-1] : 0;

        switch (state) {
            case states::OUTSIDE:
                if(c == '/') {
                    if(cn == '/') {
                        state = states::ONELINE_COMMENT;
                        i++;
                        continue;
                    }
                    else if(cn == '*') {
                        state = states::BLOCK_COMMENT;
                        i++;
                        continue;
                    }
                }
                else {
                    if(c == '"') {
                        state = states::STRING_LITERAL;
                    }
                }
                break;
            case states::STRING_LITERAL:
                if(c == '"' && cp != '\\') state = states::OUTSIDE;
                break;
            case states::ONELINE_COMMENT:
                if(c == '\n') {
                    state = states::OUTSIDE;
                }
                else {
                    continue;
                }
                break;            
            case states::BLOCK_COMMENT:
                if(c == '*' && cn == '/') {
                    state = states::OUTSIDE;
                    i++;
                }               
                continue;                
                break;
        }
        res += c;
   }

    return res;
}
*/