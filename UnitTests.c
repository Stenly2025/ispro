#include"Unity/src/unity.h"
#include"Trains.h"
#include"RManager.h"
#include"ChekData.h"
#include"CheckSize.h"
#include"CheckCountElements.h"

void test(){
	Train*el = allocate();
	Train*el2 = allocate();
	Train*el3 = allocate();
	el2->next = el3;
	el2 = indexed(el2);

	TEST_ASSERT_EQUAL_INT(0, count(NULL));
	TEST_ASSERT_EQUAL_INT64(1, count(el));
	TEST_ASSERT_EQUAL_INT64(2, count(el2));	
	TEST_ASSERT_EQUAL_INT64(0,el2->index);
	el3=goToEnd(el2);
	TEST_ASSERT_EQUAL_INT64(1,el3->index);
	el2 = deleteAt(el2, 1);
	TEST_ASSERT_EQUAL_INT64(1, count(el2));
	el2 = deleteAt(el2, 0);
	TEST_ASSERT_EQUAL_INT64(0, count(el2));

	Train*el4 = allocate();
	el2 = add(el2,el4);
	Train*el5 = allocate();
	el2 = add(el2,el5);
	TEST_ASSERT_EQUAL_INT64(2, count(el2));
	Train*el6 = NULL;
	Train*el7 = allocate();	
	el6 = add(el6, el7);
	TEST_ASSERT_EQUAL_INT64(0, el6->index);
	TEST_ASSERT_EQUAL_INT64(1, count(el6));
	TEST_ASSERT_EQUAL_INT64(4, sizeOfString("Good\0"));
	TEST_ASSERT_EQUAL_INT64(4, sizeOfString("Good"));
	TEST_ASSERT_EQUAL_INT64(0, sizeOfString("\0"));
	TEST_ASSERT_EQUAL_INT64(0, sizeOfString(""));

}

void setUp(){

}

void tearDown(){
	
}

int main(){	
	UNITY_BEGIN();
	RUN_TEST(test);
	return UNITY_END();
}
