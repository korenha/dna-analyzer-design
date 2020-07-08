#include <iostream>
#include "Terminal.h"
#include "../CLI/Params.h"
#include "ParamsManager.h"
#include "CommandsManager.h"
#include "../Exception/MyException.h"
static std::vector<std::string> parsingCommand(const std::string& input);
//static void checkValidCommandStart(const std::vector<std::string> &params);/*> cmd >>>*/

void Terminal::run(IReader *readFrom, IWriter *writeTo)
{
    std::string input,output;
    CommandsManager commandsManager;
    ParamsManager commandParsingManager;
    while (true)
    {
        try
        {
            writeTo->write("> cmd >>> ");
            input = readFrom->read();
            std::vector<std::string> params = parsingCommand(input);
            //checkValidCommandStart(params);
            output = commandsManager.getCommand(params[0])->run(commandParsingManager.getParams(params[0], std::vector<std::string>(params.begin() + 1, params.end())));
            writeTo->write(output.c_str());
            input.clear();
        }
        catch (const std::exception& e)
        {
            writeTo->write(e.what());
        }
    }
}

/*static void checkValidCommandStart(const std::vector<std::string> &params)
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
*/
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
