#pragma once 

#include "storage/IStorageFactory.hpp"

#include <memory>

#include "types/Storage.hpp"

namespace storage {
class StorageFactory : public IStorageFactory {
public:
    StorageFactory(const types::StorageFormat);
    std::unique_ptr<storage::IStorage> createStorage() const override;

private:
    const types::StorageFormat storageFormat;
};
} // namespace storage
