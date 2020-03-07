/* file: gaussian_naive_bayes_model.h */
/*******************************************************************************
* Copyright 2014-2020 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*
//++
//  Implementation of class defining Naive Bayes model.
//--
*/

#ifndef __G_NAIVE_BAYES_MODEL_H__
#define __G_NAIVE_BAYES_MODEL_H__

#include "algorithms/algorithm.h"
#include "data_management/data/numeric_table.h"
#include "data_management/data/homogen_numeric_table.h"
#include "algorithms/classifier/classifier_model.h"

namespace daal
{
namespace algorithms
{
/**
 * @defgroup gaussian_naive_bayes Naive Bayes Classifier
 * \copydoc daal::algorithms::gaussian_naive_bayes
 * @ingroup classification
 * @{
 */
/**
 * \brief Contains classes for gaussian Naive Bayes algorithm
 */
namespace gaussian_naive_bayes
{

/**
 * \brief Contains version 2.0 of Intel(R) Data Analytics Acceleration Library (Intel(R) DAAL) interface.
 */
namespace interface2
{
/**
 * <a name="DAAL-STRUCT-ALGORITHMS__GAUSSIAN_NAIVE_BAYES__PARAMETER"></a>
 * \brief Naive Bayes algorithm parameters
 *
 * \snippet naive_bayes/gaussian_naive_bayes_model.h Parameter source code
 */
/* [Parameter source code] */
struct DAAL_EXPORT Parameter : public classifier::Parameter
{
    /**
     *  Main constructor
     *  \param[in] nClasses             Number of classes
     *  \param[in] priorClassEstimates_ Prior class estimates, numeric table of size [nClasses x 1]
     *  \param[in] alpha_               Imagined occurrences of the each feature, numeric table of size [1 x nFeatures]
     */
    Parameter(size_t nClasses, const data_management::NumericTablePtr & priorClassEstimates_ = data_management::NumericTablePtr())
        : classifier::Parameter(nClasses), priorClassEstimates(priorClassEstimates_)
    {}

    data_management::NumericTablePtr priorClassEstimates; /*!< Prior class estimates */

    services::Status check() const DAAL_C11_OVERRIDE;
};
/* [Parameter source code] */
} // namespace interface2

namespace interface1
{
/**
 * <a name="DAAL-CLASS-ALGORITHMS__GAUSSIAN_NAIVE_BAYES__MODEL"></a>
 * \brief Gaussian naive Bayes model
 */
class DAAL_EXPORT Model : public classifier::Model
{
public:
    DECLARE_MODEL(Model, classifier::Model);

    /**
     * Empty constructor for deserialization
     * \DAAL_DEPRECATED_USE{ Model::create }
     */
    Model() {}

    /**
     * Constructs gaussian naive Bayes model
     * \param[in] nFeatures  The number of features
     * \param[in] parameter  The gaussian naive Bayes parameter
     * \param[in] dummy      Dummy variable for the templated constructor
     * \DAAL_DEPRECATED_USE{ Model::create }
     */
    template <typename modelFPType>
    DAAL_EXPORT Model(size_t nFeatures, const interface2::Parameter & parameter, modelFPType dummy);

    /**
     * Constructs gaussian naive Bayes model
     * \param[in] nFeatures  The number of features
     * \param[in] parameter  The gaussian naive Bayes parameter
     * \param[out] stat      Status of the model construction
     */
    template <typename modelFPType>
    DAAL_EXPORT static services::SharedPtr<Model> create(size_t nFeatures, const interface2::Parameter & parameter, services::Status * stat = NULL);
    /** \private */
    virtual ~Model() {}

protected:
    template <typename modelFPType>
    DAAL_EXPORT Model(size_t nFeatures, const interface2::Parameter & parameter, modelFPType dummy, services::Status & st);

    template <typename Archive, bool onDeserialize>
    services::Status serialImpl(Archive * arch)
    {
        services::Status st = classifier::Model::serialImpl<Archive, onDeserialize>(arch);
        if (!st) return st;
        //TODO: arch->setSharedPtrObj(_logP);
        //TODO: arch->setSharedPtrObj(_logTheta);
        //TODO: arch->setSharedPtrObj(_auxTable);

        return st;
    }
};

typedef services::SharedPtr<Model> ModelPtr;

} // namespace interface1
using interface2::Parameter;
using interface1::Model;
using interface1::ModelPtr;

} // namespace gaussian_naive_bayes
/** @} */
} // namespace algorithms
} // namespace daal
#endif
