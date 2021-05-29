#include "storage/XmlStorage.hpp"
#include <iostream>

#include "types/Report.hpp"

#include "tinyxml2/tinyxml2.h"

namespace storage {
std::optional<types::StorageResult> XmlStorage::storeReport( const types::Report& report) const {
    using namespace tinyxml2;

    XMLDocument doc;
	auto r = doc.NewElement( "report" )->ToElement();
    r->SetAttribute( "payer", report.payer );
	r->SetAttribute( "tax", report.tax.c_str() );
	r->SetAttribute( "amount", report.amount );
    r->SetAttribute( "year", report.year );

    return doc.Error()? types::StorageResult::Failure: types::StorageResult::Success;
}

} // namespace storage
