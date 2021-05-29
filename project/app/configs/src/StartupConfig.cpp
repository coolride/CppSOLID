#include "configs/StartupConfig.hpp"

#include <iostream>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

std::optional<const StartupConfig> optionsToStartupConfig(int argc, char* argv[])
{
    po::options_description desc("Allowed options");

    // clang-format off
    desc.add_options()
        ("help", "Produce help message")
        ("port", po::value<std::uint16_t>()->default_value(8080), "Set server port")
        ("format", po::value<types::ReportFormat>()->default_value( types::ReportFormat::Json, "json" ), "Set tax report format (json, xml or yaml)")
        ("storage", po::value<types::StorageFormat>()->default_value( types::StorageFormat::Json, "json" ), "Set storage format (json, xml or yaml)");
    // clang-format on

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        return std::nullopt;
    }

    return StartupConfig{
        vm["port"].as<std::uint16_t>(),
        vm["format"].as<types::ReportFormat>(),
        vm["storage"].as<types::StorageFormat>()
    };
}
