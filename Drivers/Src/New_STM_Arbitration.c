



#include "New_STM_Arbitration.h"


typedef enum {

	IO_A0 = (0 << 4) | 0,
	IO_A1 = (0 << 4) | 1,
	IO_A2 = (0 << 4) | 2,
	IO_A3 = (0 << 4) | 3,
	IO_A4 = (0 << 4) | 4,
	IO_A5 = (0 << 4) | 5,
	IO_A6 = (0 << 4) | 6,
	IO_B0 = (1 << 4) | 0,
	IO_B1 = (1 << 4) | 1,
	IO_B2 = (1 << 4) | 2,

} io_e;


static GPIO_typedef* const gpio_ports[IO_PORT_COUNT] = {
		GPIOA, GPIOB, GPIOC, GPIOD,GPIOE, GPIOF,GPIOG, GPIOH, GPIOI
};


inline static GPIO_TypeDef* io_get_gpio(io_e io){
	return gpio_ports[IO_PORT(io)];
}


void io_configure (io_e pin, const io_config_t* cfg){

	GPIO_Typedef* gpio = io_get_gpio(pin);
	uint8_t p = IO_PIN(pin);

	//Mode
	gpio->MODER &= ~ (0x3 << (2*p));
	gpio->MODER |= (cfg->mode << (2*p));

	//Output Type
	gpio-> OTYPER &= ~ (1<<p);
	gpio->OTYPER |= (cfg->Output_type <<p);

    // SPEED
    gpio->OSPEEDR &= ~(0x3 << (2 * p));
    gpio->OSPEEDR |=  (cfg->speed << (2 * p));

    // PULL-UP/DOWN
    gpio->PUPDR &= ~(0x3 << (2 * p));
    gpio->PUPDR |=  (cfg->pull << (2 * p));

    // ALTERNATE FUNCTION (if applicable)
    if (cfg->mode == GPIO_MODE_ALTFN) {
        uint8_t afr_index = p / 8;
        uint8_t afr_pos   = p % 8;
        gpio->AFR[afr_index] &= ~(0xF << (4 * afr_pos));
        gpio->AFR[afr_index] |=  (cfg->alt_func << (4 * afr_pos));
    }

}

static const struct {
    io_e pin;
    io_config_t config;
} io_initial_configs[] = {
    {
        IO_A5,
        {
            .mode = GPIO_MODE_OUT,
            .pull = GPIO_NO_PUPD,
            .output_type = GPIO_OP_TYPE_PP,
            .speed = GPIO_SPEED_FAST,
            .alt_func = 0
        }
    },
    {
        IO_C13,
        {
            .mode = GPIO_MODE_IN,
            .pull = GPIO_PIN_PU,
            .output_type = GPIO_OP_TYPE_PP,
            .speed = GPIO_SPEED_LOW,
            .alt_func = 0
        }
    }
};

void io_init(void){
	uint32_t count = (sizeof(io_initial_configs[])) / (sizeof(io_initial_configs[0]));

	for (uint32_t i=0; i < count; i++){
		io_configure (io_initial_configs[i].pin, &io_initial_configs[i].config);
	}
}

void io_write (io_e pin, uint8_t value){
	GPIO_TypeDef* gpio = io_get_gpio(pin);
	uint16_t mask = IO_PIN_MASK(PIN);

	if(value){
		gpio->ODR |= mask;
	}else{
		gpio->ODR &= ~mask;
	}
}

void io_toggle (io_e pin){
	GPIO_TypeDef* gpio = io_get_gpio(pin);
	gpio->ODR ^= IO_PIN_MASK(PIN);
}

void io_read (io_e pin){
	GPIO_TypeDef* gpio = io_get_gpio(pin);
	return (gpio->IDR & IO_PIN_MASK(pin)) ? 1 : 0;
}
