#pragma once

#include <cstdint>
#include <optional>

#include "types/ReportFormat.hpp"
#include "types/Storage.hpp"

struct StartupConfig {
    const std::uint16_t port;
    const types::ReportFormat reportFormat;
    const types::StorageFormat storageFormat;
};

std::optional<const StartupConfig> optionsToStartupConfig(int argc, char* argv[]);
