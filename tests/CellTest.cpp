#include "CellTest.h"
#include "../Cell.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CellTest);

void CellTest::testConstructor() {
 
    char valid_sym[] ={'#', '+', '-', '.'};
    char digits[] = {'1', '2', '3', '4', '5','6','7','8', '9'};
    
    for(int i=0;i<4;i++){
        CPPUNIT_ASSERT_NO_THROW(Cell testCell(valid_sym[i]));
    }

    for(int i=0;i<9;i++){
        CPPUNIT_ASSERT_NO_THROW(Cell testCell(digits[i]));
    }
    
    bool exceptionThrown;
    char invalid_sym[] = {'$', '/', '*', '='};
    for(int i=0;i<4;i++){
        exceptionThrown = false;
        try {
            Cell testCell(invalid_sym[i]);
        }
        catch(std::runtime_error){
            exceptionThrown = true;
        }
    }
    if(!exceptionThrown){
        CPPUNIT_FAIL("No exception thrown for invalid symbol");
    }
    
    Cell obs_cell('#'),food_cell('5'), clear('.'), black_home('-'), red_home('+');
    CPPUNIT_ASSERT(obs_cell.has_obstruction()==true);
    CPPUNIT_ASSERT(food_cell.get_food() == 5);
    CPPUNIT_ASSERT(clear.has_obstruction()==false);
    CPPUNIT_ASSERT(black_home.is_black_home_area() == true);
    CPPUNIT_ASSERT(black_home.is_red_home_area() == false);
    CPPUNIT_ASSERT(red_home.is_red_home_area() == true);
    CPPUNIT_ASSERT(red_home.is_black_home_area() == false);
}

void CellTest::testGetters() {
    Cell obs_cell('#'), food_cell('7'), clear('.'), black_home('-'), red_home('+');
    CPPUNIT_ASSERT(obs_cell.has_obstruction()==true);
    CPPUNIT_ASSERT(food_cell.get_food() == 7);
    CPPUNIT_ASSERT(clear.has_obstruction()==false);
    CPPUNIT_ASSERT(black_home.is_black_home_area() == true);
    CPPUNIT_ASSERT(black_home.is_red_home_area() == false);
    CPPUNIT_ASSERT(red_home.is_red_home_area() == true);
    CPPUNIT_ASSERT(red_home.is_black_home_area() == false);
    
    tcolor col;
    col.val = 0;
    Bug testBug(col, 1, 10);
    clear.set_occupant(&testBug);
    CPPUNIT_ASSERT(clear.get_occupant()->get_progid() == testBug.get_progid());
}

void CellTest::testSetters(){
    Cell clear1('.'),clear2('.'),obs('#');
    
    tcolor col;
    col.val = 1;
    Bug testBug(col, 1, 10);
    clear1.set_occupant(&testBug);
    clear2.set_food(3);
    CPPUNIT_ASSERT(clear1.get_occupant()->get_progid() == testBug.get_progid());
    CPPUNIT_ASSERT(clear2.get_food() == 3);
    CPPUNIT_ASSERT_THROW(obs.set_occupant(&testBug), std::runtime_error);
    CPPUNIT_ASSERT_THROW(obs.set_food(5), std::runtime_error);
}

