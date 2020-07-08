#include <string>
#include "QuitCommand.h"
#include "../../Params.h"
namespace CLI
{


    std::string QuitCommand::run(Params *params)
    {//check modified and new
        m_writer->write("... Are you sure you want to quit?\n"
                        "Please confirm by 'y' or 'Y', or cancel by 'n' or 'N'.");
        std::string input;
        while(input != "Y" && input != "y" && input != "N" && input != "n" )
        {
            if(!input.empty())
            {
                m_writer->write("\nYou have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'.");
            }
            m_writer->write("\n> confirm >>> ");
            input = m_reader->read();
        }
        if(input == "Y" || input == "y")
        {
            m_writer->write("Thank you for using Dnalanyzer. \n"
                            "Goodbye!");
            throw QuitException();
        }
        return "";
    }

}