#include <string>

#include "Tools/Perf/MIPP/mipp.h"

#include "Module/CRC/NO/CRC_NO.hpp"
#include "Module/CRC/Polynomial/CRC_polynomial.hpp"
#include "Module/CRC/Polynomial/CRC_polynomial_fast.hpp"
#include "Module/CRC/Polynomial/CRC_polynomial_inter.hpp"

#include "Factory_CRC.hpp"

using namespace aff3ct::module;
using namespace aff3ct::tools;

template <typename B>
CRC<B>* Factory_CRC<B>
::build(const parameters &params)
{
	CRC<B> *crc = nullptr;

	// build the crc
	if (!params.crc.poly.empty() && params.decoder.simd_strategy == "INTER")
		crc = new CRC_polynomial_inter<B>(params.code.K - params.crc.size, params.crc.poly, params.crc.size, params.simulation.inter_frame_level);
	else if (!params.crc.poly.empty())
	{
		if (params.crc.type == "FAST")
			crc = new CRC_polynomial_fast<B>(params.code.K - params.crc.size, params.crc.poly, params.crc.size, params.simulation.inter_frame_level);
		else
			crc = new CRC_polynomial<B>(params.code.K - params.crc.size, params.crc.poly, params.crc.size, params.simulation.inter_frame_level);
	}
	else
		crc = new CRC_NO<B>(params.code.K - params.crc.size, params.simulation.inter_frame_level);

	return crc;
}

// ==================================================================================== explicit template instantiation 
#include "Tools/types.h"
#ifdef MULTI_PREC
template struct aff3ct::tools::Factory_CRC<B_8>;
template struct aff3ct::tools::Factory_CRC<B_16>;
template struct aff3ct::tools::Factory_CRC<B_32>;
template struct aff3ct::tools::Factory_CRC<B_64>;
#else
template struct aff3ct::tools::Factory_CRC<B>;
#endif
// ==================================================================================== explicit template instantiation
