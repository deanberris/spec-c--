.. Copyright 2007 (C) Dean Michael Berris <dean@orangeandbronze.com>
.. Copyright 2008-2009 (C) Dean Michael Berris <me@deanberris.com>
.. Distributed under the Boost Software License, Version 1.0.
.. (See accompanying file LICENSE_1_0.txt or copy at
.. http://boost.org/LICENSE_1_0.txt)

=====================================
Behavior Driven Development Interface
=====================================
--------------------
The Spec C++ Library
--------------------

The Spec C++ Library implements a Behavior Driven Development [0]_ (BDD)
Interface for specifying behavior of a program. The interface allows an 
alternative to the traditional Unit Testing interface of assertions to 
test the behavior of modules/units/components.

Below is shown the example of how the Spec library can be used in your test
suites:

::

    #include <boost/spec.hpp>
    #include <iostream>

    int main(int argc, char * argv[]) {
        using namespace boost::spec ;
        using namespace std;

        int an_int = 0;
        cout << "Please enter an integer: " << endl;
        cin >> an_int;
        try {
            value(an_int).should.be_greater_than(0);
            value(an_int).should.be_less_than(99);
            value(an_int).should.be_between(0).and_(99);
            value(an_int).should.equal(50);
        } catch (std::exception & e) {
            cerr << "Caught: " << e.what() << '\n';
        };
        return 0;
    };

Depending on what the user enters, the exception that is thrown by the
specifications will be displayed. Should the user enter ``50`` there will
be no exception thrown.

The library is developed to be part of the `Boost C++ Library`_.

----------
Features
----------

The following list shows the features that the Spec library implements.

- Integral Type specification of expected values

  - ``value(some_int).should.equal(0)``
  - ``value(some_int).should.be_greater_than(0)``
  - ``value(some_int).should.be_less_than(0)``
  - ``value(some_int).should.not_equal(0)``
  - ``value(some_int).should.be_between(0).and_(1)``
  - ``value(some_int).should.be_even()``
  - ``value(some_int).should.be_odd()``
  - ``value(some_int).should.be_divisible_by(5)``
  - ``value(some_int).should.not_be_divisible_by(9)``

- String value specification of expected values

  - ``value(some_string).should.equal("Some String Literal")``
  - ``value(some_string).should.not_equal("Some other string Literal")``

- Bool value specification

  - ``value(some_bool).should.be_true()``
  - ``value(some_bool).should.be_false()``

- Container inspection

  - ``container(some_container).should.contain(value)``
  - ``container(some_container).should.not_contain(value)``
  - ``container(some_container).should.not_be_empty()``
  - ``container(some_container).should.have_size(value)``

----------
References
----------

.. _`Boost C++ Library`: http://boost.org/

.. [0] Behavior Driven Development: http://behaviour-driven.org/

---------------

| Copyright (C) 2007 Dean Michael Berris <dean@orangeandbronze.com> 
| Copyright (C) 2009 Dean Michael Berris <me@deanberris.com>
| Distributed under the Boost Software License, Version 1.0. (See accompanying file `LICENSE_1_0.txt` or copy at http://boost.org/LICENSE_1_0.txt)

