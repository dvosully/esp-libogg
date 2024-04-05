#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_timer.h"
#include <stdint.h>
#include <inttypes.h>
#include <esp_random.h>
#include <math.h>
#include "string.h"

#include "ogg/ogg.h"

#define SAMPLERATE    (48000)
#define PACKETSIZE    (321)
static const char* TAG = "main";

void app_main(void) 
{
  ESP_LOGI(TAG, "Starting OGG");

  ogg_stream_state os;
  int err = ogg_stream_init(&os, esp_random());
  if (err)
  {
    ESP_LOGE(TAG, "Failed to init OGG stream");
    return;
  }
  ESP_LOGI(TAG, "OGG stream initialised successfully");

  ogg_packet op;
  op.packet = malloc(PACKETSIZE);
  op.bytes = PACKETSIZE;
  op.b_o_s = 1;
  op.e_o_s = 0;
  op.granulepos = 0;
  op.packetno = 0;

  ogg_page og;

  while(1)
    {
    esp_fill_random(op.packet, PACKETSIZE);

    err = ogg_stream_packetin(&os, &op);
    if(err)
      {
      ESP_LOGE(TAG, "Failed to add packet to OGG stream");
      return;
      }
    else
      {
      ESP_LOGI(TAG, "Successfully added packet to OGG stream");
      }
    err = ogg_stream_pageout(&os, &og);
    if(err)
      {
      ESP_LOGW(TAG, "A page has been completed and returned: %d byte header, %d byte body", (int)og.header_len, (int)og.body_len);
      }
    else
      {
      ESP_LOGI(TAG, "Not enough data to fill a page");
      }
    vTaskDelay(200);
    }
}
