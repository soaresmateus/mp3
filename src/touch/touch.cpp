#include <touch/touch.h>

Touch::Touch(int touchCs, int touchIrq, int touchRotation)
  : touch(touchCs, touchIrq) {
  touch.begin();
  touch.setRotation(touchRotation);
}

bool Touch::isTouched() {
  return touch.touched();
}

bool Touch::isThisAreaTouched(int xMin, int yMin, int xMax, int yMax, int zMin) {
  if (isTouched()) {
    TS_Point p = touch.getPoint();
    if (p.z > zMin && p.x >= xMin && p.x <= xMax && p.y >= yMin && p.y <= yMax) {
      return true;
    }
  }
  return false;
}