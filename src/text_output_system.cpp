#ifndef TEXT_OUTPUT_SYSTEM_CPP_INCLUDED
#define TEXT_OUTPUT_SYSTEM_CPP_INCLUDED

#include "text_output_system.h"

using namespace std;

void TextOutputSystem::writeOutput()
{
    std::string def_string = getDefstring();
    std::string res = completeString(def_string);

    //skriv ut
    /*printw(out_string.c_str());
    printw("\n>>");
    refresh();*/

    }

std::string TextOutputSystem::getDefstring() const
    {
  string res;
  auto range = defaultstrings.equal_range( m_message->getCommand() ); //range = pair<const unordered_multimap<int,string>::iterator, const unordered_multimap<int,string>::iterator>

  // kolla om det bara finns 1 standardstr�ng, ex: kommando help eller _list
  //Om kommandot har 2 standradstr�ngar, s� hittar man den r�tta med hj�lp av check
  auto temp = range.first;
  if((++temp) == range.second)
    {
      unordered_multimap<int,std::string>::value_type& x = *range.first;
      res = x.second;
    }
  //
  else{

    if(m_message->getSuccess() )
      {
	std::unordered_multimap<int,std::string>::value_type& x = *(++range.first);
	res = x.second;
      }
    else
      {
	std::unordered_multimap<int,std::string>::value_type& x = *(range.first);
	res = x.second;
      }

  }
  return res;
    }

//INTE f�rdig!!
std::string TextOutputSystem::completeString( const std::string& defstring)
    {
    std::string _complete_string = defstring;
    string temp;

    //Utmatingsstr�ng f�r kommando: list
    if(m_message->getCommand() == EngineMessage::_list)
    {
     for(auto i : m_message->getPlayer().getInventory())
       {
            temp = " " + i.getName();
            _complete_string.append(temp);
       }
    }

    else
    {
        vector<string> args = m_message->getArguments();
        for(int i = 0; i < args.size(); ++i)
        {
            temp = "<arg";
            temp += (to_string(i) + ">");

            size_t pos = _complete_string.find(temp);

            //�r vi s�kra p� att den kommer att finnas? Beh�ver vi kolla detta?
            if(pos != string::npos)
            {
                _complete_string.replace(pos,temp.length(),args.at(i));
            }

        }
    }

    return _complete_string;
}




#endif // TEXT_OUTPUT_SYSTEM_CPP_INCLUDED
