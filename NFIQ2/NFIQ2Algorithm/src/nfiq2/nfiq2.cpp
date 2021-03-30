#include <nfiq2/modelinfo.hpp>
#include <nfiq2/nfiq2.hpp>

#include "nfiq2impl.h"

#ifdef EMBED_RANDOMFOREST_PARAMETERS
NFIQ::NFIQ2Algorithm::NFIQ2Algorithm()
    : pimpl { new NFIQ::NFIQ2Algorithm::Impl() }
{
}
#endif

NFIQ::NFIQ2Algorithm::NFIQ2Algorithm(
    const std::string &fileName, const std::string &fileHash)
    : pimpl { new NFIQ::NFIQ2Algorithm::Impl(fileName, fileHash) }
{
}

NFIQ::NFIQ2Algorithm::NFIQ2Algorithm(const NFIQ::ModelInfo &modelInfoObj)
    : NFIQ::NFIQ2Algorithm { modelInfoObj.getModelPath(),
	    modelInfoObj.getModelHash() }
{
}

unsigned int
NFIQ::NFIQ2Algorithm::computeQualityScore(
    const NFIQ::FingerprintImageData &rawImage) const
{
	return (this->pimpl->computeQualityScore(rawImage));
}

unsigned int
NFIQ::NFIQ2Algorithm::computeQualityScore(
    const std::vector<NFIQ::QualityFeatureData> &qualityFeatureData) const
{
	return (this->pimpl->computeQualityScore(qualityFeatureData));
}

NFIQ::NFIQ2Results
NFIQ::NFIQ2Algorithm::computeQualityFeaturesAndScore(
    const NFIQ::FingerprintImageData &rawImage) const
{
	return (this->pimpl->computeQualityFeaturesAndScore(rawImage));
}

std::string
NFIQ::NFIQ2Algorithm::getParameterHash() const
{
	return (this->pimpl->getParameterHash());
}

NFIQ::NFIQ2Algorithm::~NFIQ2Algorithm() = default;
