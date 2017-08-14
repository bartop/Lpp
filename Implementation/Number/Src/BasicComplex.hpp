
#pragma once

#include "Number.hpp"

namespace Lpp{

struct RealNumber;

class BasicComplex final : public Number{
public:
	BasicComplex(
		std::shared_ptr<const RealNumber> _realPart,
		std::shared_ptr<const RealNumber> _imaginaryPart);

	NumberExchangeFormat numberValue() const final override;

private:
	const std::shared_ptr<const RealNumber> m_realPart;
	const std::shared_ptr<const RealNumber> m_imaginaryPart;
};

}
