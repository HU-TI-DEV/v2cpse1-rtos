#include "hwlib.hpp"

void led1_update( hwlib::pin_out & led ){
   static long long int last_toggle = 0;
   static bool level = 0;
   auto t = hwlib::now_us();
   if( t - last_toggle > 50'000 ){
      level = ! level;
      led.set( level );
      last_toggle = t;
   }
}
 
void led2_update( hwlib::pin_out & led ){
   static long long int last_toggle = 0;
   static bool level = 0;
   auto t = hwlib::now_us();
   if( t - last_toggle > 165'000 ){
      level = ! level;
      led.set( level );
      last_toggle = t;
   }
}
 
int main(){	        
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
    
   namespace target = hwlib::target;       
   auto led1 = target::pin_out( target::pins::d42 );
   auto led2 = target::pin_out( target::pins::d44 );

   for(;;){
      led1_update( led1 );
      led2_update( led2 );
   }
}