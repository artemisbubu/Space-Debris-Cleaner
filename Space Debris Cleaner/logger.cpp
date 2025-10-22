#include "logger.hpp"
#include <iostream>

// 
void sdc::logger::log(const std::string& content, const std::string& color, const std::string& label)
{
    if (!label.empty())
        std::cout << color << "[" << label << "]\t" << COLOR::_WHITE;
    std::cout << content << std::endl;
}

void sdc::logger::error(const std::string& content, const std::string& label)
{
    log(content, COLOR::_RED, label);
}

void sdc::logger::info(const std::string& content, const std::string& label)
{
    log(content, COLOR::_WHITE, label);
}

void sdc::logger::warn(const std::string& content, const std::string& label)
{
    log(content, COLOR::_YELLOW, label);
}

void sdc::logger::vital(const std::string& content, const std::string& label)
{
    log(content, COLOR::_BLUE, label);
}

void sdc::logger::success(const std::string& content, const std::string& label)
{
    log(content, COLOR::_GREEN, label);
}