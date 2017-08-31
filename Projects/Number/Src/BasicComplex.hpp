
#pragma once

#include "Number.hpp"

namespace Lpp{

struct RealNumber;

class BasicComplex final : public Number{
public:
	BasicComplex(
		Shared<const RealNumber> _realPart,
		Shared<const RealNumber> _imaginaryPart);

	NumberExchangeFormat numberValue() const final override;

private:
	const Shared<const RealNumber> m_realPart;
	const Shared<const RealNumber> m_imaginaryPart;
};

}
