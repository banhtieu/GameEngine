
#include "TouchScreeniPhone.h"


void TouchScreeniPhone::touchBegan(float x, float y, double timestamp, int tapCount, float oldX, float oldY, long id)
{
    TouchScreenBase::touchBegan(TouchPoint((TouchType)x, (TouchType)y), (TouchID)0);
}