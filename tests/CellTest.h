#ifndef CELLTEST_H
#define CELLTEST_H

#include <cppunit/extensions/HelperMacros.h>

class CellTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(CellTest);

    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testGetters);
    CPPUNIT_TEST(testSetters);
    
    CPPUNIT_TEST_SUITE_END();

public:
    CellTest(){};
    virtual ~CellTest(){};
    void setUp(){};
    void tearDown(){};

private:
    void testConstructor();
    void testGetters();
    void testSetters();
};

#endif /* CELLTEST_H */

