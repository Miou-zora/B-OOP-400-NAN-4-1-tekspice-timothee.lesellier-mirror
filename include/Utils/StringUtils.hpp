/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** StringUtils
*/

#pragma once

#include <string>
#include <memory>
#include <vector>
#include <sstream>

class StringUtils {
    public:
        static std::string clearAfter(std::string line, char commentChar)
        {
            std::string lineWithOutComment = line.substr(0, line.find(commentChar));
            return (lineWithOutComment);
        }


        static std::unique_ptr<std::vector<std::string>> splitString(std::string line)
        {
            std::vector<std::string> list;
            std::string buffer;
            std::stringstream ss(line);

            while (ss >> buffer)
                list.push_back(buffer);
            return (std::make_unique<std::vector<std::string>>(list));
        }

        static std::string getString(std::string line, size_t pos)
        {
            std::unique_ptr<std::vector<std::string>> list = StringUtils::splitString(line);

            return (list->at(pos));
        }
};
