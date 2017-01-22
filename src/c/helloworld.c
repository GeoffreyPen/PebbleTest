#include <pebble.h>
#include "helloworld.h"

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_gothic_28_bold;
static TextLayer *s_textlayer_1;
static bool s_js_ready;
static float latitude;
static float longitude;
static char stopwatch_miles[50];

static void inbox_received_callback(DictionaryIterator *iter, void *context) {
  // A new message has been successfully received
  text_layer_set_text(s_textlayer_1, "hello?");
}

static void request_location(){
    DictionaryIterator *iter;
  app_message_outbox_begin(&iter);

  if (!iter) {
    // Error creating outbound message
    return;
  }

  int value = 1;
  dict_write_int(iter, 1, &value, sizeof(int), true);
  dict_write_end(iter);

  app_message_outbox_send();
}

static void initialise_ui(void) {
  s_window = window_create();
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, true);
  #endif
  
  s_res_gothic_28_bold = fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD);
  // s_textlayer_1
  latitude=11.1f;
  //String str = String.valueOf(latitude);
  s_textlayer_1 = text_layer_create(GRect(1, 20, 142, 75));
  snprintf(stopwatch_miles, sizeof(stopwatch_miles), "  %d.%03d miles!", (int)latitude, (int)(latitude*1000)%1000);
  text_layer_set_text(s_textlayer_1,stopwatch_miles);

  text_layer_set_font(s_textlayer_1, s_res_gothic_28_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
  request_location();
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(s_textlayer_1);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_helloworld(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
  
}

void hide_helloworld(void) {
  window_stack_remove(s_window, true);
}
