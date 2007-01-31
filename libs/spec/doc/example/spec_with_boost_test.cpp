// Copyright 2006, 2007 Dean Michael Berris.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt )

// This test uses BDD along with Boost.Test

#define BOOST_AUTO_TEST_MAIN
#include <boost/test/auto_unit_test.hpp>
#include <boost/spec.hpp>

using namespace boost::spec ;

BOOST_AUTO_TEST_CASE ( spec_bool_test ) {
    value(true).should.be_true();
    value(false).should.be_false();
    BOOST_REQUIRE_THROW ( value(true).should.be_false() , std::exception );
};
