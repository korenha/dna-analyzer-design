#include "Manager.h"

#include <iostream>
#include "../Exception/MyException.h"
#include "CommandsManager.h"
#include "CommandParsingManager.h"
#include "../CLI/IParams.h"
#include <sstream>
#include <vector>

static std::vector<std::string> parsingCommand(const std::string& input);
static void checkValidCommandStart(const std::vector<std::string> &params);/*> cmd >>>*/

void Manager::doAction()
{
    std::cout<<"|--------Start Run-------------|"<<std::endl;
    std::string input,output;
    input = m_reader->read();
    CommandsManager commandsManager;
    CommandParsingManager commandParsingManager;
    try
    {
        std::vector<std::string> params = parsingCommand(input);
        checkValidCommandStart(params);
        output = commandsManager.getCommand(params[3])->run((CLI::IParams*)commandParsingManager.getParams(params[3], std::vector<std::string>(params.begin() + 4, params.end())));
        m_writer->write(output.c_str());
        input.clear();
    }
    catch (const MyException& e)
    {
        m_writer->write(e.what());
    }

}

static void checkValidCommandStart(const std::vector<std::string> &params)
{

    if(params[0] != ">")
    {
        throw MyException("SyntaxError:  Expected get '>' ");
    }
    if(params[1] != "cmd")
    {
        throw MyException("SyntaxError: Expected get 'cmd' ");
    }
    if(params[2] != ">>>")
    {
        throw MyException("SyntaxError: Expected get '>>>' ");
    }
}

static std::vector<std::string> parsingCommand(const std::string& input)
{
    std::vector<std::string> parsedVector;
    size_t wordBegin = 0;
    for (size_t wordEnd = 0; wordEnd < input.size(); ++wordEnd)
    {
        for (wordBegin = wordEnd; wordBegin < input.size() && input[wordBegin] == ' '; ++wordBegin);
        for (wordEnd = wordBegin; wordEnd < input.size() && input[wordEnd] != ' '; ++wordEnd);
        parsedVector.push_back(std::string(input.begin()+wordBegin,input.begin() + wordEnd));
    }
    return parsedVector;
}
