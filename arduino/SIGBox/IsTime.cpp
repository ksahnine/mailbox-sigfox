#include "IsTime.h"
bool IsTime(unsigned long& timeMark, unsigned long timeInterval) {
    if (millis() - timeMark >= timeInterval) {
        timeMark = millis();
        return true;
    }    
    return false;
}