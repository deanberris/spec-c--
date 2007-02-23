// Copyright 2006, 2007 Dean Michael Berris.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt )

#include <boost/spec.hpp>
#include <vector>
#include <iostream>

int main (int argc, char * argv[]) {
    std::vector<int> v(1);
    v[0] = 1;
    boost::spec::container(v).should.contain(1);
    boost::spec::container(v).should.not_contain(0);
    boost::spec::container(v).should.not_be_empty();
    try {
        boost::spec::container(v).should.be_empty();
    } catch (std::exception & e) {
        std::cerr << "Expected: " << e.what() << '\n';
    };
    return EXIT_SUCCESS;
};
