#include "types/Storage.hpp"

#include <iostream>
#include <string>

#include <boost/algorithm/string.hpp>

std::istream& operator>>(std::istream& in, types::StorageFormat &format)
{
    std::string token;
    in >> token;

    boost::algorithm::to_lower(token);

    if (token == "json")
        format = types::StorageFormat::Json;
    else if (token == "xml")
        format = types::StorageFormat::Xml;
    else if (token == "yaml")
        format = types::StorageFormat::Yaml;
    else
        in.setstate(std::ios_base::failbit);
    
    
    return in;
}

std::ostream& operator<<(std::ostream& os, types::StorageFormat format) {
    switch( format ) {
        case types::StorageFormat::Json: os << "json"; break;
        case types::StorageFormat::Xml: os << "xml"; break;
        case types::StorageFormat::Yaml: os << "yaml"; break;
    }
    
    return os;
}

