#include "storage/ValidatedStorage.hpp"

#include <chrono>
#include <ctime>
#include <iostream>
#include <stdexcept>

#include <boost/algorithm/string.hpp>

#include "constants/Constants.hpp"

#include "storage/JsonStorage.hpp"
#include "storage/XmlStorage.hpp"
#include "storage/YamlStorage.hpp"

namespace storage {
template <typename BaseStorage>
std::optional<types::StorageResult> ValidatedStorage<BaseStorage>::storeReport(
    const types::Report& report) const try {
    if( report.amount > 0.0
    && !report.tax.empty() ) {
        if (const auto status = BaseStorage::storeReport( report )) {
            if( status == types::StorageResult::Success ) {
                return status;
            }
        }
    }

    return types::StorageResult::Failure;
} catch (const std::exception& e) {
    std::cerr << __FILE__ << ' ' << e.what() << '\n';
    return std::nullopt;
}

template class ValidatedStorage<JsonStorage>;
template class ValidatedStorage<XmlStorage>;
template class ValidatedStorage<YamlStorage>;
} // namespace storage
