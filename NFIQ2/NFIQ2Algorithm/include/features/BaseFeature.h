#ifndef BASEFEATURE_H
#define BASEFEATURE_H

#include <nfiq2_fingerprintimagedata.hpp>
#include <nfiq2_interfacedefinitions.hpp>

#include <string>
#include <unordered_map>
#include <vector>

namespace NFIQ2 { namespace QualityFeatures {

class BaseFeature {
    public:
	BaseFeature();

	virtual ~BaseFeature();

	/** @return Identifier for this particular feature */
	virtual std::string getModuleName() const = 0;

	/** @return computed quality feature speed */
	virtual NFIQ2::QualityFeatureSpeed getSpeed() const;

	/** @return computed quality features */
	virtual std::unordered_map<std::string, double> getFeatures() const;

	static const std::string HistogramBin0Suffix;
	static const std::string HistogramBin1Suffix;
	static const std::string HistogramBin2Suffix;
	static const std::string HistogramBin3Suffix;
	static const std::string HistogramBin4Suffix;
	static const std::string HistogramBin5Suffix;
	static const std::string HistogramBin6Suffix;
	static const std::string HistogramBin7Suffix;
	static const std::string HistogramBin8Suffix;
	static const std::string HistogramBin9Suffix;
	static const std::string StdDevSuffix;
	static const std::string MeanSuffix;

    protected:
	void setSpeed(const NFIQ2::QualityFeatureSpeed &featureSpeed);

	void setFeatures(
	    const std::unordered_map<std::string, double> &featureResult);

    private:
	NFIQ2::QualityFeatureSpeed speed {};

	std::unordered_map<std::string, double> features {};
};

}}

#endif

/******************************************************************************/
