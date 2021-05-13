#include"Unity/src/unity.h"
#include"Trains.h"
#include"RManager.h"
#include"ChekData.h"
#include"CheckCountElements.h"

void test(){
	Train*el = allocate();
	Train*el2 = allocate();
	Train*el3 = allocate();
	el2->next = el3;
	// el2 = deleteAt(el2, 1);
	// el2 = deleteAt(el2, 0);

	TEST_ASSERT_EQUAL_INT64(2, countOfElements(el2));
    
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
