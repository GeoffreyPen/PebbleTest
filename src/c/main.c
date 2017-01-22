#include <pebble.h>
#include "helloworld.h"




void init() {

show_helloworld();

}

void deinit() {
hide_helloworld();
}

int main() {
  init();
  app_event_loop();
  deinit();
}