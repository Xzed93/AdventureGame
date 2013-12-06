#include "text_input_system.h"
#include <cctype>

InputMessage* TextInputSystem::getData()
{

  m_command.clear();
  m_arguments.clear();// tömmer för att det alltid ska finnas senaste inmatningen
  char ncurses_input[254]; // för att getstr() vill har char[] och inte tar string
  getnstr( ncurses_input,254 );
  std::string temp, input = ncurses_input; 
  unsigned int start_of_word = 0;

  for( int y = 1; y < input.size(); ++y )
    {
      if( isblank( input.at(y) ) )
	{
	  if( !isblank( input.at(y-1) ) )
	    {
	      temp.assign( input, start_of_word, y - start_of_word);
	      if( start_of_word == 0 )
		m_command = temp;
	      else
		m_arguments.push_back( temp );
	    }
	  start_of_word = y + 1;
	}
      else if( y == input.size() - 1 && !isblank( input.at(y) ) )
	{
	  temp.assign( input, start_of_word, y - start_of_word + 1);
	  if( start_of_word == 0 )
	    m_command = temp;
	  else	 
	    m_arguments.push_back( temp );
	}
    }
  return m_parser.getData(m_command,m_arguments);
}
