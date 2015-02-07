#include "ets_sys.h"
#include "osapi.h"
#include "os_type.h"
#include "user_config.h"

#define user_procTaskPrio        0
#define user_procTaskQueueLen    1

os_event_t    user_procTaskQueue[user_procTaskQueueLen];
static void user_procTask(os_event_t *events);

//Hello world task
static void ICACHE_FLASH_ATTR
task_hello(os_event_t *events)
{
  //print text to the serial output
  os_printf("Hello World!\r\n");
}

//Init function
void ICACHE_FLASH_ATTR
user_init()
{
  // Initialize UART0
  uart_div_modify(0, UART_CLK_FREQ / 115200);

  //Set up the hello world task
  system_os_task(task_hello, user_procTaskPrio, user_procTaskQueue, user_procTaskQueueLen);
  //send a message to the "hello world" task to activate it
  system_os_post(user_procTaskPrio, 0, 0 );
}
