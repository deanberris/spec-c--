// Copyright 2006, 2007 Dean Michael Berris.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt )

#include <boost/spec.hpp>
#include <vector>
#include <iostream>

using namespace boost::spec ;

int main (int argc, char * argv[]) {
    int v = 10;
    spec<int> variable = value(v);
    variable.should.equal(10);
    variable.should.not_equal(11);
    variable.should.be_less_than(11);
    variable.should.be_more_than(9);
    variable.should.be_between(5).and_(15);

    try {
        value(v).should.equal(11);
    } catch (std::exception & e) {
        std::cerr << e.what() << '\n';
    };

    try {
        value(v).should.not_equal(10);
    } catch (std::exception & e) {
        std::cerr << e.what() << '\n';
    };

    try {
        value(v).should.be_between(20).and_(25);
    } catch (std::exception & e) {
        std::cerr << e.what() << '\n';
    };

    try {
        value(v).should.be_between(0).and_(1);
    } catch (std::exception & e) {
        std::cerr << e.what() << '\n';
    };

    return 0;
};
