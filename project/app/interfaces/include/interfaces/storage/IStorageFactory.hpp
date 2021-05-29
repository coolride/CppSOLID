#pragma once

#include <memory>

#include "storage/IStorage.hpp"

namespace storage {
class IStorageFactory {
public:
    virtual ~IStorageFactory() = default;
    virtual std::unique_ptr<IStorage> createStorage() const = 0;
};
} // namespace storage
