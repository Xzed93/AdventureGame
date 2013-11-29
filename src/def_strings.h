#ifndef DEF_STRINGS_H
#define DEF_STRINGS_H

#include <string>
#include <unordered_map>
#include "message.h"

/**
unordered_multimap f�r att lagra standardstr�ngarna f�r varje kommandon.
Vissa kommandon kommer att ha 2 olika standardstr�ngarna(om kommandot
lyckades eller inte).

�nnu inte f�rdig
**/
 static std::unordered_multimap<int,std::string> defaultstrings{
{EngineMessage::chelp,"Player Commands: clist, cgo, ceat, cthrow, ctake, csave Create World: cmakeroom, cmake, cdelete, cdestroy, cjump, crooms"},
{EngineMessage::clist,"Your inventory: "}, //specialfall
{EngineMessage::cgo,"You go <arg0>"}, // <arg0> �r argumentet som ska kompletteras, ex: You go west
{EngineMessage::cgo,"You can�t go that direction!"},
{EngineMessage::ceat,"You�re eating <arg0>"},
{EngineMessage::ceat,"You can�t eat That! You crazy?"},
{EngineMessage::cjump,"You jumped to (<arg0>,arg<1>)"},
{EngineMessage::cthrow,"You threw <arg0>"},
{EngineMessage::cthrow,"You can�t throw that item!"},
{EngineMessage::ctake,"You got this item: <arg0>"},
{EngineMessage::ctake,"You can�t take this item!"},
{EngineMessage::cunknown,"Invalid command"}// Default Message string
//{EngineMessage::none,"testing2"}
};

#endif
