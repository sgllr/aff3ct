#ifndef LAUNCHER_BFERI_RSC_HPP_
#define LAUNCHER_BFERI_RSC_HPP_

#include "../Launcher_BFERI.hpp"

namespace aff3ct
{
namespace launcher
{
template <typename B, typename R, typename Q, typename QD>
class Launcher_BFERI_RSC : public Launcher_BFERI<B,R,Q>
{
public:
	Launcher_BFERI_RSC(const int argc, const char **argv, std::ostream &stream = std::cout);
	virtual ~Launcher_BFERI_RSC() {};

protected:
	virtual void build_args();
	virtual void store_args();
	virtual simulation::Simulation* build_simu();

	virtual std::vector<std::pair<std::string,std::string>> header_encoder();
	virtual std::vector<std::pair<std::string,std::string>> header_decoder();
};
}
}

#endif /* LAUNCHER_BFERI_RSC_HPP_ */
