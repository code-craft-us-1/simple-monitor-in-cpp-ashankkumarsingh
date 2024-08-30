#include "./monitor.h"
#include <assert.h>
#include <unistd.h>
#include <iostream>
using std::cout, std::flush;

int vitalsOk(float temperature, float pulseRate, float spo2) {
  if (temperature > 102 || temperature < 95) {
    cout << "Temperature is critical!\n";
    for (int i = 0; i < 6; i++) {
      cout << "\r* " << flush;
      sleep(1);
      cout << "\r *" << flush;
      sleep(1);
    }
    return 0;
  } else if (pulseRate < 60 || pulseRate > 100) {
    cout << "Pulse Rate is out of range!\n";
    for (int i = 0; i < 6; i++) {
      cout << "\r* " << flush;
      sleep(1);
      cout << "\r *" << flush;
      sleep(1);
    }
    return 0;
  } else if (spo2 < 90) {
    cout << "Oxygen Saturation out of range!\n";
    for (int i = 0; i < 6; i++) {
      cout << "\r* " << flush;
      sleep(1);
      cout << "\r *" << flush;
      sleep(1);
    }
    return 0;
  }
  return 1;
}