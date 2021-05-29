#include "storage/JsonStorage.hpp"

#include "types/Report.hpp"

#include "nlohmann/json.hpp"

using json = nlohmann::json;

namespace storage {
std::optional<types::StorageResult> JsonStorage::storeReport( const types::Report& report) const {
    json jsonReport = {
        {"payer", report.payer},
        {"tax", report.tax},
        {"amount", report.amount},
        {"year", report.year},
    };
    std::string s = jsonReport.dump();

    return types::StorageResult::Success;
}

} // namespace storage
