#include "types/ReportFormat.hpp"

#include <iostream>
#include <string>

#include <boost/algorithm/string.hpp>

std::istream& operator>>(std::istream& in, types::ReportFormat &format)
{
    std::string token;
    in >> token;

    boost::algorithm::to_lower(token);

    if (token == "json")
        format = types::ReportFormat::Json;
    else if (token == "xml")
        format = types::ReportFormat::Xml;
    else if (token == "yaml")
        format = types::ReportFormat::Yaml;
    else
        in.setstate(std::ios_base::failbit);
    
    return in;
}

std::ostream& operator<<(std::ostream& os, types::ReportFormat format) {
    switch( format ) {
        case types::ReportFormat::Json: os << "json"; break;
        case types::ReportFormat::Xml: os << "xml"; break;
        case types::ReportFormat::Yaml: os << "yaml"; break;
    }

    return os;
}
