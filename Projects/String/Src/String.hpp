
#include "StringExchangeFormat.hpp"

#include "Generic/Src/Ordinal.hpp"

namespace Lpp{

struct String : public Ordinal<String>{

	ResultOfComparison compare(
		const Shared<const String> &_valueObject
	) const final override;

	virtual StringExchangeFormat value() const = 0;

};

}
