#include "parsers/YamlParser.hpp"

#include <iostream>
#include <stdexcept>

#include <boost/lexical_cast.hpp>

#include "yaml-cpp/yaml.h"

namespace {
template <typename T> auto getFromYaml(const YAML::Node &node, const char *field) {
    for(YAML::const_iterator it=node.begin();it!=node.end();++it) {
        if( it->first.as<std::string>().compare( field ) == 0 ) {
            return it->second.as<T>();
        }
    }

    throw std::runtime_error{ "Invalid yaml" };
}
} // namespace

namespace parsers {
std::optional<types::Report> YamlParser::parseReport(const std::string& rawReport) const try {
    YAML::Node map = YAML::Load( rawReport );

    if( not map.IsNull()
    && map.IsMap() ) {
        YAML::Node attributes = map.begin()->second;
        return types::Report{
            getFromYaml<std::uint32_t>(attributes, "payer"),
            getFromYaml<std::string>(attributes, "tax"),
            getFromYaml<double>(attributes, "amount"),
            getFromYaml<std::uint16_t>(attributes, "year"),
        };
    }

    return std::nullopt;
} catch (const std::exception& e) {
    std::cerr << __FILE__ << ' ' << e.what() << '\n';
    return std::nullopt;
}

std::optional<types::User> YamlParser::parseCredentials(const std::string& rawCredentials) const try {
    YAML::Node map = YAML::Load( rawCredentials );

    if( not map.IsNull()
    && map.IsMap() ) {
        YAML::Node attributes = map.begin()->second;
        return types::User{
            getFromYaml<std::string>(attributes, "login"),
            getFromYaml<std::string>(attributes, "password"),
        };
    }

    return std::nullopt;
} catch (const std::exception& e) {
    std::cerr << __FILE__ << ' ' << e.what() << '\n';
    return std::nullopt;
}
} // namespace parsers
