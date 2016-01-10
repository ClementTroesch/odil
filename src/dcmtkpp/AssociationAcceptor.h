/*************************************************************************
 * odil - Copyright (C) Universite de Strasbourg
 * Distributed under the terms of the CeCILL-B license, as published by
 * the CEA-CNRS-INRIA. Refer to the LICENSE file or to
 * http://www.cecill.info/licences/Licence_CeCILL-B_V1-en.html
 * for details.
 ************************************************************************/

#ifndef _b21e4f11_9337_4612_8152_b59dedc16f18
#define _b21e4f11_9337_4612_8152_b59dedc16f18

#include <functional>
#include <string>

#include "odil/AssociationParameters.h"
#include "odil/Exception.h"

namespace odil
{

/**
 * @brief Callback to check whether the association request is acceptable.
 *
 * The callback shall return the parameters for the acceptation or throw an
 * AssociationRejected exception if the association is not acceptable.
 */
typedef
    std::function<AssociationParameters(AssociationParameters const &)>
    AssociationAcceptor;

/**
 * @brief Default association acceptor.
 *
 * Reverse the calling and called AE titles, accept the first transfer syntax
 * and the roles of each presentation context, do not check identity,
 * keep maximum length.
 */
AssociationParameters
default_association_acceptor(AssociationParameters const & input);

struct AssociationRejected: public Exception
{
public:
    AssociationRejected(
        unsigned char result, unsigned char source, unsigned char reason,
        std::string const & message="Association rejected");

    unsigned char get_result() const;
    void set_result(unsigned char value);

    unsigned char get_source() const;
    void set_source(unsigned char value);

    unsigned char get_reason() const;
    void set_reason(unsigned char value);
private:
    unsigned char _result;
    unsigned char _source;
    unsigned char _reason;
};

}

#endif // _b21e4f11_9337_4612_8152_b59dedc16f18
