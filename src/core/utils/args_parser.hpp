#ifndef ARGS_PARSER_HPP_
#define ARGS_PARSER_HPP_

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <optional>

namespace socketlib
{
    /*!
        \brief Class for parse arguments from argc argv, and vector<string>.
    */

    class ArgsParser
    {
        using token = std::vector<std::string>;
    public:
        ArgsParser(int _argc, char** _argv)
        {
            std::copy(_argv + 1, _argv + _argc, std::back_inserter(arg));
        }

        ArgsParser(token _args)
        {
            std::copy(_args.begin(), _args.end(), std::back_inserter(arg));
        }

        ~ArgsParser() = default;
    public:
        const token& GetTokens() const
        {
            return arg;
        }

        const std::optional<std::string> GetOption(const std::string _option) const
        {
            auto it = std::find(arg.begin(), arg.end(), _option);

            if(it != arg.end()){
                if(it - arg.begin() <= arg.size()){
                    auto opt = (++it)->c_str() == nullptr ? "" : *it;
                    if(opt != "" && opt[0] != '-'){
                        return opt;
                    }
                }
            }
            return std::nullopt;
        }

        bool IsExist(const std::string _arg) const
        {
            return std::find(arg.begin(), arg.end(), _arg) != arg.end();
        }
    private:
        token arg;
    };
}

#endif