#include <iostream>
#include "Terminal.h"
#include "../../CLI/CommandsParams/Params.h"
#include "../paramsManager/ParamsManager.h"
#include "../commandsManager/CommandsManager.h"
#include "../../Exception/MyException.h"
#include "../../CLI/Commands/controlCommand/quit/QuitCommand.h"

static std::vector<std::string> parsingCommand(const std::string& input);
//static void checkValidCommandStart(const std::vector<std::string> &params);/*> cmd >>>*/

void Terminal::run(const IReader *readFrom, const IWriter *writeTo, bool writeInput)
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
            if(writeInput)
            {
                writeTo->write((input+"\n").c_str());
            }
            std::vector<std::string> params = parsingCommand(input);
            //checkValidCommandStart(params);
            output = commandsManager.getCommand(params[0], readFrom, writeTo)->run(commandParsingManager.getParams(params[0],params));
            writeTo->write(output.c_str());
            input.clear();
        }
        catch (const std::exception& e)
        {
            std::string s = e.what();
            s+= "\n";
            writeTo->write(s.c_str());
        }
        catch (const CLI::QuitException& e)
        {
            return;
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
    for (wordBegin = 0; wordBegin < input.size() && input[wordBegin] == ' '; ++wordBegin);
    if(wordBegin == input.size())
    {
        parsedVector.push_back("\n");
        return parsedVector;
    }
    for (size_t wordEnd = wordBegin; wordEnd < input.size(); ++wordEnd)
    {
        for (wordEnd = wordBegin; wordEnd < input.size() && input[wordEnd] != ' '; ++wordEnd);
        parsedVector.push_back(std::string(input.begin()+wordBegin,input.begin() + wordEnd));
        for (wordBegin = wordEnd; wordBegin < input.size() && input[wordBegin] == ' '; ++wordBegin);

    }
    return parsedVector;
}
