#include <iostream>

#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "pico/stdlib.h"

int main()
{
	stdio_init_all();
	constexpr int LED_PIN = 25;
	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);

	while(1)
	{
		gpio_put(LED_PIN, 0);
		sleep_ms(250);
		gpio_put(LED_PIN, 1);
		std::cout << "Hello Word\n";
		sleep_ms(1000);
	}
}