#include "../unity/unity.h"
#include "../onlytesting/onlytesting.h"

void setUp()
{
   
}
void tearDown()
{
} 

void test_map(void) 
{ 
  TEST_ASSERT_EQUAL_FLOAT(100,fan_led_percent_map(252));
  TEST_ASSERT_EQUAL_FLOAT(75,fan_led_percent_map(189));
  TEST_ASSERT_EQUAL_FLOAT(50,fan_led_percent_map(126)); 
  TEST_ASSERT_EQUAL_FLOAT(25,fan_led_percent_map(63));
  TEST_ASSERT_EQUAL_FLOAT(0,fan_led_percent_map(0));
  
}




int main()
{
  UNITY_BEGIN();

  RUN_TEST(test_map);

  return UNITY_END();
}