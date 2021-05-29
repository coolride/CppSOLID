#include <iostream>
#include <memory>
#include <stdexcept>

#include "auth/AuthManager.hpp"
#include "configs/StartupConfig.hpp"
#include "parsers/ParsersFactory.hpp"
#include "storage/StorageFactory.hpp"
#include "servers/Server.hpp"
#include "services/TaxServiceFactory.hpp"

int main(int argc, char* argv[])
{
    try {
        if (const auto config = optionsToStartupConfig(argc, argv)) {
            std::cout
            << "Starting server on port " << config->port << '\n'
            << "Report format is set as " << config->reportFormat << '\n'
            << "Storage format is set as " << config->storageFormat << '\n'
            ;

            const auth::AuthManager authManager;
            const parsers::ParsersFactory parsersFactory(config->reportFormat);

            const auto credentialsParser = parsersFactory.createCredentialsParser();
            const auto reportParser = parsersFactory.createReportParser();

            const storage::StorageFactory storageFactory(config->storageFormat);
            const auto storage = storageFactory.createStorage();

            const services::TaxServiceFactory taxServiceFactory(authManager, *reportParser, *storage);

            servers::runServer(config->port, authManager, *credentialsParser, taxServiceFactory);
        }
    } catch (std::exception& e) {
        std::cerr << __FILE__ << ' ' << e.what() << '\n';
        return 1;
    }

    return 0;
}
