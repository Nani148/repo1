#ifndef MUFEATURE_H
#define MUFEATURE_H

#include <features/BaseFeature.h>
#include <nfiq2_fingerprintimagedata.hpp>
#include <nfiq2_interfacedefinitions.hpp>

#include <string>
#include <vector>

namespace NFIQ2 { namespace QualityFeatures {

class MuFeature : public BaseFeature {
    public:
	MuFeature(const NFIQ2::FingerprintImageData &fingerprintImage);
	virtual ~MuFeature();

	std::string getModuleName() const override;

	/** @throw NFIQ2::NFIQException
	 * Sigma has not yet been calculated.
	 */
	double getSigma() const;

	static std::vector<std::string> getQualityFeatureIDs();

    private:
	std::unordered_map<std::string, double> computeFeatureData(
	    const NFIQ2::FingerprintImageData &fingerprintImage);

	bool sigmaComputed { false };
	double sigma {};
};

}}

#endif

/******************************************************************************/
