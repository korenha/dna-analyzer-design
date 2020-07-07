#include "Manager.h"
#include "../Reader/ConsulReader.h"
#include "../Writer/ConsulWriter.h"
#include <iostream>
#include "../Exception/MyException.h"
#include "CommandsManager.h"
#include "CommandParsingManager.h"
#include "../CML/IParams.h"
#include <sstream>
static void removeTheInputBeginningAndCheckItsSyntax(std::string& input);/*> cmd >>>*/
static std::string getNameCommandAndRemoveFromTheInput(std::string& input);

void Manager::doAction()
{
    std::cout<<"|--------Start Run-------------|"<<std::endl;
    ConsulReader  reader;
    ConsulWriter writer;
    std::string input;
    input = reader.read();
    CommandsManager commandsManager;
    CommandParsingManager commandParsingManager;
    try
    {
        removeTheInputBeginningAndCheckItsSyntax(input);
        std::string commandName = getNameCommandAndRemoveFromTheInput(input);
        commandsManager.getCommand(commandName)->run((CML::IParams*)commandParsingManager.getParams(commandName,input));
        input.clear();
    }
    catch (const MyException& e)
    {
        writer.write(e.what());
    }

}

static void removeTheInputBeginningAndCheckItsSyntax(std::string& input)
{
    size_t i;
    for (i = 0; i < input.size() && input[i] == ' '; ++i);
    if(input[i] != '>')
    {
        throw MyException("SyntaxError:  Expected get '>' ");
    }
    ++i;
    for (; i < input.size() && input[i] == ' '; ++i);
    if(input.find("cmd") != i)
    {
        throw MyException("SyntaxError: Expected get 'cmd' ");
    }
    i += 3;
    for (; i < input.size() && input[i] == ' '; ++i);
    if(input.find(">>>") != i)
    {
        throw MyException("SyntaxError: Expected get '>>>' ");
    }
    i += 3;
    for (; i < input.size() && input[i] == ' '; ++i);
    input = std::string(input.begin() + i,input.end());

}

static std::string getNameCommandAndRemoveFromTheInput(std::string& input)
{
    size_t index=input.find(' ');
    std::string commandName = std::string(input.begin(),input.begin() + index);
    for (; index < input.size() && input[index] == ' '; ++index);
    input = std::string(input.begin()+index,input.end());
    return commandName;
}
