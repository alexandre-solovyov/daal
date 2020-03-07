/* file: naivebayes_model_fpt.cpp */
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
//  Implementation of class defining naive bayes algorithm model
//--
*/

#include "algorithms/naive_bayes/gaussian_naive_bayes_model.h"

namespace daal
{
namespace algorithms
{
namespace gaussian_naive_bayes
{

/**
 * Constructs gaussian naive Bayes model
 * \param[in] nFeatures  The number of features
 * \param[in] parameter  The gaussian naive Bayes parameter
 * \param[in] dummy      Dummy variable for the templated constructor
 * \DAAL_DEPRECATED_USE{ Model::create }
 */
template <typename modelFPType>
DAAL_EXPORT Model::Model(size_t nFeatures, const interface2::Parameter & parameter, modelFPType dummy)
{
    using namespace data_management;

    const interface2::Parameter * par = &parameter;
    if (par->nClasses < 2 || nFeatures == 0)
    {
        return;
    }
}

template <typename modelFPType>
DAAL_EXPORT Model::Model(size_t nFeatures, const interface2::Parameter & parameter, modelFPType dummy, services::Status & st)
{
    using namespace data_management;

    if (parameter.nClasses < 2)
    {
        st.add(services::ErrorIncorrectNumberOfClasses);
        return;
    }
    if (nFeatures == 0)
    {
        st.add(services::ErrorIncorrectNumberOfFeatures);
        return;
    }
}

/**
 * Constructs gaussian naive Bayes model
 * \param[in] nFeatures  The number of features
 * \param[in] parameter  The gaussian naive Bayes parameter
 * \param[out] stat      Status of the model construction
 */
template <typename modelFPType>
DAAL_EXPORT ModelPtr Model::create(size_t nFeatures, const interface2::Parameter & parameter, services::Status * stat)
{
    DAAL_DEFAULT_CREATE_IMPL_EX(Model, nFeatures, parameter, (modelFPType)0.0);
}

} // namespace gaussian_naive_bayes
} // namespace algorithms
} // namespace daal
