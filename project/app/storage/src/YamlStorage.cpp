#include "storage/YamlStorage.hpp"

#include "types/Report.hpp"

#include "yaml-cpp/yaml.h"

namespace storage {
std::optional<types::StorageResult> YamlStorage::storeReport( const types::Report& report) const {
    YAML::Emitter out;
    out << YAML::BeginMap
    << YAML::Key << "report"
    << YAML::Value
        << YAML::BeginMap
            << YAML::Key << "payer" << YAML::Value << report.payer
            << YAML::Key << "tax" << YAML::Value << report.tax
            << YAML::Key << "amount" << YAML::Value << report.amount
            << YAML::Key << "year" << YAML::Value << report.year
        << YAML::EndMap
    << YAML::EndMap;

    return out.good()? types::StorageResult::Success: types::StorageResult::Failure;
}

} // namespace storage
