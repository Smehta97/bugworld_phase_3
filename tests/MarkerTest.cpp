#include "MarkerTest.h"
#include "../Marker.h"

CPPUNIT_TEST_SUITE_REGISTRATION(MarkerTest);

void MarkerTest::testSetMarker() {
    Marker testMarker;
    tmark mark1, mark2, mark3, mark4;
    tcolor col1, col2, col3;
    mark1.val = 1;
    mark2.val = 3;
    mark3.val = -5;
    mark4.val = 5;
    col1.val = 0;
    col2.val = 1;
    col3.val = 2;
    
    CPPUNIT_ASSERT_NO_THROW(testMarker.set_marker(mark1,col1));
    CPPUNIT_ASSERT_NO_THROW(testMarker.set_marker(mark2, col2));
    CPPUNIT_ASSERT_THROW(testMarker.set_marker(mark1, col3), std::runtime_error);
    CPPUNIT_ASSERT_THROW(testMarker.set_marker(mark3, col2), std::runtime_error);
    CPPUNIT_ASSERT_THROW(testMarker.set_marker(mark4, col3), std::runtime_error);    
}

void MarkerTest::testCheckMarker() {
    Marker testMarker;
    tmark mark;
    tcolor col;
    
    mark.val = 2;
    col.val = 0;
    testMarker.set_marker(mark, col);
    
    CPPUNIT_ASSERT(testMarker.check_marker(mark, col) == true);
    mark.val = 4;
    col.val = 1;
    CPPUNIT_ASSERT(testMarker.check_marker(mark, col) == false);
}

void MarkerTest::testCheckOtherMarker(){
    Marker testMarker;
    tmark mark;
    tcolor col;
    
    mark.val = 3;
    col.val = 0;
    testMarker.set_marker(mark, col);
    
    CPPUNIT_ASSERT(testMarker.check_other_marker(col) == false);
    
    col.val = 1;
    
    CPPUNIT_ASSERT(testMarker.check_other_marker(col) == true);
}

void MarkerTest::testClearMarker(){
    Marker testMarker;
    tmark mark;
    tcolor col;
    mark.val = 3;
    col.val = 0;
    
    testMarker.set_marker(mark, col);
    testMarker.clear_marker(mark, col);
    CPPUNIT_ASSERT(testMarker.check_marker(mark,col) == false);
    CPPUNIT_ASSERT(testMarker.check_other_marker(col) == false);
}
